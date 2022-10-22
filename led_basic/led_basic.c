#include <mcs51/8051.h>

void delayms(unsigned int xms)
{
	unsigned int i, j;
	for (i = xms; i > 0; i--)
		for (j = 70; j > 0; j--)
			;
}

void main(){
    while(1) {
        P0 = 0;
        P0_0 = 0;
        delayms(1000);
        P0_0 = 1;
        delayms(1000);
    }
}