/*
	Reference: http://akkera102.sakura.ne.jp/gbadev/index.php?Step.4%20%A5%BF%A5%A4%A5%EB%A5%E2%A1%BC%A5%C9%281%29
*/

#include <gba_video.h>
#include <gba_input.h>


/*
	CharId : [0,15]
	CharTable = Array Int (ColorId, ColorId)
	ColorId : [0,255]
	Color ::[0,0x7fff]
*/
/*
	fillBox :: CharTable->CharId->ColorId->IO ()
*/
void fillBox(u16* chr /*CharTable*/,int chid/*CharId*/,u8 colid/*ColorId*/){//256 colors
	int i,s;
	//char chid
	for(s=32*chid+32,i=s-32; i<s; i++)
	{
		chr[i] = colid + (colid<<8);
	}
}

void drawTile0(void){
	SetMode(MODE_0 | BG0_ENABLE);
	REG_BG0CNT = (BG_SIZE_0 | BG_256_COLOR | CHAR_BASE(0) | MAP_BASE(28)); 

	u16* pal = BG_PALETTE;		// palette, pal :: Array ColorId Color
	u16* chr = CHAR_BASE_ADR(0);	// char-base :: CharTable = Array Int (ColorId, ColorId)
	u16* map = MAP_BASE_ADR(28);	// map :: Array Int CharId
	
	int blk=2; // :: ColorId
	int red=1; // :: ColorId
	pal[blk] = RGB5(17,17,17); // :: Color
	pal[red] = RGB5(31, 0, 0); // :: Color

	
	//char 2
	fillBox(chr, 2, blk);

	//char 1
	fillBox(chr, 1, red);
	
	//setting map
	u16 x = 5; // DisplayIndex
	u16 y = 5; // DisplayIndex

	map[y*32+x] = 1;//char 1, :: CharId
	map[y*32+x+1] = 2;//char 2 :: CharId
}

