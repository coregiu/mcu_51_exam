#include <mcs51/8051.h>
#include <stdio.h>
// #include <intrins.h>
// #include <absacc.h>
/*********************************************************
Copyright (C), 2015-2025, ZYRobot.
湖南智宇科教设备有限公司
www.hnzhiyu.cn
File：ps2测试程序
Author：zhulin    Version:1.0     Data:2017/05/30

**********************************************************/

#define uchar unsigned char
#define uint unsigned int
#define _nop_() __asm NOP __endasm

#define DATA   P1_0  //D0
#define CMND   P1_1  //D1
#define ATT    P1_2  //CS
#define CLK    P1_3  //CLK

/********手柄定义变量*********/
uchar scan[9] = {0x01, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uchar out[9];

/********************************************************************
* 名称 : void delayms(uint xms)
* 功能 : 延时
* 输入 : 有
* 输出 : 无
***********************************************************************/
void delayms(uint xms)
{
	uint i, j;
	for (i = xms; i > 0; i--)
		for (j = 70; j > 0; j--)
			;
}
/********************************************************************
* 名称 : void uart_init()
* 功能 : 串口设置
* 输入 : 无
* 输出 : 无
***********************************************************************/
void uart_init()
{
	TMOD=0x20;		   //用定时器设置串口波特率	   9600 
	TH1=0xfd;
	TL1=0xfd;
	TR1=1;
	REN=1;          //串口初始化
	SM0=0;
	SM1=1;
	EA=1;           //开启总中断
	ES=1;
}

/********************************************************************
* 名称 : uart_sendata(uchar n)
* 功能 : 发送字节
* 输入 : 有
* 输出 : 无
***********************************************************************/
void uart_sendata(uchar n)
{
	ES = 0;
	TI = 0;
	SBUF = n;
	while (!TI)
		; //如果发送完毕，硬件会置位TI
	TI = 0;
	ES = 1;
}

void delay(uint n) //delay(x)=(2.5+x)us;
{
	uint i;
	for (i = 0; i < n; i++)
		_nop_();
}

void psin(uchar command) //手柄发送子程序
{
	uchar i;
	for (i = 0; i <= 7; i++) //逐位接收
	{
		if (command & 0x01) //此if下5行语句用时1us
			CMND = 1;
		else
			CMND = 0;
		command = command >> 1;
		_nop_();
		_nop_();
		CLK = 0;
		delay(3);
		CLK = 1;
		delay(1);
	}
	CMND = 1;
}

uchar scanout(uchar command) //手柄发送子程序
{
	uchar i, j = 1;
	uchar res = 0;
	for (i = 0; i <= 7; i++) //逐位接收
	{
		if (command & 0x01)
			CMND = 1;
		else
			CMND = 0;
		command = command >> 1;
		_nop_();
		_nop_();
		CLK = 0;
		// delay(3);
		if (DATA)
			res = res + j;
		j = j << 1;
		CLK = 1;
		delay(3);
	}
	CMND = 1;
	return res;
}
void Read_PS2(void) //手柄读取程序
{
	uchar i;
	ATT = 0;
	for (i = 0; i < 9; i++) //扫描按键
	{
		out[i] = scanout(scan[i]);
	}
	ATT = 1;
	for (i = 0; i < 9; i++)
	{
		uart_sendata(0x30);
		uart_sendata(0x78);
		if (out[i] / 16 < 10)
			uart_sendata(out[i] / 16 + 0x30);
		else
			uart_sendata(out[i] / 16 + 0x37);
		if (out[i] % 16 < 10)
			uart_sendata(out[i] % 16 + 0x30);
		else
			uart_sendata(out[i] % 16 + 0x37);
		uart_sendata(' ');
		uart_sendata(' ');
	}
	uart_sendata(0x0d);
	uart_sendata(0x0a);
}
void main()
{
	delayms(500);
	P0_0 = 0;
	uart_init();

	while (1)
	{
		Read_PS2();

		switch (out[3])
		{
			case 0XEF:
                P0_0 = !P0_0;//left top
		uart_sendata(out[3]);
                break;
            case 0xBF:
                P0_1 = !P0_1;//left down
		uart_sendata(out[3]);
                break;
            case 0x7F:
                P0_2 = !P0_2;//left left
		uart_sendata(out[3]);
                break;
            case 0xDF:
                P0_3 = !P0_3;//left right
		uart_sendata(out[3]);
                break;
		default:
			break;
		}

		switch (out[4])
		{
		
            case 0XEF:
                P0_4 = !P0_4;//right top
		uart_sendata(out[4]);
                break;
            case 0xBF:
                P0_5 = !P0_5;//right down
		uart_sendata(out[4]);
                break;
            case 0x7F:
                P0_6 = !P0_6;//right left
		uart_sendata(out[4]);
                break;
            case 0xDF:
                P0_7 = !P0_7;//right right
		uart_sendata(out[4]);
                break;
		
		default:
			break;
		}
		
		delayms(200);
	}
}

/*****************************PS2遥控器说明
out[3]==0xEF//左4个按键中上
out[3]==0xBF//左4个按键中下
out[3]==0x7F//左4个按键中左
out[3]==0xDF//左4个按键中右

out[4]==0xEF//右4个按键中上
out[4]==0xBF//右4个按键中下
out[4]==0x7F//右4个按键中左
out[4]==0xDF//右4个按键中右

out[4]==0xFB//左1,2个按键中1
out[4]==0xFE//左1,2个按键中2
out[4]==0xF7//右1,2个按键中1
out[4]==0xFD//右1,2个按键中2

当按下MODE键手柄MODE LED灯亮起时
out[7] 00——80——FF 左摇杆从左到右
out[8] 00——7F——FF 左摇杆从上到下
out[5] 00——80——FF 右摇杆从左到右
out[6] 00——7F——FF 右摇杆从上到下
当手柄MODE LED灯不亮时，手柄功能同左四右四按键
*******************************/