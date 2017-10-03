#include "operations.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

float add(float firstoperand, float secondoperand)
{
    return firstoperand + secondoperand;
}

float sub(float firstoperand, float secondoperand)
{
    return firstoperand - secondoperand;
}

float mul(float firstoperand, float secondoperand)
{
    return firstoperand * secondoperand;
}

float divide(float firstoperand, float secondoperand)
{
    return firstoperand/secondoperand;
}

int mod(int firstoperand, int secondoperand)
{
    return firstoperand%secondoperand;
}

float power(float firstoperand, float secondoperand){
    return pow(firstoperand, secondoperand);
}

float logarithm(float firstoperand, float secondoperand)
{
    return (log10(secondoperand)/log10(firstoperand));
}
