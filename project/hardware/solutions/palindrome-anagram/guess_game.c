#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count;
	int guess = 0;
	int rand_max;
	int rand_min;
	printf("please add the maximum number!\n");
	scanf("%d", &rand_max);
	printf("please add the minimum number!\n");
	scanf("%d", &rand_min);
	srand(time(NULL));
	int rand_num = rand() % (rand_max + 1 - rand_min) + rand_min;
	printf("%d\n", rand_num);

	printf("I have a number between %d and %d. You have 5 lives\n", rand_min, rand_max);

	for (count = 0; count < 5; count++) {
		printf("\n>");
		scanf("%d", &guess);

		if (guess == rand_num) {
			printf("Yeeeeey, you did well! It took you %d tires!", count + 1);
			break;
		}

		if (guess > rand_num)
			printf("Too big, You have %d, lives left\n", 4 - count);
		else
			printf("Too low, You have %d, lives left\n", 4 - count);

	}

	if (count == 5)
		printf("You have used all your lives!");


	return 0;
}
