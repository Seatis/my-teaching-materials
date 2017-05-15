#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input

    //TODO:
    // Get the user's name with gets
    printf("Your name is: ");
    gets(buffer);

    //TODO:
    // Print it out with puts
    printf("You are ");
    puts(buffer);
    printf("\n");

    //TODO:
    // Get the user's pet name with getch
    printf("Please enter your pet's name: ");
    int index = 0;
    char character = getch();
    while(character != '\r') {
        buffer[index] = character;
        index++;
        character = getch();
    }
    buffer[index] = 0;

    //TODO:
    // Print it out
    printf("\nYour pet is ");
    puts(buffer);

    return 0;
}
