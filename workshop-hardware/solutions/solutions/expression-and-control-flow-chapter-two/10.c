#include <stdio.h>
#include <stdlib.h>

/*
write a simple program which can help you decide is it hot enough to turn on the AC or not
for example if temperature 20 or less the output is :
it is too cold for the AC
or, the temperature is between 21-24:
it is up to you to turn on the AC
...
*/

int main()
{
    int temperature;
    temperature = 23;

	switch ((temperature >= 21) && (temperature <= 24)) {
    case 1:
        printf("it is up to you to turn on the AC");
        break;
	case !1:
	    switch (temperature <= 20) {
        case 1:
            printf("it is too cold for the AC");
            break;
	    }
	}

    return 0;
}