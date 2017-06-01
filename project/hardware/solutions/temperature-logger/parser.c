#include <stdio.h>
#include "rs232/rs232.h"
#include "parser.h"
#include "printer.h"

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

    if (!comOpen(parser_port, BAUD_RATE)) {
        printf("Port can not be opened. Try to set the port again!\n");
        return -1;
    } else {
        printf("Port opened successfully!\n");
        return 0;
    }
}
