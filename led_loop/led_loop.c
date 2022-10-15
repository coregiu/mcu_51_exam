#include <mcs51/8051.h>

void delay() {
    unsigned int i, j;
    for (i=0; i < 100; i++){
        for (j=0; j < 100; j++) {

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