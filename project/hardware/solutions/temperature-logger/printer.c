#include <stdio.h>
#include <string.h>
#include "printer.h"
void print_startup_message()
{
    clear_screen();
    printf("Todo application\n");
    printf("====================\n");
    printf("Commands:\n");
    printf(" h      Show the command list\n");
    printf(" l      List available ports\n");
    printf(" p      Set port name\n");
    printf(" w      Set write filename\n");
    printf(" o      Open port\n");
    printf(" s      Start logging / Stop logging\n");
    printf(" c      Close port\n");
    printf(" r      Set read filename\n");
    printf(" a      Calculate average in given period\n");
}

void clear_screen()
{
    system("cls");
}
