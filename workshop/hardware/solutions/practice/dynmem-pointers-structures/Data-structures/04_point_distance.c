#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} Point;

// TODO:
// Create a function the constructs a Point (returns a pointer to a new point)
// It should take it's x and y coordinate as parameter
Point* CreatePoint(int x, int y)
{
    Point* point =(Point*)malloc(sizeof(Point));
    point->x=x;
    point->y=y;
    return point;
}

// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them
float Distance(Point* point1, Point* point2)
{
    float distance = sqrt(pow(point1->x-point2->x, 2)+pow(point1->y-point2->y, 2));
    return distance;
}

int main()
{
    Point* point1=CreatePoint(1, 1);
    Point* point2=CreatePoint(2, 2);
    float distance = Distance(point1, point2);
    printf("%f", distance);
	return 0;
}