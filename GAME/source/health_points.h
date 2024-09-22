#include "includes.h"

void HealthPointsLoadingTexture(){
	int f;

for(f=0;f<8;f++){
	LoadingFiles("/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Health_Points/", f);
	LoadingPngFile( &CUPHEADHEALTPOINTS.TextureHealthPointsNumber_offset[f], &CUPHEADHEALTPOINTS.TextureHealthPointsNumber[f], buff);
	free(buff);
}
LoadingPngFile( &CUPHEADHEALTPOINTS.TextureHealthPointsDead_offset[0], &CUPHEADHEALTPOINTS.TextureHealthPointsDead[0], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Health_Points/dead.png");
}

void HealthPointsDraw(){
	
if(GamePause == 0){
if(CUPHEADHEALTPOINTS.Switch == 0){
	CUPHEADHEALTPOINTS.TextureHealthPoints_offset[0] = CUPHEADHEALTPOINTS.TextureHealthPointsDead_offset[0];
	CUPHEADHEALTPOINTS.TextureHealthPoints[0] = CUPHEADHEALTPOINTS.TextureHealthPointsDead[0];
}	
if(CUPHEADHEALTPOINTS.Switch == 1){
	CUPHEADHEALTPOINTS.TextureHealthPoints_offset[0] = CUPHEADHEALTPOINTS.TextureHealthPointsNumber_offset[0];
	CUPHEADHEALTPOINTS.TextureHealthPoints[0] = CUPHEADHEALTPOINTS.TextureHealthPointsNumber[0];
}	
if(CUPHEADHEALTPOINTS.Switch == 2){
	CUPHEADHEALTPOINTS.TextureHealthPoints_offset[0] = CUPHEADHEALTPOINTS.TextureHealthPointsNumber_offset[1];
	CUPHEADHEALTPOINTS.TextureHealthPoints[0] = CUPHEADHEALTPOINTS.TextureHealthPointsNumber[1];
}	
if(CUPHEADHEALTPOINTS.Switch == 3){
	CUPHEADHEALTPOINTS.TextureHealthPoints_offset[0] = CUPHEADHEALTPOINTS.TextureHealthPointsNumber_offset[2];
	CUPHEADHEALTPOINTS.TextureHealthPoints[0] = CUPHEADHEALTPOINTS.TextureHealthPointsNumber[2];
}
if(CUPHEADHEALTPOINTS.Switch == 4){
	CUPHEADHEALTPOINTS.TextureHealthPoints_offset[0] = CUPHEADHEALTPOINTS.TextureHealthPointsNumber_offset[3];
	CUPHEADHEALTPOINTS.TextureHealthPoints[0] = CUPHEADHEALTPOINTS.TextureHealthPointsNumber[3];
}

if(CUPHEADHEALTPOINTS.Switch <= 0)CUPHEADHEALTPOINTS.Switch = 0;
if(CUPHEADHEALTPOINTS.Switch >= 8)CUPHEADHEALTPOINTS.Switch = 8;
}
DrawMatrix( &CUPHEADHEALTPOINTS.TextureHealthPoints_offset[0], &CUPHEADHEALTPOINTS.TextureHealthPoints[0], 70.0, 30.0, 40, 480, 0, 0, 0, 0xffffffff);

}