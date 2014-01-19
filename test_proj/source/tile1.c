#include <gba_video.h>
#include "tile1.h"
#include "pic.h"

void drawTile1(void){
	SetMode(MODE_0 | BG0_ENABLE);

	REG_BG0CNT = (BG_SIZE_0 | BG_256_COLOR | CHAR_BASE(0) | MAP_BASE(28)); 

	u16* pal = BG_PALETTE;		// BG
	u16* chr = CHAR_BASE_ADR(0);	// 
	u16* map = MAP_BASE_ADR(28);	// 

	u16 i;

	for(i=0; i<256; i++)
	{
		pal[i] = picPal[i];
	}
	for(i=0; i<(240*160)/2; i++)
	{
		chr[i] = picTiles[i];
	}

	i = 0;
	u16 x, y;
	for(y=0; y<20; y++)
	{
		for(x=0; x<30; x++)
		{
			map[y*32+x] = i++;
		}
	}
}
