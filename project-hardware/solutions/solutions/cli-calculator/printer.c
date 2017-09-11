#include "printer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

act_line_pos = 0;

#ifdef WINDOWS
COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
#endif // WINDOWS

#ifndef WINDOWS
void gotoxy(int x,int y)
{
    printf("\033[%d;%dH", y+1, x+1);
}
#endif // WINDOWS

void set_prompt_pos(char *command)
{
    int pos = strlen(command);
    gotoxy(pos, act_line_pos);
    act_line_pos++;
}

void print_usage()
{
    clear_screen();
    printf("========================================|\n");
    printf("\tCLI Calculator\t\t\t|\n" );
    printf("========================================|\n");
    printf("usage: [number] [operation] [number]\t|\n");
    printf("example: 5 + 6\t\t\t\t|\n");
    printf("========================================|\n");
    printf("Commands:\t\t\t\t|\n");
    printf("+\tsummation\t\t\t|\n");
    printf("-\tsubtraction\t\t\t|\n");
    printf("*\tmultiplication\t\t\t|\n");
    printf("/\tdivision\t\t\t|\n");
    printf("%%\tdivision with remainder\t\t|\n");
    printf("^\tsquaring\t\t\t|\n");
    printf("<\tsquare root\t\t\t|\n");
    printf("log\tlogarithm\t\t\t|\n");
    printf("binto\tbinary to hex or dec\t\t|\n");
    printf("hexto\thexadecimal to bin or dec\t|\n");
    printf("decto\tdecimal to bin or hex\t\t|\n");
    printf("========================================|\n");
    printf("exit\texiting from the program\t|\n");
    printf("clear\tclear the screen\t\t|\n");
    printf("help\tprint usage\t\t\t|\n");
    printf("========================================|\n");
    printf("Hit enter to start!\t\t\t|\n");
    printf("========================================|\n");


    getchar();
    clear_screen();
}

void print_result(float result)
{
    printf(" = %f\n", result);
}

void print_result_int(int result)
{
    printf(" = %d\n", result);
}
