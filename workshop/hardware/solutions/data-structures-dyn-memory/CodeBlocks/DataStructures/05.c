#include <stdio.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
struct House {
    char addr[256];
    float price_eur;
    int room_count;
    float area_sqm;
};

// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)
#define MARKET_PRICE    400
int IsWorthToBuy(struct House* house) {
    if(MARKET_PRICE <= (house->price_eur / house->area_sqm)) {
        return 1;
    } else {
        return 0;
    }
}

// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
int GetWorthToBuyCount(struct House* houses, int len) {
    int cntr = 0;

    for(int i = 0; i < len; i++) {
        if(IsWorthToBuy(houses[i])) {
            cntr++;
        }
    }

    return cntr;
}

int main() {

  return 0;
}
