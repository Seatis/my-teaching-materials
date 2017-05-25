#include <stdio.h>

//ws-08

int main() {
    int h1 = 350;
    int h2 = 200;

// tell if the double of h2 is bigger than h1

    printf("h1=%d\n",h1);
    printf("h2=%d\n",h2);
    printf("after h2 is duobled\n");
    h2 = 2*h2;
    if(h1 >h2) {
        printf("h1 is bigger");
    } else {
        printf("h2 is bigger");
    }


    return 0;
}
