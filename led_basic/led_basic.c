#include <mcs51/8051.h>

void delay(unsigned int delayTime) {
    unsigned int i = delayTime*10, loop = 10240;
    for (; i>0; i--){
        for (;loop>0;loop--) {

        }
    }
}

void main(){
    while(1) {
        P0 = 0;
        delay(1000);
        P0 = 0xff;
        delay(1000);
    }
}