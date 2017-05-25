#include <stdio.h>
#include <stdint.h>

//ws-22

int main() {

    uint8_t ac = 8;
    uint8_t time = 120;
    uint8_t out;
    // if ac is dividable by 4
    // and time is not more than 200
    // set out to 0b100

    if(ac%4 == 0 && time <= 200) {
        out = 0b100;
    }

    // if time is more than 200
    // set out to 0b010

    else if(time > 200) {
        out = 0b010;
    }

    // otherwise set out to 0b001

    else {
        out = 0b001;
    }

    printf("%d",out);

    return 0;
}
