#include <stdio.h>
#include <time.h>
#include "file.h"
#include "printer.h"

int get_file_name(char *file_name)
{
	fgets(file_name, MAX_FILENAME_LEN - 1, stdin);

	// Remove \r and \n characters
	for (int i = 0; i < MAX_FILENAME_LEN; i++) {
		if (file_name[i] == '\r' || file_name[i] == '\n')
			file_name[i] = '\0';
	}

	// Try to open the file
	FILE *f = fopen(file_name, "a");
	if (f == NULL) {
		printf("File \"%s\" can not be opened.\n", file_name);
		file_name[0] = '\0';
		return -1;
	} else {
		printf("File name \"%s\" saved.\n", file_name);
		fclose(f);
		return 0;
	}
}

int get_write_file_name()
{
	clear_screen();
	printf("Please enter the name of the file which will be used to log data into it!\n");
	return get_file_name(write_file_name);
}

int get_read_file_name()
{
	clear_screen();
	printf("Please enter the name of the file which will be used to read data from it!\n");
	return get_file_name(read_file_name);
}

int write_data_to_file(char *data)
{
	// Try to open file
	FILE *f = fopen(write_file_name, "a");
	if (f == NULL) {
		printf("%s can not be opened.\n", write_file_name);
		write_file_name[0] = '\0';
		return -1;
	}

	// Get timestamp
	time_t raw_time;
	struct tm *timeinfo;
	char buffer[STRFTIME_BUFF_LEN];
	time (&raw_time);
	timeinfo = localtime (&raw_time);
	strftime (buffer, STRFTIME_BUFF_LEN, "%Y-%m-%d %H:%M:%S", timeinfo);

	// Write data to file
	fprintf(f, "%s\t%s\n", buffer, data);

	// Close file
	fclose(f);
	return 0;
}

int get_temp_from_file(time_t start, time_t end, float *temp, FILE *f)
{
	struct tm date;
	int year, month, day, hour, min, sec;
	int item_count = fscanf(f,
							"%d-%d-%d %d:%d:%d\t%f\r\n",
							&year,
							&month,
							&day,
							&hour,
							&min,
							&sec,
							temp);

	if (item_count != 7)
		return -10;

	time_t raw_time = time(NULL);
	date = *localtime(&raw_time);
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	date.tm_hour = hour;
	date.tm_min = min;
	date.tm_sec = sec;

	raw_time = mktime(&date);
	// If raw_time is after end
	if (difftime(raw_time, end) > 0)
		return -1;
	// If raw_time is before start
	else if (difftime(start, raw_time) > 0)
		return 1;
	// If raw_time is between start and end
	else
		return 0;
}

float get_average_from_file(time_t start, time_t end)
{
	// Try to open file
	FILE *f = fopen(read_file_name, "r");
	if (f == NULL) {
		printf("%s can not be opened.\n", write_file_name);
		write_file_name[0] = '\0';
		return -10000;
	}

	float sum = 0;
	int count = 0;
	float temp;
	int retval = get_temp_from_file(start, end, &temp, f);
	while (retval >= 0) {
		if (retval == 0) {
			sum += temp;
			count++;
		}
		retval = get_temp_from_file(start, end, &temp, f);
	}
	fclose(f);
	return (sum / count);
}

