#include "includes.h"

void AmmoLoadingTexture(){
	int f;

for(f=0;f<4;f++){
	LoadingFiles("/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Ammo/Peashooter_ex/", f);
	LoadingPngFile( &PEASHOOTER[0].TexturePeashooter_ex_offset[f], &PEASHOOTER[0].TexturePeashooter_ex[f], buff);
	free(buff);
}
}

void AmmoDraw(){
	
if(GamePause == 0){
	
	PEASHOOTER[0].Counter++;	
	if(PEASHOOTER[0].SwitchTexture == 0){
		PEASHOOTER[0].TextureShoots_offset[0] = PEASHOOTER[0].TexturePeashooter_ex_offset[PEASHOOTER[0].NumberTexturePeashooter_ex];
		PEASHOOTER[0].TextureShoots[0] = PEASHOOTER[0].TexturePeashooter_ex[PEASHOOTER[0].NumberTexturePeashooter_ex];
		if(PEASHOOTER[0].Counter > 3){
			if(PEASHOOTER[0].NumberTexturePeashooter_ex > 2)PEASHOOTER[0].NumberTexturePeashooter_ex = 0;
			PEASHOOTER[0].NumberTexturePeashooter_ex += 1;
		PEASHOOTER[0].Counter = 0;			
		}
	}
//
	if(PEASHOOTER[0].Switch == 1){
		if( PEASHOOTER[0].SwitchPose == 0){
			PEASHOOTER[0].PositionY = CUPHEAD.PositionY;
			PEASHOOTER[0].PositionX = CUPHEAD.PositionX;
		if( CUPHEAD.Turn == 0){
			PEASHOOTER[0].TurnTmp = 0;
		}
		if( CUPHEAD.Turn == 1){
			PEASHOOTER[0].TurnTmp = 1;
		}
		if(PEASHOOTER[0].ButtonUp == 1){
			PEASHOOTER[0].TurnTmp = 3;
		}
		if(PEASHOOTER[0].ButtonUp == 1 && PEASHOOTER[0].ButtonLeft == 1){
			PEASHOOTER[0].TurnTmp = 4;
		}		
		if(PEASHOOTER[0].ButtonUp == 1 && PEASHOOTER[0].ButtonRight == 1){
			PEASHOOTER[0].TurnTmp = 5;
		}		
	}
		if(PEASHOOTER[0].TurnTmp == 5){
			PEASHOOTER[0].PositionX -= 15;
			PEASHOOTER[0].PositionY += 20;
			PEASHOOTER[0].TextureTurnOver = 7;
			PEASHOOTER[0].Turn = 0;
		}
		if(PEASHOOTER[0].TurnTmp == 4){
			PEASHOOTER[0].PositionX -= 15;
			PEASHOOTER[0].PositionY -= 20;
			PEASHOOTER[0].TextureTurnOver = 9;
			PEASHOOTER[0].Turn = 0;
		}
		if(PEASHOOTER[0].TurnTmp == 3){
			PEASHOOTER[0].PositionX -= 15;
			PEASHOOTER[0].TextureTurnOver = 8;
			PEASHOOTER[0].Turn = 0;
		}
		if( PEASHOOTER[0].TurnTmp == 0){
			PEASHOOTER[0].PositionY += 20;
			PEASHOOTER[0].TextureTurnOver = 0;
			PEASHOOTER[0].Turn = 0;
		}
		if( PEASHOOTER[0].TurnTmp == 1){
			PEASHOOTER[0].PositionY -= 20;
			PEASHOOTER[0].TextureTurnOver = 0;
			PEASHOOTER[0].Turn = 1;
		}
		PEASHOOTER[0].SwitchPose = 1;

//
	DrawMatrix( &PEASHOOTER[0].TextureShoots_offset[0], &PEASHOOTER[0].TextureShoots[0], 60.0, 30.0, PEASHOOTER[0].PositionY, PEASHOOTER[0].PositionX, PEASHOOTER[0].TextureTurnOver, 0, PEASHOOTER[0].Turn, 0xffffffff);

//
		PEASHOOTER[0].SwitchEnemy = 0;
	}	
	
	if( PEASHOOTER[0].PositionY > 840){
		PEASHOOTER[0].SwitchPose = 0;
		PEASHOOTER[0].Switch = 0;
	}
	if( PEASHOOTER[0].PositionY < 0){
		PEASHOOTER[0].SwitchPose = 0;
		PEASHOOTER[0].Switch = 0;
	}
	if(PEASHOOTER[0].PositionX < 10){
		PEASHOOTER[0].SwitchPose = 0;
		PEASHOOTER[0].Switch = 0;
	}
	
}
//

}