/**
  ******************************************************************************
  *
  * 实验平台:蓉新电子51开发板 
  * 淘宝    :https://rongxindz.taobao.com
  ******************************************************************************
    *
  *
  *	    单片机串口与PC通信           										   *
  *     波特率9600                       								               *

  *
  * 【函数功能】： 串口中断程序实验——通过PC上位机软件控制流水灯实验			   			            			    
				 发送 01 ， D1 led灯亮；
				 发送 02 ， D2 led灯亮；
				 发送 03 ， D3 led灯亮；
				 发送 04 ， D4 led灯亮；
				 发送 05 ， D5 led灯亮；
				 发送 06 ， D6 led灯亮；
				 发送 07 ， D7 led灯亮；
				 发送 08 ， D8 led灯亮；
  *                             								               *
  *																			   *
  ******************************************************************************
**/

/*预处理命令*/
#include <mcs51/8051.h>		  //包含单片机寄存器的头文件
#define uchar unsigned char
#define uint unsigned int
#define LED P0
uchar dat,num;

// D7作为信号展示灯，每接收一个字符，反转一次
void change_led(){
    P0_7 = !P0_7;
}

void main()
{	
	TMOD=0x20;		   //用定时器设置串口波特率
	TH1=0xfd;
	TL1=0xfd;
	TR1=1;
	REN=1;          //串口初始化
	SM0=0;
	SM1=1;
	EA=1;           //开启总中断
	ES=1;			//开启串口中断
	while(1)
	{	
		if(num==1)
		{
            change_led();
			switch(dat)    //判断串口接收的数据
			{	case '1':P0_0=0;break;  //点亮第1个灯
				case '2':P0_1=0;break;  //点亮第2个灯
				case '3':P0_2=0;break;  //点亮第3个灯
				case '4':P0_3=0;break;  //点亮第4个灯
				case '5':P0_4=0;break;  //点亮第5个灯
				case '6':P0_5=0;break;  //点亮第6个灯
				case '7':P0_6=0;break;  //点亮第7个灯
				case '0':P0|=0x7f;break;  //清空所有的灯
				default :break;
			}
			ES=1;		 //打开串口中断	
			num=0;
		}
		
	}	
}

void serial() __interrupt 4
{
	RI=0;
	dat = SBUF;				//接收数据SBUF，即将计算机的数据接收。
	ES=0;				    //关闭串口中断
	num=1;
}