#include <stdio.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
struct house {
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
int is_worth_to_buy(struct house *house)
{
	if (MARKET_PRICE >= (house->price_eur / house->area_sqm))
		return 1;
	else
		return 0;

}

// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
int get_worth_to_buy_count(struct house *houses, int len)
{
	int cntr = 0;

	for (int i = 0; i < len; i++) {
		if (is_worth_to_buy(&houses[i]))
			cntr++;
	}

	return cntr;
}

int main()
{
	struct house house1 = {
		"1117, Budapest, Irinyi Jozsef utca 42.",
		200e6,
		288,
		12568
	};
	struct house house2 = {
		"1234, Az, Utca utca 23.",
		100,
		2,
		40
	};

	struct house array[2];
	array[0] = house1;
	array[1] = house2;

	printf("%d\n", is_worth_to_buy(&house1));
	printf("%d\n", is_worth_to_buy(&house2));
	printf("%d\n", get_worth_to_buy_count(array, 2));

	return 0;
}
