#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "rs232/rs232.h"
#include "printer.h"

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
