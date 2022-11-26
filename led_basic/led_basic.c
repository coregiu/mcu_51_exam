#include <mcs51/8051.h>

void delayms(unsigned int xms)
{
	unsigned int i, j;
	for (i = xms; i > 0; i--)
		for (j = 70; j > 0; j--)
			;
}

void main(){
    P2_0 = 1;
    P2_1 = 1;
    P2_2 = 0;

    P2_3 = 1;
    P2_4 = 1;
    P2_5 = 0;
    while(1) {
    }
}