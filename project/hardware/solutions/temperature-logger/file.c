#include <stdio.h>
#include "file.h"
#include "printer.h"

int get_write_file_name()
{
    clear_screen();
    printf("Please enter the name of the file which will be used to log data into it!\n");
    fgets(write_file_name, MAX_FILENAME_LEN - 1, stdin);

    // Remove \r and \n characters
    for (int i = 0; i < MAX_FILENAME_LEN; i++) {
        if (write_file_name[i] == '\r' || write_file_name[i] == '\n')
            write_file_name[i] = '\0';
    }

    // Try to open the file
    FILE *f = fopen(write_file_name, "a");
    if (f == NULL) {
        printf("%s can not be opened.\n", write_file_name);
        write_file_name[0] = '\0';
        return -1;
    } else {
        printf("%s saved.\n", write_file_name);
        fclose(f);
        return 0;
    }
}


