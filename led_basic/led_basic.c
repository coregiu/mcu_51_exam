#include <mcs51/8051.h>

void delay(unsigned int delayTime) {
    unsigned int loopi;
    for (delayTime; delayTime > 0; delayTime--){
        for (loopi = 0; loopi < 100; loopi++){

        }
    }
}

void main(){
    while(1) {
        P0_0 = 0;
        delay(500);
        P0_0 = 1;
        delay(500);
    }
}