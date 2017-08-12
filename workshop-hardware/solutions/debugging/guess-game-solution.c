#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//project-guessing-game
//Note: the program gets harder, when you set a lower range

int main()
{

	int x, y;
	int count;
	int guess = 0;
	int Rand_max;
	int Rand_min;
	printf("please add the minimum number!\n");
	scanf("%d", &Rand_min);
	printf("please add the maximum number!\n");
	scanf("%d", &Rand_max);
	srand(time(NULL));
	int rand_num = rand() % (Rand_max + 1 - Rand_min) + Rand_min;
	y = Rand_max - Rand_min;
	x = log10(y) / log10(2);

	printf("I have a number between %d and %d. You have %d lives\n", Rand_min, Rand_max, x - 2);

	for (count = 0; count < x - 2; count++) {
		printf("\n>");
		scanf("%d", &guess);

		if (guess == rand_num) {
			printf("Yeeeeey, you did well! It took you %d tires!", count + 1);
			break;
		}

		if (guess > rand_num)
			printf("Too big, You have %d lives left\n", x - 3 - count);
		else
			printf("Too low, You have %d lives left\n", x - 3 - count);

	}

	if (count == x - 2)
		printf("You have used all your lives!");


	return 0;

}
