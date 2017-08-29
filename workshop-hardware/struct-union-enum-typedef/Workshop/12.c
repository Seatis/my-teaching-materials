#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x;
    float y;

} point_t;

typedef struct
{
    point_t start;
    point_t end;

} section_t;

typedef struct
{
    point_t p;
    float right_side;
} equation_t;

point_t intersection_point(section_t sec1, section_t sec2);

//TODO: write a C program which can find the intersection point of two section

int main()
{
    section_t first_sect, second_sect;

    first_sect.start.x = -8;
    first_sect.start.y = 1;
    first_sect.end.x = 2;
    first_sect.end.y = 5;

    second_sect.start.x = -4;
    second_sect.start.y = 9;
    second_sect.end.x = 2;
    second_sect.end.y = -3;

    point_t intersect = intersection_point(first_sect, second_sect);
    printf("Intersection point: x = %f, y = %f.\n", intersect.x, intersect.y);

    return 0;
}