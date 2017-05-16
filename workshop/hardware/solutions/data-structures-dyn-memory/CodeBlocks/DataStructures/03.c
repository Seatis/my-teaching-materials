#include <stdio.h>

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  enum CarType type;
  double km;
  double gas;
};

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level
void PrintStats(struct Car car)
{
    printf("%f\n", car.km);
    if (car.type != TESLA)
    {
        printf("%f", car.gas);
    }
}

int main() {

    struct Car car = {TESLA, 1500.25, 80.75};
    PrintStats(car);
    return 0;
}