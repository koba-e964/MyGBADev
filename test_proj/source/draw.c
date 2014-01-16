#include "./draw.h"


void WaitForVsync(void){
	while (*(volatile u16*)0x4000006 >= 160) {};
	while (*(volatile u16*)0x4000006 <  160) {};
}

void Mode3PutPixel(u16 x, u16 y, u16 col){
	u16* ScreenBuffer     = (u16*)0x6000000;
	ScreenBuffer[y*240+x] = col;
}
