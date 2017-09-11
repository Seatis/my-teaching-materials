#include <stdio.h>

struct rectengular_cuboid {
	double a;
	double b;
	double c;
};

// TODO:
// Write a function called "get_surface" that takes a rectengular_cuboid
// and returns it's surface
int get_surface(struct rectengular_cuboid rect_cub)
{
	return (2 * rect_cub.a * rect_cub.b + 2 * rect_cub.a * rect_cub.c + 2 * rect_cub.c * rect_cub.b);
}


// TODO:
// Write a function called "get_volume" that takes a rectengular_cuboid
// and returns it's volume
int get_volume (struct rectengular_cuboid rect_cub)
{
	return (rect_cub.a * rect_cub.b * rect_cub.c);
}

int main()
{
	struct rectengular_cuboid rect = {2, 2, 2};
	printf("Surface: %d\nVolume: %d", get_surface(rect), get_volume(rect));
	return 0;
}
