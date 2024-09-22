#include "includes.h"

void EpisodeRuse0fAnOozeLoading(){
	Ground = 400;
	GOOPYLEGRANDE.PositionY = 620;
	GOOPYLEGRANDE.PositionX = 390;
	GOOPYLEGRANDE.Ground = 390;
	GOOPYLEGRANDE.SwitchMoveY = -3;
	CUPHEADHEALTPOINTS.Switch = 3;
	
	CUPHEAD.Color = 0xffffffff;
	CUPHEAD.PositionY = 201;
	CUPHEAD.PositionX = 400;
	CUPHEAD.SwitchPose = 0;
	CUPHEAD.Turn = 0;
	CUPHEAD.FizicJump = 9;
	
	MUGMAN.Color = 0xffffffff;
	MUGMAN.PositionY = 261;
	MUGMAN.PositionX = 400;
	MUGMAN.SwitchPose = 0;
	MUGMAN.Turn = 0;
	MUGMAN.FizicJump = 9;

LoadingPngFile( &RUSEOFANOOZE.TextureBackground_offset[0], &RUSEOFANOOZE.TextureBackground[0], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Episode_Ruse_Of_An_Ooze/Forest/slime_bg_mg_main_ground.png");
LoadingPngFile( &RUSEOFANOOZE.TextureBackground_offset[1], &RUSEOFANOOZE.TextureBackground[1], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Episode_Ruse_Of_An_Ooze/Forest/slime_bg_bg_forest.png");
LoadingPngFile( &RUSEOFANOOZE.TextureBackground_offset[2], &RUSEOFANOOZE.TextureBackground[2], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Episode_Ruse_Of_An_Ooze/Forest/slime_bg_bg_far_forest.png");

}

void EpisodeRuse0fAnOozeDraw(){
if(GamePause == 0){
if(CUPHEAD.PositionY > 200 && CUPHEAD.PositionY < 640){
	RUSEOFANOOZE.Position_01Y = 0;
	RUSEOFANOOZE.Position_02Y = 0;
}

}
//
DrawMatrix( &RUSEOFANOOZE.TextureBackground_offset[2], &RUSEOFANOOZE.TextureBackground[2], 900.0, 350.0, 410, 170, 0, 0, 0, 0xffffffff);	
DrawMatrix( &RUSEOFANOOZE.TextureBackground_offset[1], &RUSEOFANOOZE.TextureBackground[1], 920.0, 350.0, 420 + RUSEOFANOOZE.Position_02Y, 170, 0, 0, 0, 0xffffffff);
DrawMatrix( &RUSEOFANOOZE.TextureBackground_offset[0], &RUSEOFANOOZE.TextureBackground[0], 960.0, 600.0, 420 + RUSEOFANOOZE.Position_01Y, 270, 0, 0, 0, 0xffffffff);

}
