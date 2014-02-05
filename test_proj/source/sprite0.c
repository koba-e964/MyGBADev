#include <gba_video.h>
#include <gba_sprites.h>


#include <gba_console.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>



#include "./sprite0.h"
#include "./draw.h"
#include "./spr.h"
/**
	Reference: http://akkera102.sakura.ne.jp/gbadev/index.php?Step.7%20%A5%B9%A5%D7%A5%E9%A5%A4%A5%C8(1)
*/

/*
		type XCoord : [0,511]
		type YCoord : [0,255]
		type SpriteID : ?
*/

/**
	SpriteMove :: SpriteID->XCoord->YCoord->IO ()
*/
void SpriteMove(u16 num, s16 x, s16 y)
{
	OBJATTR* sp = (OBJATTR*)OAM + num;
	x&=0x01ff;
	y&=0x00ff;

	sp->attr1 &= 0xfe00;
	sp->attr0 &= 0xff00;
	sp->attr1 |= (x & 0x01ff);
	sp->attr0 |= (y & 0x00ff);
}
// SpriteSetSize :: SpriteID->Int->?->ColorID->IO ()
void SpriteSetSize(u16 num, u16 size, u16 form, u16 col)
{
	OBJATTR* sp = (OBJATTR*)OAM + num;

	sp->attr0 &= 0x1fff;
	sp->attr1 &= 0x3fff;
	sp->attr0 |= col  | form | (160);
	sp->attr1 |= size | (240);
}
// SpriteSetChr :: SpriteID -> ? ->IO()
void SpriteSetChr(u16 num, u16 ch)
{
	OBJATTR* sp = (OBJATTR*)OAM + num;

	sp->attr2 &= 0xfc00;
	sp->attr2 |= ch;
}
// ()->IO()
void SpriteInit()
{
	u16 i;
	for(i=0; i<128; i++)
	{
		SpriteMove(i, 240, 160);
	}
}
//---------------------------------------------------------------------------
void drawSprite0()
{
	SetMode(MODE_0 | OBJ_ENABLE | OBJ_1D_MAP);//not OBJ_2D_MAP , which is not existent.

	u16* oam = OBJ_BASE_ADR;	// sprite data 
	u16* pal = OBJ_COLORS;		// sprite palette
	u16 i;

	for(i=0; i<sprTilesLen/2; i++)
	{
		oam[i] = sprTiles[i];
	}
	int cols[]={
		RGB15_BLACK,
		RGB15_GRAY,
		RGB15_SILVER,
		RGB15_WHITE,
		RGB15_BLUE ,
		RGB15_NAVY ,
		RGB15_TEAL ,
		RGB15_GREEN ,
		RGB15_LIME ,
		RGB15_AQUA ,
		RGB15_YELLOW ,
		RGB15_RED ,
		RGB15_FUCHSIA ,
		RGB15_OLIVE ,
		RGB15_PURPLE ,
		RGB15_MALOON ,
	};
	for(i=0;i<16;i++){
		pal[i]=cols[i];
	}

	SpriteInit();

	SpriteSetSize(0/*::SpriteID*/, OBJ_SIZE(1), OBJ_SQUARE, OBJ_16_COLOR);
	SpriteSetChr (0, 2);
	SpriteMove   (0, 20/*::XCoord*/, 20/*::YCoord*/);


	SpriteSetSize(1/*::SpriteID*/, OBJ_SIZE(1), OBJ_SQUARE, OBJ_16_COLOR);
	SpriteSetChr (1, 2);
	SpriteMove   (1, 20/*::XCoord*/, 20/*::YCoord*/);

}
