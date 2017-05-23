#include <stdio.h>

struct Pirate {
    char name[256];
    int has_wooden_leg;
    short int gold_count;
};

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates
int GetGoldSum(struct Pirate* p, int len)
{
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += p[i].gold_count;
    }
    return sum;
}

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate
float GetGoldAvg(struct Pirate* p, int len) {
    int sum = GetGoldSum(p, len);
    return ((float)sum / len);
}

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg
char* GetRichestWithWoodenLeg(struct Pirate* p, int len)
{
    // Search for the richest
    int richest_index = 0;
    int highest_gold_count = 0;
    for(int i = 0; i < len; i++) {
        if((p[i].gold_count > highest_gold_count) && p[i].has_wooden_leg) {
            highest_gold_count = p[i].gold_count;
            richest_index = i;
        }
    }
    return (p[richest_index].name);
}

int main()
{
    struct Pirate pirates[] = {
        {"Jack", 0, 18},
        {"Uwe", 1, 8},
        {"Hook", 1, 12},
        {"Halloween kid", 0, 0},
        {"Sea Wolf", 1, 14},
        {"Morgan", 0, 1}
    };

    int len = sizeof(pirates) / sizeof(pirates[0]);
    printf("GoldSum:\t%d\n", GetGoldSum(pirates, len));
    printf("GoldAvg:\t%f\n", GetGoldAvg(pirates, len));
    printf("Richest:\t%s\n", GetRichestWithWoodenLeg(pirates, len));


    return 0;
}