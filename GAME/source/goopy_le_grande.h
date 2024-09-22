#include "includes.h"

void GoopyLeGrandeLoadingTexture(){
	GOOPYLEGRANDE.ShootHit = 0;
	GOOPYLEGRANDE.Color = 0xffffffff;
	GOOPYLEGRANDE.Turn = 0;
	GOOPYLEGRANDE.SwitchPoseSlim = 0;
	int f;

for(f=0;f<16;f++){
	LoadingFiles("/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Episode_Ruse_Of_An_Ooze/Goopy_Le_Grande/Phase_1/Jump/", f);
	LoadingPngFile( &GOOPYLEGRANDE.TextureSlimeJump_offset[f], &GOOPYLEGRANDE.TextureSlimeJump[f], buff);
	free(buff);
}

for(f=0;f<5;f++){
	LoadingFiles("/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Episode_Ruse_Of_An_Ooze/Goopy_Le_Grande/Phase_1/Up_Down_Transition/", f);
	LoadingPngFile( &GOOPYLEGRANDE.TextureUpDownTransition_offset[f], &GOOPYLEGRANDE.TextureUpDownTransition[f], buff);
	free(buff);
}	

for(f=0;f<3;f++){
	LoadingFiles("/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Episode_Ruse_Of_An_Ooze/Goopy_Le_Grande/Phase_1/Air_Up/", f);
	LoadingPngFile( &GOOPYLEGRANDE.TextureAirUp_offset[f], &GOOPYLEGRANDE.TextureAirUp[f], buff);
	free(buff);
}	

for(f=0;f<3;f++){
	LoadingFiles("/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Episode_Ruse_Of_An_Ooze/Goopy_Le_Grande/Phase_1/Air_Down/", f);
	LoadingPngFile( &GOOPYLEGRANDE.TextureAirDown_offset[f], &GOOPYLEGRANDE.TextureAirDown[f], buff);
	free(buff);
}

for(f=0;f<20;f++){
	LoadingFiles("/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Episode_Ruse_Of_An_Ooze/Goopy_Le_Grande/Phase_2/Death/", f);
	LoadingPngFile( &GOOPYLEGRANDE.TextureDeadh_offset[f], &GOOPYLEGRANDE.TextureDeadh[f], buff);
	free(buff);
}
}
void GoopyLeGrandeDraw(){
	
if(GamePause == 0){	
	GOOPYLEGRANDE.Counter +=1;
	//Jump
if(GOOPYLEGRANDE.SwitchPoseSlim == 0){	
	GOOPYLEGRANDE.TextureSlime_offset[0] = GOOPYLEGRANDE.TextureSlimeJump_offset[GOOPYLEGRANDE.NumberTextureJump];
	GOOPYLEGRANDE.TextureSlime[0] = GOOPYLEGRANDE.TextureSlimeJump[GOOPYLEGRANDE.NumberTextureJump];
if(GOOPYLEGRANDE.Counter > 3){
		if(GOOPYLEGRANDE.NumberTextureJump > 14) {
			GOOPYLEGRANDE.NumberTextureJump = 0;
			GOOPYLEGRANDE.SwitchPoseSlim = 1;
		}
		GOOPYLEGRANDE.NumberTextureJump += 1;	
	GOOPYLEGRANDE.Counter = 0;
	
}
}

	//Air Up
if(GOOPYLEGRANDE.SwitchPoseSlim == 1){
	GOOPYLEGRANDE.TextureSlime_offset[0] = GOOPYLEGRANDE.TextureAirUp_offset[GOOPYLEGRANDE.NumberTextureAirUp];
	GOOPYLEGRANDE.TextureSlime[0] = GOOPYLEGRANDE.TextureAirUp[GOOPYLEGRANDE.NumberTextureAirUp];

if(GOOPYLEGRANDE.Counter > 3){
		if(GOOPYLEGRANDE.NumberTextureAirUp > 1) {
			GOOPYLEGRANDE.NumberTextureAirUp = 0;
		}
		GOOPYLEGRANDE.NumberTextureAirUp += 1;
	GOOPYLEGRANDE.Counter = 0;
	
}
}	
	//Up Down Transition
if(GOOPYLEGRANDE.SwitchPoseSlim == 2){
	GOOPYLEGRANDE.TextureSlime_offset[0] = GOOPYLEGRANDE.TextureUpDownTransition_offset[GOOPYLEGRANDE.NumberTextureUpDownTransition];
	GOOPYLEGRANDE.TextureSlime[0] = GOOPYLEGRANDE.TextureUpDownTransition[GOOPYLEGRANDE.NumberTextureUpDownTransition];

if(GOOPYLEGRANDE.Counter > 3){
		if(GOOPYLEGRANDE.NumberTextureUpDownTransition > 3) {
			GOOPYLEGRANDE.SwitchPoseSlim = 3;
			GOOPYLEGRANDE.NumberTextureUpDownTransition = 0;
		}
		GOOPYLEGRANDE.NumberTextureUpDownTransition += 1;
	GOOPYLEGRANDE.Counter = 0;
	
}
}
	//Air_Down
if(GOOPYLEGRANDE.SwitchPoseSlim == 3){
	GOOPYLEGRANDE.TextureSlime_offset[0] = GOOPYLEGRANDE.TextureAirDown_offset[GOOPYLEGRANDE.NumberTextureAirDown];
	GOOPYLEGRANDE.TextureSlime[0] = GOOPYLEGRANDE.TextureAirDown[GOOPYLEGRANDE.NumberTextureAirDown];

if(GOOPYLEGRANDE.Counter > 3){
		if(GOOPYLEGRANDE.NumberTextureAirDown > 1) {
			GOOPYLEGRANDE.NumberTextureAirDown = 0;
		}
		GOOPYLEGRANDE.NumberTextureAirDown += 1;
	GOOPYLEGRANDE.Counter = 0;
	
}
}

if(GOOPYLEGRANDE.SwitchPoseSlim == 9){
	GOOPYLEGRANDE.TextureSlime_offset[0] = GOOPYLEGRANDE.TextureDeadh_offset[GOOPYLEGRANDE.NumberTextureDeadh];
	GOOPYLEGRANDE.TextureSlime[0] = GOOPYLEGRANDE.TextureDeadh[GOOPYLEGRANDE.NumberTextureDeadh];

if(GOOPYLEGRANDE.Counter > 3){
		if(GOOPYLEGRANDE.NumberTextureDeadh > 18) {
			GOOPYLEGRANDE.NumberTextureDeadh = 0;
		}
		GOOPYLEGRANDE.NumberTextureDeadh += 1;
	GOOPYLEGRANDE.Counter = 0;
	
}
}






	if(GOOPYLEGRANDE.PositionY > CUPHEAD.PositionY - 60 && GOOPYLEGRANDE.PositionY < CUPHEAD.PositionY + 60 && GOOPYLEGRANDE.PositionX > CUPHEAD.PositionX - 60 && GOOPYLEGRANDE.PositionX < CUPHEAD.PositionX + 60){
		if(CUPHEADHEALTPOINTS.SwitchStop == 0){
		CUPHEADHEALTPOINTS.Switch -= 1;
		CUPHEAD.Color = 0x555555ff;
		}
		CUPHEADHEALTPOINTS.SwitchStop = 1;
	}else{
		CUPHEADHEALTPOINTS.SwitchStop = 0;
	}

GOOPYLEGRANDE.Color = 0xffffffff;
if(PEASHOOTER[0].SwitchEnemy == 0){
	if(PEASHOOTER[0].PositionY > GOOPYLEGRANDE.PositionY - 60 && PEASHOOTER[0].PositionY < GOOPYLEGRANDE.PositionY + 60 && PEASHOOTER[0].PositionX > GOOPYLEGRANDE.PositionX - 60 && PEASHOOTER[0].PositionX < GOOPYLEGRANDE.PositionX + 60){
		PEASHOOTER[0].Switch = 0;
		PEASHOOTER[0].SwitchPose = 0;
		GOOPYLEGRANDE.Color = 0x555555ff;
		GOOPYLEGRANDE.ShootHit +=1;
	}
	PEASHOOTER[0].SwitchEnemy = 1;	
}
if(GOOPYLEGRANDE.ShootHit == 100){
	GOOPYLEGRANDE.SwitchPoseSlim = 9;
}





if(GOOPYLEGRANDE.NumberTextureJump == 14)GOOPYLEGRANDE.SwitchJump = 0;
	if(GOOPYLEGRANDE.SwitchJump == 0){
//		
		if(GOOPYLEGRANDE.PositionY <= 0) GOOPYLEGRANDE.SwitchMoveY =  3, GOOPYLEGRANDE.Turn = 1;
		if(GOOPYLEGRANDE.PositionY >= 840) GOOPYLEGRANDE.SwitchMoveY = -3, GOOPYLEGRANDE.Turn = 0;
		GOOPYLEGRANDE.PositionY += GOOPYLEGRANDE.SwitchMoveY;
//		
		GOOPYLEGRANDE.PositionX -= GOOPYLEGRANDE.FizicJump;
		GOOPYLEGRANDE.FizicJump = GOOPYLEGRANDE.FizicJump - 0.2;
	}
//
if(GOOPYLEGRANDE.FizicJump < 1){
	if(GOOPYLEGRANDE.SwitchPoseSlim == 1){
		GOOPYLEGRANDE.SwitchPoseSlim = 2;
	}
}
//	
if(GOOPYLEGRANDE.FizicJump < 0){
	if(GOOPYLEGRANDE.PositionX >= GOOPYLEGRANDE.Ground){
		GOOPYLEGRANDE.FizicJump = 8;
		GOOPYLEGRANDE.SwitchJump = 1;
		GOOPYLEGRANDE.SwitchPoseSlim = 0;
	}
}



}
DrawMatrix( &GOOPYLEGRANDE.TextureSlime_offset[0], &GOOPYLEGRANDE.TextureSlime[0], 130.0, 130.0, GOOPYLEGRANDE.PositionY + RUSEOFANOOZE.Position_01Y, GOOPYLEGRANDE.PositionX, 0, 0, GOOPYLEGRANDE.Turn, GOOPYLEGRANDE.Color);
}