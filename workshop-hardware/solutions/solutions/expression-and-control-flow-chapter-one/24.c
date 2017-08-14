#include <stdio.h>
#include <stdlib.h>

/*
Create a program which converts days to years ,weeks and days
to keep it simple we say every year is 365 days long, every month is 30 days
*/

int main()
{
    int days = 4582;
    int years = 0;
    int weeks = 0;

    years = days/365;
    weeks = (days % 365)/7;
    days = days- ((years*365) + (weeks*7));

    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d \n", days);

    return 0;
}
