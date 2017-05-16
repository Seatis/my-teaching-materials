#include <stdio.h>

struct RectangularCuboid {
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
int GetSurface(struct RectangularCuboid rect_cub) {
    return (2*rect_cub.a*rect_cub.b + 2*rect_cub.a*rect_cub.c + 2*rect_cub.c*rect_cub.b);
}


// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume
int GetVolume (struct RectangularCuboid rect_cub) {
    return (rect_cub.a*rect_cub.b*rect_cub.c);
}

int main() {

    struct RectangularCuboid rect = {2, 2, 2};
    printf("Surface: %d\nVolume: %d", GetSurface(rect), GetVolume(rect));
    return 0;
}