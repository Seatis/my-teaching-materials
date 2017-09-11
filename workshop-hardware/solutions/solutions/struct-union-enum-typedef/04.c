#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float x;
	float y;
} point_t;

// TODO:
// Create a function the constructs a point
// It should take it's x and y coordinate as parameter
point_t create_point(float x, float y)
{
	point_t p;
	p.x = x;
	p.y = y;
    return p;
}

// TODO:
// Create a function that takes 2 points as a pointer and returns the distance between them
float distance(point_t p1, point_t p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}