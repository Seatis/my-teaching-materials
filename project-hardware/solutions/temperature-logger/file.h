#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include <time.h>

#define MAX_FILENAME_LEN    1024
#define STRFTIME_BUFF_LEN   100
#define READ_BUFFER_LEN     1024

char write_file_name[MAX_FILENAME_LEN];
char read_file_name[MAX_FILENAME_LEN];

int get_write_file_name();
int get_read_file_name();
int write_data_to_file(char *data);
float get_average_from_file(time_t start, time_t end);

#endif // FILE_H_INCLUDED
