#include <iostream>
#include <string>

using namespace std;

int main() {
    //RPG Game lite
    //Create a Character class with the following preferences:
    //name 
    //character type (player/monster)
    //health point value
    //attack value
    //defense value   
    //attacking method which takes a character class and decreases its health 
    //value with (current character class attack - input character class defense),
    //if the output is minus, then our health is decreased
    //set the attacking method to have 50% chanse to count our attack value twice,
    //(2xcurrent attack - input defense) before calculating the final health points.

    //create 2 instances of the character class and fill their base stats from their constructor
    //make them attack each other with the attack method from the character class
    //after each round print both the attacker, and the attacked character health
    //make them fight each other until one of them has a health point lower or equal 0
    //print the winner and offer a new game

    //dont forget to use private variables, and get/set methods, and also place out_of_range
    //character class into a seperate file

  return 0;
}