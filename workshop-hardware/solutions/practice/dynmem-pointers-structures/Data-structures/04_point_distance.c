#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} point;

// TODO:
// Create a function the constructs a point (returns a pointer to a new point)
// It should take it's x and y coordinate as parameter
point *create_point(int x, int y)
{
	point *point = (point *)malloc(sizeof(point));
	point->x = x;
	point->y = y;
	return point;
}

// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them
float distance(point *point1, point *point2)
{
	float distance = sqrt(pow(point1->x - point2->x, 2) + pow(point1->y - point2->y, 2));
	return distance;
}

int main()
{
	point *point1 = create_point(1, 1);
	point *point2 = create_point(2, 2);
	float distance = distance(point1, point2);
	printf("%f", distance);
	return 0;
}
