#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "rs232/rs232.h"
#include "printer.h"

int main()
{
    print_startup_message();

    while (1)
    {
        char key = getch();
        switch (key)
        {
        case 'h':
            print_startup_message();
            break;
        case 'h':
            print_startup_message();
            break;
        }

        // Exit
        if (key == 'e')
        {
            break;
        }
    }

    return 0;
}
