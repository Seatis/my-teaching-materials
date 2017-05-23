#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a function that takes a double array as a parameter, and the length of the array.
// This function should calculate the avarage of the elements.

double avarage(double array[], int length)
{
    double avarage = 0;
    for(int i=0; i<length; i++) {
        avarage += array[i];
    }
    return (avarage/length);
}

// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It calculates how much elements are under the avarage, and returns with that.
int under_avarage(double array[], int length, float avarage)
{
    int num_of_under_avarage=0;
    for(int i=0; i<length; i++) {
        if(array[i]<avarage) {
            num_of_under_avarage++;
        }
    }
    return num_of_under_avarage;
}

// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It allocates a new array, and loads into it the elements which are under the average.
// It returns a pointer to the new array.
double *create_array_with_under_avg(double array[], int length, double avg)
{
    double *new_array = (double*)calloc(length, sizeof(double));
    int index=0;
    for (int i=0; i<length; i++) {
        if (array[i]<avg) {
            new_array[index]=array[i];
            index++;
        }
    }
    return new_array;
}

int main()
{
    double array[]={5.0, 3.3, 4.0, 6.6, 7.1};
    int n = sizeof(array)/sizeof(array[0]);

    float avg = avarage(array, n);
    printf("%f\n", avg);

    int under = under_avarage(array, n, avg);
    printf("%d", under);

    printf("\nNumbers under the avarage:\n");
    double *array_under_avg = create_array_with_under_avg(array, n, avg);
    for(int i=0; i<under; i++) {
        printf("%f\n", array_under_avg[i]);
    }

    return 0;
}
