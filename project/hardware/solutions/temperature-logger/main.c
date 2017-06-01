#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "rs232/rs232.h"
#include "printer.h"
#include "parser.h"
#include "file.h"

int main()
{
    comEnumerate();
    print_startup_message();

    while (1)
    {
        char key = getch();
        switch (key)
        {
        case 'h':
            print_startup_message();
            break;
        case 'l':
            print_port_list();
            break;
        case 'p':
            get_port_name();
            break;
        case 'w':
            get_write_file_name();
            break;
        default:
            break;
        }

        // Exit
        if (key == 'e')
        {
            break;
        }
    }

    comCloseAll();
    comTerminate();
    return 0;
}
