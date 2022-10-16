#include <mcs51/8051.h>

#define LED P0_0	  //宏定义LED代表P0
/********************************************************
                    主程序
*********************************************************/

unsigned int loop_times = 0;

void time0_init(void) {
    EA = 1;
    ET0 = 1;
    TR0 = 1;
    TMOD |= 0X01;
    TH0 = 0XFC;
    TL0 = 0X66; // 11.0592晶振 1ms值。  12m晶振是0xfc18
}

void main(void)
{
	time0_init();

	while(1)
	{
		//在此添加其他程序，中断程序可以跟此处的程序同步执行



	}
}
/****************************************************
                 定时器中断程序
*****************************************************/
void time0_exe(void) __interrupt 1 //R0 R1 =  0/1   0/1
{
    loop_times++;
    TH0 = 0XFC;
    TL0 = 0X66;

    if (loop_times >= 1000) {
    	LED = !LED;
        loop_times = 0;
    }
}
