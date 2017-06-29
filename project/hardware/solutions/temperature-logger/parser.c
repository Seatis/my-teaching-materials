#include <stdio.h>
#include <time.h>
#include "rs232/rs232.h"
#include "parser.h"
#include "printer.h"
#include "string.h"
#include "file.h"

int parser_port = -1;


int get_port_name()
{
	clear_screen();
	printf("Please enter the name of the serial port you want to use!\n");
	char port_name[PORT_NAME_MAX_LEN];
	fgets(port_name, PORT_NAME_MAX_LEN - 1, stdin);

	// Remove \r and \n characters
	for (int i = 0; i < PORT_NAME_MAX_LEN; i++) {
		if (port_name[i] == '\r' || port_name[i] == '\n')
			port_name[i] = '\0';
	}

	// Find the index of that port
	parser_port = comFindPort(port_name);

	if (parser_port < 0) {
		printf("%s not exists!\n", port_name);
		return -1;
	} else {
		printf("%s port exists, saved.\n", port_name);
	}

	return 0;
}

int open_port()
{
	clear_screen();
	if (parser_port < 0) {
		printf("Port not set!\n");
		return -1;
	}

	close_port(parser_port);
	if (!comOpen(parser_port, BAUD_RATE)) {
		printf("Port can not be opened. Try to set the port again!\n");
		return -1;
	} else {
		printf("Port opened successfully!\n");
		return 0;
	}
}

int close_port()
{
	clear_screen();
	if (parser_port < 0) {
		printf("Port not set!\n");
		return -1;
	}

	comClose(parser_port);
	printf("Port closed.\n");
	return 0;
}


int get_line_from_port(char *buff, int buff_len)
{
	if (parser_port < 0) {
		printf("Port not set!\n");
		return -1;
	}

	// Put data into the
	char ch;
	int i = 0;
	int bytes = comRead(parser_port, &ch, 1);
	// If there is no data on the port, exit
	if (bytes <= 0) {
		return 0;
	}
	// This loop will read until a \n character. If the buffer is too small, then
	// the characters will be discarded after the size limit is reached.
	while (ch != '\n') {
		// Check if there is enough space in the buffer
		if (i < (buff_len - 1)) {
			// Check if we are not near the end of the line (cr character)
			if (ch != '\r') {
				buff[i] = ch;
				i++;
			}
		}
		while (comRead(parser_port, &ch, 1) == 0);
	}
	// Put terminating zero at the end
	buff[i] = '\0';

	return i;
}

int log_data()
{
	// Check if port set up properly
	if (parser_port < 0) {
		printf("Port not set!\n");
		return -1;
	}

	// Get a line of data from the port
	// If there is no data on the port, then do nothing
	char buff[PORT_BUFFER_LEN];
	if (get_line_from_port(buff, PORT_BUFFER_LEN) > 0) {
		// Put the data into the logfile
		write_data_to_file(buff);
	}

	return 0;
}

time_t get_date_from_user()
{
	struct tm date;
	int year, month, day, hour, min, sec;
	fflush(stdin);
	int input_count = scanf("%d-%d-%d %d:%d:%d",
							&year,
							&month,
							&day,
							&hour,
							&min,
							&sec);
	if (input_count != 6)
		return -1;

	time_t raw_time = time(NULL);
	date = *localtime(&raw_time);
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	date.tm_hour = hour;
	date.tm_min = min;
	date.tm_sec = sec;

	return mktime(&date);
}

int get_average()
{
	printf("Enter period start date (YYYY-MM-DD HH-mm-SS): \t");
	time_t start = get_date_from_user();
	if (start < 0) {
		printf("The entered date is invalid.\n");
		return -1;
	}

	printf("Enter period end date (YYYY-MM-DD HH-mm-SS): \t");
	time_t end = get_date_from_user();
	if (end < 0) {
		printf("The entered date is invalid.\n");
		return -1;
	}

	float avg = get_average_from_file(start, end);
	printf("%f\n", avg);
	return 0;
}
