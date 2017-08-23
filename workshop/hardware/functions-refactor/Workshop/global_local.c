#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int speed_of_sound = 340; //  [m/s]

int give_me_distance()
{
    //calculate the distance between you and a lighting
    //the sound of it reaches you in 5 seconds
    //distance = time * speed_of_sound

    int time = 5; // [s]
    int distance;

    //as you can see the time and the distance is a local variable, we can only
    //access them in this function (with these values), but the speed_of_sound is a global variable
    //we can use it without any declaration
}

int give_me_distance_in_km()
{
    //calculate the distance again but this time the result
    //this time the sound reaches you in 50 seconds
    //should be in kilometers

    int divider = 1000;
    int time = 50; // [s]
    int distance;

    //here we have a third local variable called divider

}

//as you can see local variable values can use the same name
//like time and distance and have a different values
//think about the given functions as well, are we usng them correctly?

int main()
{

	return 0;

}
