/**
  ******************************************************************************
  *
  * 实验平台:蓉新电子51开发板 
  * 淘宝    :https://rongxindz.taobao.com
  ******************************************************************************
  *
  *
  *	    液晶LCD1602                 										   *
  *																			   *
  ******************************************************************************
**/
#include <mcs51/8051.h>
#include <stdio.h>

#define _nop_() __asm NOP __endasm

unsigned int hour, minute, second, count;

#define RS P1_2
#define RW P1_1
#define E P1_0

#define Data P2 //数据端口

char __data TimeNum[] = "                ";
char __data Test1[] = "                  ";
/******************************************************************/
/*                    函数声明                                    */
/******************************************************************/ /***************************************************************/
void DelayUs(unsigned char us)                                       //delay us
{
    unsigned char uscnt;
    uscnt = us >> 1; /* Crystal frequency in 12MHz*/
    while (--uscnt)
        ;
}
/******************************************************************/
void DelayMs(unsigned char ms) //delay Ms
{
    while (--ms)
    {
        DelayUs(250);
        DelayUs(250);
        DelayUs(250);
        DelayUs(250);
    }
}
void WriteCommand(unsigned char c)
{
    DelayMs(5); //short delay before operation
    E = 0;
    RS = 0;
    RW = 0;
    _nop_();
    E = 1;
    Data = c;
    E = 0;
}
/****************************************************************/
void WriteData(unsigned char c)
{
    DelayMs(5); //short delay before operation
    E = 0;
    RS = 1;
    RW = 0;
    _nop_();
    E = 1;
    Data = c;
    E = 0;
    RS = 0;
}
/*********************************************************************/
void ShowChar(unsigned char pos, unsigned char c)
{
    unsigned char p;
    if (pos >= 0x10)
        p = pos + 0xb0; //是第二行则命令代码高4位为0xc
    else
        p = pos + 0x80; //是第二行则命令代码高4位为0x8
    WriteCommand(p);    //write command
    WriteData(c);       //write data
}
/*************************************************************************/
void ShowString(unsigned char line, char *ptr)
{
    unsigned char l, i;
    l = line << 4;
    for (i = 0; i < 16; i++)
        ShowChar(l++, *(ptr + i)); //循环显示16个字符
}
/*********************************************************************/
void InitLcd()
{
    DelayMs(15);
    WriteCommand(0x38); //display mode
    WriteCommand(0x38); //display mode
    WriteCommand(0x38); //display mode
    WriteCommand(0x08); //显示光标移动位置
    WriteCommand(0x0c); //显示开及光标设置
    WriteCommand(0x01); //显示清屏
    WriteCommand(0x04); //
    WriteCommand(0x0c); //
}
void SetCurPosition(unsigned char X, unsigned char Y)
{
    Y &= 0x01;
    X &= 0x0F; // 限制X不能大于15，Y不能大于1
    if (Y)
    {
        X |= 0xc0; // 当要显示第二行时地址码:0xc0	 0x80 + 0x40
    }
    X |= 0x80;          // 第一行的地址码:0x80
    WriteCommand(X);    //
    WriteCommand(0X0f); //开光标，闪烁
}

/////////////////////////////////////////////////////////////////
void main(void)

{
    InitLcd(); //
    DelayMs(15);
    sprintf(Test1, " gogo yoyo      "); //the first line
    ShowString(0, Test1);
    sprintf(TimeNum, "zhangsai is good boy"); //the first line
    ShowString(1, TimeNum);
    SetCurPosition(0, 0); //第一行第一位置

    while (1)
        ;
}
