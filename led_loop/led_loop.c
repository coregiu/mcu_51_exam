#include <mcs51/8051.h>

void delay() {
    unsigned int i = 512, loop = 10240;
    for (; i>0; i--){
        for (;loop>0;loop--) {

        }
    }
}

void main(){
    unsigned int data1,data2,num;
    while(1) {
        data1=0xfe;
        data2=0x7f;
        for(num=0; num<7; num++) {
            P0=data1;
            data1=data1<<1;
            delay();
        }
        for(num=0; num<7; num++) {
            P0=data2;
            data2=data2>>1;
            delay();
        }
    }
}