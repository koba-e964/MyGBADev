#include "sprite1.h"
#include "sprite_common.h"
#include <gba_video.h>
#include  <gba_sprites.h>

/*16x16, (>_<)*/
char testSprite1_1[256]=
"..*..........*.." //0
".*............*."
"*..**......**..*"
"*....*....*....*"
"*....**..**....*"
"*..**......**..*"
".*............*."
"..*..******..*.."
"................" //8
"................"
"................"
"................"
"................" //12
"................"
"................"
"................";

/*16x16, =>*/
char testSprite1_2[256]=
"................" //0
"........***....." 
".........**....."
"...........**..." 
"...........**..."
"**************.." 
"**************.."
"..............*."
"..............*." //8
"**************.."
"**************.."
"...........**..."
"...........**..." //12
".........**....."
"........***....."
"................";

/*
	Array Int Char->CharId->IO()
*/
void setSprite16x16(char* font,int charId){
	u16 *oba;
	charId&=0x1f8;//multiple of 8
	oba=(u16*)((char*)OBJ_BASE_ADR+0x20*charId);
	int i,j,k;
	for(k=0;k<4;k++){
		for(i=0;i<8;i++){
			for(j=0;j<8;j+=2){
				int ind=(i+8*(k/2))*16 + j+(k%2)*8;
				int t0=font[ind]!='*'?0/*black*/ : 3/*white*/;
				int t1=font[ind+1]!='*'?0/*black*/ : 3/*white*/;
				oba[0x20*k+(i*8+j)/2]=t0|t1<<8; //Data must be written as 16-bit value, but I do NOT know why.
			}
		}
	}
}

void setTestSprite1(){
	SpriteSetSize(0/*::SpriteID*/, OBJ_SIZE(1), OBJ_SQUARE, OBJ_256_COLOR);
	SpriteSetChr (0, 0);
	SpriteMove   (0, 20/*::XCoord*/, 20/*::YCoord*/);


	SpriteSetSize(1/*::SpriteID*/, OBJ_SIZE(1), OBJ_SQUARE, OBJ_256_COLOR);
	SpriteSetChr (1, 8);
	SpriteMove   (1, 20/*::XCoord*/, 20/*::YCoord*/);
	setSprite16x16(testSprite1_1,0);
	setSprite16x16(testSprite1_2,8);
}

