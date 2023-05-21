/**************************************************************************
                        PCA9685模块简单应用
                平台：STC89C52RC，晶振：11.0592
***************************************************************************/
#include <mcs51/8051.h>
#include <stdio.h>
typedef unsigned char uchar;
typedef unsigned int uint;

#define _nop_() __asm NOP __endasm
#define scl P1_1 //时钟输入线
#define sda P1_0 //数据输入/输出端

#define PCA9685_adrr 0x80 //  1+A5+A4+A3+A2+A1+A0+w/r
#define PCA9685_SUBADR1 0x2
#define PCA9685_SUBADR2 0x3
#define PCA9685_SUBADR3 0x4

#define PCA9685_MODE1 0x00
#define PCA9685_PRESCALE 0xFE

#define LED0_ON_L 0x06
#define LED0_ON_H 0x07
#define LED0_OFF_L 0x08
#define LED0_OFF_H 0x09

#define ALLLED_ON_L 0xFA
#define ALLLED_ON_H 0xFB
#define ALLLED_OFF_L 0xFC
#define ALLLED_OFF_H 0xFD

//#define SERVO_ANGLE0  102 //0度对应4096的脉宽计数值
//#define SERVO_ANGLE180  476 //180度对应4096的脉宽计算值，根据不同舵机修改

void delayms(uint z);
void delayus();
void init_pca9685();
void init_iic();
void start_iic();
void stop_iic();
void ack_iic();
void write_byte(uchar byte);
uchar pca9685_read(uchar address);
uchar read_byte();
void pca9685_write(uchar address, uchar date);
void reset_pca9685(void);
void set_pwm_freq(float freq);
void servo_control(uchar num, uchar angle);

/**********************函数的声明*********************************/
/*---------------------------------------------------------------
                  毫秒延时函数
----------------------------------------------------------------*/
void delayms(uint z)
{
    uint x, y;
    for (x = z; x > 0; x--)
        for (y = 148; y > 0; y--)
            ;
}

/*---------------------------------------------------------------
                                                                        IIC总线所需的通用函数
----------------------------------------------------------------*/
/*---------------------------------------------------------------
                 微妙级别延时函数 大于4.7us
----------------------------------------------------------------*/
void delayus()
{
    _nop_(); //在intrins.h文件里
    _nop_();
    _nop_();
    _nop_();
    _nop_();
}
/*---------------------------------------------------------------
                 IIC总线初始化函数 
----------------------------------------------------------------*/
void init_iic()
{
    sda = 1; //sda scl使用前总是被拉高
    delayus();
    scl = 1;
    delayus();
}
/*---------------------------------------------------------------
                 IIC总线启动信号函数
----------------------------------------------------------------*/
void start_iic()
{
    sda = 1;
    delayus();
    scl = 1; //scl拉高时 sda突然来个低电平 就启动了IIC总线
    delayus();
    sda = 0;
    delayus();
    scl = 0;
    delayus();
}
/*---------------------------------------------------------------
                 IIC总线停止信号函数
----------------------------------------------------------------*/
void stop_iic()
{
    sda = 0;
    delayus();
    scl = 1; //scl拉高时 sda突然来个高电平 就停止了IIC总线
    delayus();
    sda = 1;
    delayus();
}
/*---------------------------------------------------------------
                 IIC总线应答信号函数
----------------------------------------------------------------*/
void ack_iic()
{
    uchar i = 0;
    scl = 1;
    delayus();
    while ((sda = 1) && (i < 255))
        i++;
    scl = 0;
    delayus();
}
/*---------------------------------------------------------------
                 写一个字节,无返回值，需输入一个字节值
----------------------------------------------------------------*/
void write_byte(uchar byte)
{
    uchar i, temp;
    temp = byte;
    for (i = 0; i < 8; i++)
    {
        temp = temp << 1;
        scl = 0;
        delayus();
        sda = CY;
        delayus();
        scl = 1;
        delayus();
    }
    scl = 0;
    delayus();
    sda = 1;
    delayus();
}
/*---------------------------------------------------------------
                 读一个字节函数，有返回值
----------------------------------------------------------------*/
uchar read_byte()
{
    uchar k = 0;
    scl = 0;
    delayus();
    sda = 1;
    delayus();
    for (uchar i = 0; i < 8; i++)
    {
        uchar j = 0;
        delayus();
        scl = 1;
        delayus();
        if (sda == 1)
        {
            j = 1;
        }
        else
            j = 0;
        k = (k << 1) | j;
        scl = 0;
    }
    delayus();
    return k;
}
/*---------------------------------------------------------------
                有关PCA9685模块的函数
----------------------------------------------------------------*/
/*---------------------------------------------------------------
                向PCA9685里写地址，数据
----------------------------------------------------------------*/
void pca9685_write(uchar address, uchar date)
{
    start_iic();
    write_byte(PCA9685_adrr); //PCA9685的片选地址
    ack_iic();
    write_byte(address); //写地址控制字节
    ack_iic();
    write_byte(date); //写数据
    ack_iic();
    stop_iic();
}
/*---------------------------------------------------------------
            从PCA9685里的地址值中读数据(有返回值)
----------------------------------------------------------------*/
uchar pca9685_read(uchar address)
{
    uchar date;
    start_iic();
    write_byte(PCA9685_adrr); //PCA9685的片选地址
    ack_iic();
    write_byte(address);
    ack_iic();
    start_iic();
    write_byte(PCA9685_adrr | 0x01); //地址的第八位控制数据流方向，就是写或读
    ack_iic();
    date = read_byte();
    stop_iic();
    return date;
}
/*---------------------------------------------------------------
                        PCA9685复位
----------------------------------------------------------------*/
void reset_pca9685(void)
{
    pca9685_write(PCA9685_MODE1, 0x0);
}

/*---------------------------------------------------------------
                                        PCA9685修改频率函数
----------------------------------------------------------------*/
void set_pwm_freq(float freq)
{
    uint prescale, oldmode, newmode;
    float prescaleval;
    freq *= 0.92; // Correct for overshoot in the frequency setting
    prescaleval = 25000000;
    prescaleval /= 4096;
    prescaleval /= freq;
    prescaleval -= 1;
    prescale = (uint)(prescaleval + 0.5);

    oldmode = pca9685_read(PCA9685_MODE1);
    newmode = (oldmode & 0x7F) | 0x10;         // sleep
    pca9685_write(PCA9685_MODE1, newmode);     // go to sleep
    pca9685_write(PCA9685_PRESCALE, prescale); // set the prescaler
    pca9685_write(PCA9685_MODE1, oldmode);
    delayms(2);
    pca9685_write(PCA9685_MODE1, oldmode | 0xa1);
}
/*---------------------------------------------------------------
                                PCA9685修改角度函数
num:舵机PWM输出引脚0~15，on:PWM上升计数值0~4096,off:PWM下降计数值0~4096
一个PWM周期分成4096份，由0开始+1计数，计到on时跳变为高电平，继续计数到off时
跳变为低电平，直到计满4096重新开始。所以当on不等于0时可作延时,当on等于0时，
off/4096的值就是PWM的占空比。
----------------------------------------------------------------*/
void servo_control(uchar num, uchar angle)
{
    uint off = 102.4 + 2.275555556 * angle;
    pca9685_write(LED0_ON_L + 4 * num, 0);
    pca9685_write(LED0_ON_H + 4 * num, 0);
    pca9685_write(LED0_OFF_L + 4 * num, off);
    pca9685_write(LED0_OFF_H + 4 * num, off >> 8);
}

void init_pca9685()
{
    init_iic();
    reset_pca9685();
    set_pwm_freq(50);
}

/*---------------------------------------------------------------
                      主函数
----------------------------------------------------------------*/
void main()
{
    init_pca9685();
    //例如要求舵机转到x度，这么算，
    //x度对应的脉宽=0.5ms+(x/180)*(2.5ms-0.5ms)=1.1666ms
    //利用占空比=1.1666ms/20ms=off/4096,off=239,50hz对应周期20ms
    //setPWM(num,0,239);;;;当然也可以利用SERVO000和SERVO180计算
    while (1)
    {
        delayms(10);
        if (P3_2 == 0) {
            P0_0 = !P0_0;
            for (int i = 0; i < 180; i++)
            {
                servo_control(1, i);
                delayms(10);
            }
        }
        if (P3_3 == 0) {
            P0_1 = !P0_1;
            servo_control(1, 0);//right
        }
        if (P3_4 == 0) {
            P0_2 = !P0_2;
            servo_control(1, 90);//right
        }
        if (P3_5 == 0) {
            P0_3 = !P0_3;
            servo_control(1, 176);//right
        }
        // for (int i = 0; i < 180; i++)
        // {
        //     servo_control(1, i);
        //     delayms(10);
        // }
        // for (uint i = 90; i < 180; i++)
        // {
        //     servo_control(1, i);
        //     delayms(10);
        // }
        // for (uint i = 0; i < 90; i++)
        // {
        //     servo_control(1, 90 - i);
        //     delayms(10);
        // }
        

        // servo_control(1, 0);//right
        // delayms(2000);
        // servo_control(1, 88);//middle
        // delayms(2000);
        // servo_control(1, 179);//left
        // delayms(2000);
    }
}

void Key_INT_0(void) __interrupt 0 //R0 R1 =  0/1   0/1
{
    delayms(10);
    if (P3_2 == 0) {
        P0_0 = !P0_0;
        for (int i = 0; i < 180; i++)
        {
            servo_control(1, i);
            delayms(10);
        }
    }
    if (P3_3 == 0) {
        P0_1 = !P0_1;
        servo_control(1, 0);//right
    }
    if (P3_4 == 0) {
        P0_2 = !P0_2;
        servo_control(1, 90);//right
    }
    if (P3_5 == 0) {
        P0_3 = !P0_3;
        servo_control(1, 179);//right
    }
}