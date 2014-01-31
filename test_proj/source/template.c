
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <gba_sprites.h>
#include <stdio.h>
#include <stdlib.h>

#include "./draw.h"
#include "./tile1.h"
#include "./sprite0.h"


//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------


	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	// since the default dispatcher handles the bios flags no vblank handler
	// is required
	irqInit();
	irqEnable(IRQ_VBLANK);
	
	//drawTile1();
	drawSprite0();
	int x=20,y=20; //::XCoord, ::YCoord
	while (1) {
		volatile int key=REG_KEYINPUT;
		if(key&KEY_RIGHT){
			x--;
		}
		if(key&KEY_LEFT){
			x++;
		}
		if(key&KEY_UP){
			y++;
		}
		if(key&KEY_DOWN){
			y--;
		}
		SpriteMove(0/*::SpriteId*/,x,y);
		WaitForVsync();
	}
}


