#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED

int act_line_pos;

void gotoxy(int x,int y);
void set_prompt_pos(char *command);
void print_usage();
void print_result(float result);
void print_result_int(int result);

#endif // PRINTER_H_INCLUDED
