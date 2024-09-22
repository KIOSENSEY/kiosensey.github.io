#include "includes.h"

void EpisodeForestFolliesLoadingTexture(){
	CUPHEAD.Color = 0xffffffff;
	CUPHEAD.PositionY = 201;
	CUPHEAD.PositionX = 400;
	CUPHEAD.SwitchPose = 0;
	CUPHEAD.Turn = 0;
	CUPHEAD.FizicJump = 9;
	FORESTFOLLIES.WorldPosition = 0;
	CUPHEADHEALTPOINTS.Switch = 3;


	MUGMAN.Color = 0xffffffff;
	MUGMAN.PositionY = 261;
	MUGMAN.PositionX = 400;
	MUGMAN.SwitchPose = 0;
	MUGMAN.Turn = 0;
	MUGMAN.FizicJump = 9;
	
	FORESTFOLLIES.Position_01Y = 0;
	FORESTFOLLIES.Position_02Y = 0;

LoadingPngFile( &FORESTFOLLIES.TextureBackground_offset[0], &FORESTFOLLIES.TextureBackground[0], "/dev_hdd0/game/KIOSENSEY/USRDIR/sprites/forest_follies/forest/platform_001.png");
LoadingPngFile( &FORESTFOLLIES.TextureBackground_offset[1], &FORESTFOLLIES.TextureBackground[1], "/dev_hdd0/game/KIOSENSEY/USRDIR/sprites/forest_follies/forest/bg_forest_004.png");
LoadingPngFile( &FORESTFOLLIES.TextureBackground_offset[2], &FORESTFOLLIES.TextureBackground[2], "/dev_hdd0/game/KIOSENSEY/USRDIR/sprites/forest_follies/forest/sky_001.png");


LoadingPngFile( &FORESTFOLLIES.TextureBackground_offset[5], &FORESTFOLLIES.TextureBackground[5], "/dev_hdd0/game/KIOSENSEY/USRDIR/sprites/forest_follies/forest/stump_001.png");

}

void EpisodeForestFolliesDraw(){
DrawMatrix( &FORESTFOLLIES.TextureBackground_offset[2], &FORESTFOLLIES.TextureBackground[2], 920.0, 400.0, 420, 140,0, 0, 0, 0xffffffff);
DrawMatrix( &FORESTFOLLIES.TextureBackground_offset[1], &FORESTFOLLIES.TextureBackground[1], 900.0, 500.0, FORESTFOLLIES.Position_02Y + 1000, 100, 0, 0, 0, 0xffffffff);
DrawMatrix( &FORESTFOLLIES.TextureBackground_offset[0], &FORESTFOLLIES.TextureBackground[0], 2100.0, 200.0, FORESTFOLLIES.Position_01Y + 1000, 420, 0, 0, 0, 0xffffffff);//Platform
DrawMatrix( &FORESTFOLLIES.TextureBackground_offset[0], &FORESTFOLLIES.TextureBackground[0], 2100.0, 200.0, FORESTFOLLIES.Position_01Y + 3100, 420, 0, 0, 0, 0xffffffff);//Platform

DrawMatrix( &FORESTFOLLIES.TextureBackground_offset[5], &FORESTFOLLIES.TextureBackground[5], 220.0, 100.0, FORESTFOLLIES.Position_01Y + 2000, 410, 0, 0, 0, 0xffffffff);



if(CUPHEAD.PositionY > 400){
	CUPHEAD.PositionY = 400;
	FORESTFOLLIES.WorldPosition += 1;
	FORESTFOLLIES.Position_01Y -= 5;
	FORESTFOLLIES.Position_02Y -= 4;
}

if(FORESTFOLLIES.WorldPosition <= 0){
	FORESTFOLLIES.WorldPosition = 0;
	FORESTFOLLIES.Position_01Y = 0;
	FORESTFOLLIES.Position_02Y = 0;
}else{
	if(CUPHEAD.PositionY < 400){
	CUPHEAD.PositionY = 400;
	FORESTFOLLIES.WorldPosition -= 1;
	FORESTFOLLIES.Position_01Y += 5;
	FORESTFOLLIES.Position_02Y += 4;
}
}

}