#include "operations.h"
#include "printer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define WINDOWS

#ifdef WINDOWS
#include <Windows.h>
void clear_screen()
{
    system ("cls");
}
#endif // WINDOWS

#ifndef WINDOWS
void clear_screen()
{
    system ("clear");
}

char* itoa(int value, char* str, int radix) {
    static char dig[] =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz";
    int n = 0, neg = 0;
    unsigned int v;
    char* p, *q;
    char c;
    if (radix == 10 && value < 0) {
        value = -value;
        neg = 1;
    }
    v = value;
    do {
        str[n++] = dig[v%radix];
        v /= radix;
    } while (v);
    if (neg)
        str[n++] = '-';
    str[n] = '\0';
    for (p = str, q = p + n/2; p != q; ++p, --q)
        c = *p, *p = *q, *q = c;
    return str;
}
#endif // WINDOWS

const char OPERATION_ADD[] = " + ";
const char OPERATION_SUB[] = " - ";
const char OPERATION_MUL[] = " * ";
const char OPERATION_DIV[] = " / ";
const char OPERATION_MOD[] = " % ";
const char OPERATION_POW[] = " ^ ";
const char OPERATION_ROOT[] = " < ";
const char OPERATION_LOG[] = " log ";
const char OPERATION_B2[] = " binto ";
const char OPERATION_H2[] = " hexto ";
const char OPERATION_D2[] = " decto ";

char check_operands(char *firstoperand, char *secondoperand);

int main()
{
    char *firstoperand, *secondoperand;

    print_usage();
    char command[100];
    while(1) {
        //fgets(command, 100, stdin);
        gets(command);

        if (strstr(command, OPERATION_ADD)) {

            set_prompt_pos(command);

            firstoperand = strtok(command, OPERATION_ADD);
            secondoperand = strtok(NULL, OPERATION_ADD);

            if (check_operands(firstoperand, secondoperand)) {
                printf(" = Invalid operands.\n");
            } else {
                float result = add(atof(firstoperand), atof(secondoperand));
                print_result(result);
            }

        } else if (strstr(command, OPERATION_SUB)) {
            set_prompt_pos(command);

            firstoperand = strtok(command, OPERATION_SUB);
            secondoperand = strtok(NULL, OPERATION_SUB);

            if (check_operands(firstoperand, secondoperand)) {
                printf(" = Invalid operands.\n");
            } else {
                float result = sub(atof(firstoperand), atof(secondoperand));
                print_result(result);
            }

        } else if (strstr(command, OPERATION_MUL)) {
            set_prompt_pos(command);

            firstoperand = strtok(command, OPERATION_MUL);
            secondoperand = strtok(NULL, OPERATION_MUL);

            if (check_operands(firstoperand, secondoperand)) {
                printf(" = Invalid operands.\n");
            } else {
                float result = mul(atof(firstoperand), atof(secondoperand));
                print_result(result);
            }

        } else if (strstr(command, OPERATION_DIV)) {
            set_prompt_pos(command);

            firstoperand = strtok(command, OPERATION_DIV);
            secondoperand = strtok(NULL, OPERATION_DIV);

            if (check_operands(firstoperand, secondoperand)) {
                printf(" = Invalid operands.\n");
            } else if (atof(secondoperand)==0.0) {
                printf(" = Division by zero is undefined.\n");
            } else {
                float result = divide(atof(firstoperand), atof(secondoperand));
                print_result(result);
            }

        } else if (strstr(command, OPERATION_MOD)) {
            set_prompt_pos(command);

            firstoperand = strtok(command, OPERATION_MOD);
            secondoperand = strtok(NULL, OPERATION_MOD);

            if (check_operands(firstoperand, secondoperand)) {
                printf(" = Invalid operands.\n");
            } else {
                int result = mod(atoi(firstoperand), atoi(secondoperand));
                print_result_int(result);
            }

        } else if (strstr(command, OPERATION_POW)) {
            set_prompt_pos(command);

            firstoperand = strtok(command, OPERATION_POW);
            secondoperand = strtok(NULL, OPERATION_POW);

            float result = power(atof(firstoperand), atof(secondoperand));
            print_result(result);

        } else if (strstr(command, OPERATION_ROOT)) {
            set_prompt_pos(command);

            firstoperand = strtok(command, OPERATION_ROOT);
            secondoperand = strtok(NULL, OPERATION_ROOT);

            if (check_operands(firstoperand, secondoperand)) {
                printf(" = Invalid operands.\n");
            } else if (atoi(firstoperand)!=2) {
                printf(" = First operand must be 2.\n");
            } else if (atoi(secondoperand)<0) {
                printf(" = Negative operand is invalid.");
            }
            else {
                float result = sqrt(atof(secondoperand));

                print_result(result);
            }

        } else if (strstr(command, OPERATION_LOG)) {
            set_prompt_pos(command);

            firstoperand = strtok(command, OPERATION_LOG);
            secondoperand = strtok(NULL, OPERATION_LOG);

            float result = logarithm(atof(firstoperand), atof(secondoperand));

            print_result(result);

        } else if (strstr(command, OPERATION_B2)) {
            set_prompt_pos(command);

            char buffer[32];
            firstoperand = strtok(command, OPERATION_B2);
            secondoperand = strtok(NULL, OPERATION_B2);
            long bin_num = strtol(firstoperand, NULL, 2);

            if ((strcmp(secondoperand,"10") == 0)) {
                itoa(bin_num, buffer, atoi(secondoperand));
            } else if ((strcmp(secondoperand,"16") == 0)) {
                itoa(bin_num, buffer, atoi(secondoperand));
            }
            printf(" = %s\n", buffer);

        } else if (strstr(command, OPERATION_H2)) {
            set_prompt_pos(command);

            char buffer[32];
            firstoperand = strtok(command, OPERATION_H2);
            secondoperand = strtok(NULL, OPERATION_H2);
            long hex_num = strtol(firstoperand, NULL, 16);

            if ((strcmp(secondoperand,"2") == 0)) {
                itoa(hex_num, buffer, atoi(secondoperand));
            } else if ((strcmp(secondoperand,"10") == 0)) {
                itoa(hex_num, buffer, atoi(secondoperand));
            }
            printf(" = %s\n", buffer);

        } else if (strstr(command, OPERATION_D2)) {
            set_prompt_pos(command);

            char buffer[32];
            firstoperand = strtok(command, OPERATION_D2);
            secondoperand = strtok(NULL, OPERATION_D2);
            if ((strcmp(secondoperand,"2") == 0)) {
                itoa(atoi(firstoperand), buffer, atoi(secondoperand));
            } else if ((strcmp(secondoperand,"16") == 0)) {
                itoa(atoi(firstoperand), buffer, atoi(secondoperand));
            }
            printf(" = %s\n", buffer);

        } else if (strstr(command, "clear")) {
            clear_screen();
            act_line_pos = 0;
        } else if (strstr(command, "exit")){
            break;
        } else if (strstr(command, "help")) {
            print_usage();
            act_line_pos = 0;
        } else {
            printf("Invalid command\n");
            printf("Hit enter to continue.\n");
            getchar();
            clear_screen();
            act_line_pos = 0;
        }
    }
    return 0;
}

char check_operands(char *firstoperand, char *secondoperand)
{
    int not_num=0;
    int i;
    for (i=0; i<strlen(firstoperand); i++) {
        if (!isdigit(firstoperand[i]) && !ispunct(firstoperand[i])) {
            not_num++;
        }
    }
    for (i=0; i<strlen(secondoperand); i++) {
        if (!isdigit(secondoperand[i]) && !ispunct(secondoperand[i])) {
            not_num++;
        }
    }
    if (not_num>0) {
        return 1;
    }
    else {
        return 0;
    }
}
