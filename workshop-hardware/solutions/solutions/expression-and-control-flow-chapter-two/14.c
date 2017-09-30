#include <stdio.h>
#include <stdlib.h>

/*
Create a program which can tell how to pay an exact amount of money
for example 45670 Ft, is the amount (store this as an integer)
and the output should be:
2-20000Ft
1-5000Ft
1-500Ft
1-100Ft
1-50Ft
1-20Ft
*/

/*
Take care of the rounding (when giving back 5 coins):
1, 2 - 0 down
3, 4 - 5 up
6, 7 - 5 down
8, 9 - 0 up
*/

int main()
{
    int amount_of_money = 57545;

    int twenty_thousand = 20000;
    int ten_thousand = 10000;
    int five_thousand = 5000;
    int two_thousand = 2000;
    int one_thousand = 1000;
    int five_hundred = 500;
    int two_hundred = 200;
    int one_hundred = 100;
    int fifty = 50;
    int twenty = 20;
    int ten = 10;
    int five = 5;

    int number_of_20000_banknote, number_of_10000_banknote, number_of_5000_banknote, number_of_2000_banknote, number_of_1000_banknote, number_of_500_banknote, number_of_200_banknote, number_of_100_banknote, number_of_50_banknote, number_of_20_banknote, number_of_10_banknote, number_of_5_banknote;

    int pieces;

    //20000
    pieces = amount_of_money/twenty_thousand;
    if (pieces == 0) {
        number_of_20000_banknote = 0;
    } else {
        number_of_20000_banknote = pieces;
        amount_of_money = amount_of_money-number_of_20000_banknote*twenty_thousand;
    }
    printf("%d-%d\n", twenty_thousand, pieces);

    //10000
    pieces = amount_of_money/ten_thousand;
    if (pieces == 0) {
        number_of_10000_banknote = 0;
    } else {
        number_of_10000_banknote = pieces;
        amount_of_money = amount_of_money-number_of_10000_banknote*ten_thousand;
    }
    printf("%d-%d\n", ten_thousand, pieces);

    //5000
    pieces = amount_of_money/five_thousand;
    if (pieces == 0) {
        number_of_5000_banknote = 0;
    } else {
        number_of_5000_banknote = pieces;
        amount_of_money = amount_of_money-number_of_5000_banknote*five_thousand;
    }
    printf("%d-%d\n", five_thousand, pieces);

    //2000
    pieces = amount_of_money/two_thousand;
    if (pieces == 0) {
        number_of_2000_banknote = 0;
    } else {
        number_of_2000_banknote = pieces;
        amount_of_money = amount_of_money-number_of_2000_banknote*two_thousand;
    }
    printf("%d-%d\n", two_thousand, pieces);

    //1000
    pieces = amount_of_money/one_thousand;
    if (pieces == 0) {
        number_of_1000_banknote = 0;
    } else {
        number_of_1000_banknote = pieces;
        amount_of_money = amount_of_money-number_of_1000_banknote*one_thousand;
    }
    printf("%d-%d\n", one_thousand, pieces);

    //500
    pieces = amount_of_money/five_hundred;
    if (pieces == 0) {
        number_of_500_banknote = 0;
    } else {
        number_of_500_banknote = pieces;
        amount_of_money = amount_of_money-number_of_500_banknote*five_hundred;
    }
    printf("%d-%d\n", five_hundred, pieces);

    //200
    pieces = amount_of_money/two_hundred;
    if (pieces == 0) {
        number_of_200_banknote = 0;
    } else {
        number_of_200_banknote = pieces;
        amount_of_money = amount_of_money-number_of_200_banknote*two_hundred;
    }
    printf("%d-%d\n", two_hundred, pieces);

    //100
    pieces = amount_of_money/one_hundred;
    if (pieces == 0) {
        number_of_100_banknote = 0;
    } else {
        number_of_100_banknote = pieces;
        amount_of_money = amount_of_money-number_of_100_banknote*one_hundred;
    }
    printf("%d-%d\n", one_hundred, pieces);

    //50
    pieces = amount_of_money/fifty;
    if (pieces == 0) {
        number_of_50_banknote = 0;
    } else {
        number_of_50_banknote = pieces;
        amount_of_money = amount_of_money-number_of_50_banknote*fifty;
    }
    printf("%d-%d\n", fifty, pieces);

    //20
    pieces = amount_of_money/twenty;
    if (pieces == 0) {
        number_of_20_banknote = 0;
    } else {
        number_of_20_banknote = pieces;
        amount_of_money = amount_of_money-number_of_20_banknote*twenty;
    }
    printf("%d-%d\n", twenty, pieces);

    //10
    pieces = amount_of_money/ten;
    if (pieces == 0) {
        number_of_10_banknote = 0;
    } else {
        number_of_10_banknote = pieces;
        amount_of_money = amount_of_money-number_of_10_banknote*ten;
    }
    printf("%d-%d\n", ten, pieces);

    //5
    pieces = amount_of_money/five;
    if (pieces == 0) {
        number_of_5_banknote = 0;
        if ((amount_of_money == 3) || (amount_of_money == 4)) {
            pieces++;
        }
    } else {
        number_of_5_banknote = pieces;
        amount_of_money = amount_of_money-number_of_5_banknote*five;

        if ((amount_of_money == 3) || (amount_of_money == 4)) {
            pieces++;
        }
    }
    printf("%d-%d\n", five, pieces);

    return 0;
}