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
#include <mcs51/8051.h>

#define uint unsigned int
#define uchar unsigned char

#define COMMANDS_LENGTH 8

// define commands id
#define COMMAND_NULL         0
#define COMMAND_LEFT_TOP     1
#define COMMAND_LEFT_DOWN    2
#define COMMAND_LEFT_LEFT    3
#define COMMAND_LEFT_RIGHT   4
#define COMMAND_RIGHT_TOP    5
#define COMMAND_RIGHT_RIGHT  6
#define COMMAND_RIGHT_LEFT   7
#define COMMAND_RIGHT_DOWN   8

const uint command_map[COMMANDS_LENGTH][3] = {{3, 0xEF, COMMAND_LEFT_TOP}, 
											{3, 0xBF, COMMAND_LEFT_DOWN}, 
											{3, 0x7F, COMMAND_LEFT_LEFT}, 
											{3, 0xDF, COMMAND_LEFT_RIGHT}, 
											{4, 0xEF, COMMAND_RIGHT_TOP}, 
											{4, 0xBF, COMMAND_RIGHT_DOWN}, 
											{4, 0x7F, COMMAND_RIGHT_LEFT}, 
											{4, 0xDF, COMMAND_RIGHT_RIGHT}};

uchar out[9] = {0, 0, 0, 0xDF, 0xDF, 0, 0, 0, 0};

uint *convert_commands()
{
	uint commands[COMMANDS_LENGTH]; // default is COMMAND_NULL
	for (char i = 0; i < COMMANDS_LENGTH; i++)
	{
		if (out[command_map[i][0]] == command_map[i][1])
		{
			commands[i] = command_map[i][2];
		}
	}
	return commands;
}

void delay() {
    unsigned int i, j;
    for (i=0; i < 100; i++){
        for (j=0; j < 100; j++) {

        }
    }
}

void main(){
    uint *commands = convert_commands();
    for (char i = 0; i < COMMANDS_LENGTH; i++) 
    {
        switch (commands[i])
        {
            case COMMAND_LEFT_TOP:
                P0_0 = 0;
                break;
            case COMMAND_LEFT_DOWN:
                P0_1 = 0;
                break;
            case COMMAND_LEFT_LEFT:
                P0_2 = 0;
                break;
            case COMMAND_LEFT_RIGHT:
                P0_3 = 0;
                break;
            case COMMAND_RIGHT_TOP:
                P0_4 = 0;
                break;
            case COMMAND_RIGHT_RIGHT:
                P0_5 = 0;
                break;
            case COMMAND_RIGHT_LEFT:
                P0_6 = 0;
                break;
            case COMMAND_RIGHT_DOWN:
                P0_7 = 0;
                break;
                

        }

    }

    while(1) {
        
    }
}