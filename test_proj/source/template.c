
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
	int moving=0,bx=0;
	volatile int oldkey=~REG_KEYINPUT; //all flags are inverted. low-active -> high-active
	while (1) {
		volatile int key=~REG_KEYINPUT; //all flags are inverted. low-active -> high-active
		volatile int pushed=~oldkey&key;//0->1 (high-active)
		volatile int released=oldkey&~key;
		oldkey=key;
		if(key&KEY_RIGHT){
			x++;
		}
		if(key&KEY_LEFT){
			x--;
		}
		if(key&KEY_UP){
			y--;
		}
		if(key&KEY_DOWN){
			y++;
		}
		if(pushed&KEY_A){
			moving=1-moving;
		}
		SpriteMove(0/*::SpriteId*/,x,y);
		SpriteMove(1/*::SpriteId*/,bx,y);
		if(moving)bx++;
		WaitForVsync();
	}
}


