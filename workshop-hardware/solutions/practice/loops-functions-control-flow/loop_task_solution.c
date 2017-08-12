#include <stdio.h>
#include <string.h>

/*
Create a program which writes down the following sentence 100 times:
"I won't cheat on the test!"
Do it with:
    - for loop
    - while loop
    - do while loop
Also create a funtion which does the same.
*/

void i_wont_cheat_for_loop();
void i_wont_cheat_while_loop();
void i_wont_cheat_do_while_loop();

int main()
{
	i_wont_cheat_for_loop();
	i_wont_cheat_while_loop();
	i_wont_cheat_do_while_loop();

	return 0;
}

void i_wont_cheat_for_loop()
{
	for (int i = 1; i < 101; i++)
		printf("\n%d: I won't cheat on the test!\n", i);
}

void i_wont_cheat_while_loop()
{
	int count = 1;
	while (count < 101) {
		printf("\n%d: I won't cheat on the test!\n", count);
		count++;
	}
}

void i_wont_cheat_do_while_loop()
{
	int i = 100;
	int j = 1;
	do {
		printf("%d: I won't cheat on the test!\n", j );
		i = i - 1;
		j++;
	} while ( i > 0 );

}
