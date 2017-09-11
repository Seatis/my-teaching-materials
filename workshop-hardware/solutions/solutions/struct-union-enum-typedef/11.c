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

point_t make_dir_vect(section_t line);
equation_t make_line_equation(section_t sect);
equation_t make_line_equation(section_t sect);
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

point_t make_dir_vect(section_t line)       //helper function
{
    point_t p;
    p.x = line.end.x - line.start.x;
    p.y = line.end.y - line.start.y;
    return p;
}

equation_t make_line_equation(section_t sect)
{
    equation_t eq;
    eq.p = make_dir_vect(sect);
    eq.right_side = eq.p.x * sect.start.x + eq.p.y * sect.start.y;
    return eq;
}

point_t intersection_point(section_t sec1, section_t sec2)
{
    //making line equations from the 2 section
    equation_t eq1 = make_line_equation(sec1);
    equation_t eq2 = make_line_equation(sec2);

    //saving first equation for later use
    equation_t temp = eq2;

    //solving the system of equations
    eq1.p.y = eq1.p.y * eq2.p.x;
    eq1.right_side = eq1.right_side * eq2.p.x;

    eq2.p.y = eq2.p.y * eq1.p.x;
    eq2.right_side = eq2.right_side * eq1.p.x;

    //getting y value
    equation_t res;
    res.p.y = eq2.p.y - eq1.p.y;
    res.right_side = eq2.right_side - eq1.right_side;
    float y = res.right_side / res.p.y;

    //substituting to the original equation
    float x = (temp.right_side - temp.p.y * y) / temp.p.x;

    //struct to return with a point type
    point_t ret;
    ret.x = x;
    ret.y = y;
    return ret;
}