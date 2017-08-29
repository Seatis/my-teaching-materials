#include <stdlib.h>

#include "sin_gen.h"

typedef struct
{
    int peak_to_peak;
    float avarage;
} meas_t;


//TODO: write a program which can calculate the mean value, and the peak to peak value of an oscilloscope measurement sequence
//the gen_sine_512_sample() function generates 512 integer sample.
//it's in the libsine_gen.a so it is precompiled, because if you'd see the source code you could easily guess the solution
//you should copy and include the sin_gen.h file and link the library (in CodeBlocks: Project->Build options...->Linker settings->Add, and browse the library.

int main() {

    int meas[512];
    gen_sine_512_sample(&meas);


    return 0;
}