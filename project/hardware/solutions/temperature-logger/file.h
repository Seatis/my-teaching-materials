#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#define MAX_FILENAME_LEN    1024
#define STRFTIME_BUFF_LEN   100

char write_file_name[MAX_FILENAME_LEN];
char read_file_name[MAX_FILENAME_LEN];

int get_write_file_name();
int write_data_to_file(char *data);

#endif // FILE_H_INCLUDED
