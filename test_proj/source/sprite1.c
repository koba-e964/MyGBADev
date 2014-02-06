#include "sprite1.h"
#include "sprite0.h"
#include <gba_video.h>
#include  <gba_sprites.h>

char testSprite1[256]=
"..*..........*.." //0
".*............*."
"*..*........*..*"
"*...*......*...*"
"*....*....*....*"
"*...*......*...*"
".*.*........*.*."
"..*..******..*.."
"................" //8
"................"
"................"
"................"
"................" //12
"................"
"................"
"................";

void setTestSprite1(){
	u16 *oba=(char*)OBJ_BASE_ADR;
	int i,j,k;
	for(k=0;k<2;k++){
		for(i=0;i<8;i++){
			for(j=0;j<8;j+=2){
				int t0=testSprite1[i*16+j+k*8]=='*'?0/*black*/ : 3/*white*/;
				int t1=testSprite1[i*16+j+1+k*8]=='*'?0/*black*/ : 3/*white*/;
				oba[0x20*k+(i*8+j)/2]=t0|t1<<8; //Data must be written as 16-bit value, but I do NOT know why.
			}
		}
	}
}

