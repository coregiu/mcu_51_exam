#include <mcs51/8051.h>

unsigned int seg[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,0xff,0xff,0x00,0,0x55,0x55,0xaa,0xaa};//rom允许情况可以无限添加

void delay() {
    unsigned int i = 512, loop = 10240;
    for (; i>0; i--){
        for (;loop>0;loop--) {

        }
    }
}

void main(){
    unsigned int i;
    while(1)
    {
    P0=0xFE;//第一个LED亮
    for(i=0;i<8;i++)
        {
        delay();
        P0 <<=1;
        }

    P0=0x7F;//第七个LED亮
    for(i=0;i<8;i++)
        {
        delay();
        P0 >>=1;
        }

    P0=0xFE;//第一个LED亮
    for(i=0;i<8;i++)
        {
        delay();
        P0 <<=1;
        P0 |=0x01;
        }

    P0=0x7F;//第七个LED亮
    for(i=0;i<8;i++)
        {
        delay();
        P0 >>=1;
        P0 |=0x80;
        }
    ////////////////////////////////////
        for(i=0;i<16;i++)//查表可以简单的显示各种花样 实用性更强
        {
        delay();
        P0=seg[i];
        }
    }
}