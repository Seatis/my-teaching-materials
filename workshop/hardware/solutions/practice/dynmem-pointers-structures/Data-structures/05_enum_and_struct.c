#include <stdio.h>

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
	enum car_type type;
	double km;
	double gas;
};

// TODO:
// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level
void print_stats(struct car var_car)
{
	printf("%f\n", var_car.km);
	if (var_car.type != TESLA) {
		printf("%f", var_car.gas);
	}
}

int main()
{
	struct car var_car = {TOYOTA, 1500.25, 80.75};
	print_stats(var_car);
	return 0;
}
