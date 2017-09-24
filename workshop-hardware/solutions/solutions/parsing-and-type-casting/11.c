#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	char command[256];
    char logged_in = 0;
    char registered = 0;

    //TODO: write a register -login -logout program
    //if you type in register print out "Registration..." or "You are already registered." if you are registered.
    //if you type in login print out "Logging in..." or "Already logged in." if are logged in.
    //if you type in logout print out "Logging out..." or "Already logged out." if are logged out.
	while (1) {
        int r = rand() % 3;
		gets(command);
		if (strstr(command, "register") != NULL) {
			if (registered == 0) {
                printf("Registration...\n");
                registered++;
			} else {
                printf("You are already registered.\n");
			}
		} else if (strstr(command, "login") != NULL) {
			if (logged_in == 0) {
                printf("Logging in...\n");
                logged_in = 1;
			}
			else {
                printf("Already logged in.\n");
			}
        } else if (strstr(command, "logout") != NULL) {
			if (logged_in == 1) {
                printf("Logging out...\n");
                logged_in = 0;
			}
			else {
                printf("Already logged out.\n");
			}
        } else {

		}
	}
}