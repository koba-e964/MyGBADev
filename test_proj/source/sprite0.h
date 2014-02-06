#ifndef SPRITE0_H_sn302
#define SPRITE0_H_sn302
#include <gba_video.h> //RGB

/*
	type RGB15 : [0,0x7fff]
	type ColorID : [0,15]
	type XCoord : [0,511]
	type YCoord : [0,255]
	type SpriteID : ?
	type ColorMode : 0 or 1<<13
	type ShapeMode : [0,2] <<14
	type SizeMode  : [0,3] <<14
	type CharID : [0,63] <<3
*/


/*
	RGB15s
	reference: http://www.netyasun.com/home/color.html
*/
#define RGB15_BLACK RGB5(0,0,0)
#define RGB15_GRAY RGB5(16,16,16)
#define RGB15_SILVER RGB5(24,24,24)
#define RGB15_WHITE RGB5(31,31,31)
#define RGB15_BLUE RGB5(0,0,31)
#define RGB15_NAVY RGB5(0,0,16)
#define RGB15_TEAL RGB5(0,16,16)
#define RGB15_GREEN RGB5(0,16,0)
#define RGB15_LIME RGB5(0,31,0)
#define RGB15_AQUA RGB5(0,31,31)
#define RGB15_YELLOW RGB5(31,31,0)
#define RGB15_RED RGB5(31,0,0)
#define RGB15_FUCHSIA RGB5(31,0,31)
#define RGB15_OLIVE RGB5(16,16,0)
#define RGB15_PURPLE RGB5(16,0,16)
#define RGB15_MALOON RGB5(16,0,0)
/**
	SpriteMove :: SpriteID->XCoord->YCoord->IO ()
*/
void SpriteMove(u16 num, s16 x, s16 y);
/*
	SpriteSetSize :: SpriteID->SizeMode->ShapeMode->ColorMode->IO ()
*/
void SpriteSetSize(u16 num, u16 size, u16 form, u16 col);
/*
	SpriteSetChr :: SpriteID -> CharID ->IO()
*/
void SpriteSetChr(u16 num, u16 ch);
void drawSprite0(void);
#endif

