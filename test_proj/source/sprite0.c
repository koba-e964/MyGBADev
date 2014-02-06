#include <gba_video.h>
#include <gba_sprites.h>


#include <gba_console.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>



#include "./sprite0.h"
#include "./sprite_common.h"
#include "./spr.h"
//---------------------------------------------------------------------------
void drawSprite0()
{
	SpriteSetSize(0/*::SpriteID*/, OBJ_SIZE(1), OBJ_SQUARE, OBJ_256_COLOR);
	SpriteSetChr (0, 0);
	SpriteMove   (0, 20/*::XCoord*/, 20/*::YCoord*/);


	SpriteSetSize(1/*::SpriteID*/, OBJ_SIZE(1), OBJ_SQUARE, OBJ_256_COLOR);
	SpriteSetChr (1, 8);
	SpriteMove   (1, 20/*::XCoord*/, 20/*::YCoord*/);

}
