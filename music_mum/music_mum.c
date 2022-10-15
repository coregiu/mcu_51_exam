#include <mcs51/8051.h>

#define uchar unsigned char 
// #define beep P3_6
__sbit __at (0xB6) beep ;
uchar timer0h,timer0l,time;

//世上只有妈妈好  数据表
const uchar sszymmh[]={6,2,3,5,2,1,3,2,2,5,2,2,1,3,2,6,2,1,5,2,1,
                      6,2,4,3,2,2,5,2,1,6,2,1,5,2,2,3,2,2,1,2,1,
                      6,1,1,5,2,1,3,2,1,2,2,4,2,2,3,3,2,1,5,2,2,
                      5,2,1,6,2,1,3,2,2,2,2,2,1,2,4,5,2,3,3,2,1,
                      2,2,1,1,2,1,6,1,1,1,2,1,5,1,6,0,0,0};
// 音阶频率表 高八位
const uchar FREQH[]={0xF2,0xF3,0xF5,0xF5,0xF6,0xF7,0xF8, 
                    0xF9,0xF9,0xFA,0xFA,0xFB,0xFB,0xFC,0xFC, //1,2,3,4,5,6,7,8,i
                    0xFC,0xFD,0xFD,0xFD,0xFD,0xFE,
                    0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFF,} ;
// 音阶频率表 低八位
const uchar FREQL[]={0x42,0xC1,0x17,0xB6,0xD0,0xD1,0xB6,
                    0x21,0xE1,0x8C,0xD8,0x68,0xE9,0x5B,0x8F, //1,2,3,4,5,6,7,8,i
                    0xEE,0x44, 0x6B,0xB4,0xF4,0x2D, 
                    0x47,0x77,0xA2,0xB6,0xDA,0xFA,0x16,};
unsigned int led_times = 0;
unsigned int flag = 1;
void change_led(){
    P0 = flag ? P0 << 1 : P0 >> 1;
    if (led_times == 8) {
        flag = !flag;
        led_times = 0;
        P0 = 0xff;
    }
    led_times++;
}   

void delay(uchar t)		  // 延时函数 
{
	uchar t1;
	unsigned long t2;
	for(t1=0;t1<t;t1++)
	{
		for(t2=0;t2<8000;t2++);
	}
    change_led();
	TR0=0;
}
void song()				 //  音乐处理函数
{
	TH0=timer0h;
	TL0=timer0l;
	TR0=1;
	delay(time);                       
}
/******************************************************************
                  			主函数                                      
******************************************************************/
void main()
{
	uchar k,i;
	TMOD=1; 			//置CT0定时工作方式1
	EA=1;
	ET0=1;				//IE=0x82 //CPU开中断,CT0开中断 
	while(1)
	{
		i=0;  
		while(i<100)				  //音乐数组长度 ，唱完从头再来  
		{              
			k=sszymmh[i]+7*sszymmh[i+1]-1;
			timer0h=FREQH[k];
			timer0l=FREQL[k];
			time=sszymmh[i+2];
			i=i+3;
			song();
		}
	} 
}

void t0int() __interrupt 1		//定时器中断函数
{
	TR0=0;
	beep = !beep;//beep =~beep;
	TH0=timer0h;
	TL0=timer0l;
	TR0=1;
}