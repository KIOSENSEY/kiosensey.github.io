#include "includes.h"
	
void MugmanLoadingTexture(){

	int f;
	//Idle
for(f=0;f<5;f++){
	LoadingFiles("/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Mugman/Idle/", f);
	LoadingPngFile( &MUGMAN.TextureIdle_offset[f], &MUGMAN.TextureIdle[f], buff);
	free(buff);
}

	//Run Normal
for(f=0;f<16;f++){
	LoadingFiles("/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Mugman/Run/Normal/", f);
	LoadingPngFile( &MUGMAN.TextureRunNormal_offset[f], &MUGMAN.TextureRunNormal[f], buff);
	free(buff);
}

	//Jump
for(f=0;f<8;f++){
	LoadingFiles("/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Mugman/Jump/", f);
	LoadingPngFile( &MUGMAN.TextureJump_offset[f], &MUGMAN.TextureJump[f], buff);
	free(buff);
}

	//Shoot Straight
LoadingPngFile( &MUGMAN.TextureShootStraight_offset[0], &MUGMAN.TextureShootStraight[0], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/shoot/straight/cuphead_shoot_straight_001.png");//
LoadingPngFile( &MUGMAN.TextureShootStraight_offset[1], &MUGMAN.TextureShootStraight[1], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/shoot/straight/cuphead_shoot_straight_002.png");//
LoadingPngFile( &MUGMAN.TextureShootStraight_offset[2], &MUGMAN.TextureShootStraight[2], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/shoot/straight/cuphead_shoot_straight_003.png");//
	//Duck Idle
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[0], &MUGMAN.TextureDuckIdle[0], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_001.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[1], &MUGMAN.TextureDuckIdle[1], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_002.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[2], &MUGMAN.TextureDuckIdle[2], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_003.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[3], &MUGMAN.TextureDuckIdle[3], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_004.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[4], &MUGMAN.TextureDuckIdle[4], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_005.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[5], &MUGMAN.TextureDuckIdle[5], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_006.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[6], &MUGMAN.TextureDuckIdle[6], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_007.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[7], &MUGMAN.TextureDuckIdle[7], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_008.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[8], &MUGMAN.TextureDuckIdle[8], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_009.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[9], &MUGMAN.TextureDuckIdle[9], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_010.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[10], &MUGMAN.TextureDuckIdle[10], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_011.png");
LoadingPngFile( &MUGMAN.TextureDuckIdle_offset[11], &MUGMAN.TextureDuckIdle[11], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/idle/cuphead_duck_012.png");
	//Duck Shoot
LoadingPngFile( &MUGMAN.TextureDuckShoot_offset[0], &MUGMAN.TextureDuckShoot[0], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/shoot/cuphead_duck_shoot_001.png");
LoadingPngFile( &MUGMAN.TextureDuckShoot_offset[1], &MUGMAN.TextureDuckShoot[1], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/shoot/cuphead_duck_shoot_002.png");
LoadingPngFile( &MUGMAN.TextureDuckShoot_offset[2], &MUGMAN.TextureDuckShoot[2], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/duck/shoot/cuphead_duck_shoot_003.png");
	//Run Shoot
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[0], &MUGMAN.TextureRunShoot[0], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_001.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[1], &MUGMAN.TextureRunShoot[1], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_002.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[2], &MUGMAN.TextureRunShoot[2], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_003.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[3], &MUGMAN.TextureRunShoot[3], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_004.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[4], &MUGMAN.TextureRunShoot[4], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_005.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[5], &MUGMAN.TextureRunShoot[5], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_006.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[6], &MUGMAN.TextureRunShoot[6], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_007.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[7], &MUGMAN.TextureRunShoot[7], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_008.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[8], &MUGMAN.TextureRunShoot[8], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_009.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[9], &MUGMAN.TextureRunShoot[9], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_010.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[10], &MUGMAN.TextureRunShoot[10], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_011.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[11], &MUGMAN.TextureRunShoot[11], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_012.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[12], &MUGMAN.TextureRunShoot[12], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_013.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[13], &MUGMAN.TextureRunShoot[13], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_014.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[14], &MUGMAN.TextureRunShoot[14], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_015.png");
LoadingPngFile( &MUGMAN.TextureRunShoot_offset[15], &MUGMAN.TextureRunShoot[15], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/run/shooting/straight/cuphead_run_shoot_016.png");
	//Shoot Up
LoadingPngFile( &MUGMAN.TextureShootUp_offset[0], &MUGMAN.TextureShootUp[0], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/shoot/up/cuphead_shoot_up_001.png");
LoadingPngFile( &MUGMAN.TextureShootUp_offset[1], &MUGMAN.TextureShootUp[1], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/shoot/up/cuphead_shoot_up_002.png");
LoadingPngFile( &MUGMAN.TextureShootUp_offset[2], &MUGMAN.TextureShootUp[2], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/shoot/up/cuphead_shoot_up_003.png");
	//Aim Up
LoadingPngFile( &MUGMAN.TextureAimUp_offset[0], &MUGMAN.TextureAimUp[0], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/aim/up/cuphead_aim_up_001.png");
LoadingPngFile( &MUGMAN.TextureAimUp_offset[1], &MUGMAN.TextureAimUp[1], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/aim/up/cuphead_aim_up_002.png");
LoadingPngFile( &MUGMAN.TextureAimUp_offset[2], &MUGMAN.TextureAimUp[2], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/aim/up/cuphead_aim_up_003.png");
LoadingPngFile( &MUGMAN.TextureAimUp_offset[3], &MUGMAN.TextureAimUp[3], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/aim/up/cuphead_aim_up_004.png");
LoadingPngFile( &MUGMAN.TextureAimUp_offset[4], &MUGMAN.TextureAimUp[4], "/dev_hdd0/game/NPEB88888/USRDIR/Sprites/Cuphead/aim/up/cuphead_aim_up_005.png");

}
void MugmanDraw(){

	MUGMAN.Counter += 1;

if(GamePause == 0){
	//Idle
if(MUGMAN.SwitchPose == 0){
	MUGMAN.NumberTextureDuckIdle = 0;	
		MUGMAN.Cuphead_offset = MUGMAN.TextureIdle_offset[MUGMAN.NumberTextureIdle];
		MUGMAN.Cuphead = MUGMAN.TextureIdle[MUGMAN.NumberTextureIdle];
	if(MUGMAN.Counter > 3){		
		if(MUGMAN.NumberTextureIdle <= 0) MUGMAN.SwitchTextureIdle =  1;
		if(MUGMAN.NumberTextureIdle >= 4) MUGMAN.SwitchTextureIdle = -1;
		MUGMAN.NumberTextureIdle += MUGMAN.SwitchTextureIdle;
		MUGMAN.Counter = 0;
	}	
}
	//Run
if(MUGMAN.SwitchPose == 1){
	MUGMAN.NumberTextureDuckIdle = 0;	
		MUGMAN.Cuphead_offset = MUGMAN.TextureRunNormal_offset[MUGMAN.NumberTextureRunNormal];
		MUGMAN.Cuphead = MUGMAN.TextureRunNormal[MUGMAN.NumberTextureRunNormal];
	if(MUGMAN.Counter > 2){
		MUGMAN.NumberTextureRunNormal += 1;
		if(MUGMAN.NumberTextureRunNormal >= 15)MUGMAN.NumberTextureRunNormal = 0;
		MUGMAN.Counter = 0;
	}	
}
	//Shoot Straight
if(MUGMAN.SwitchPose == 3){
	MUGMAN.NumberTextureDuckIdle = 0;
		MUGMAN.Cuphead_offset = MUGMAN.TextureShootStraight_offset[MUGMAN.NumberTextureShootStraight];
		MUGMAN.Cuphead = MUGMAN.TextureShootStraight[MUGMAN.NumberTextureShootStraight];
	if(MUGMAN.Counter > 3){
		if(MUGMAN.NumberTextureShootStraight >= 2) MUGMAN.SwitchTextureShootStraight = -1;
		if(MUGMAN.NumberTextureShootStraight <= 0) MUGMAN.SwitchTextureShootStraight =  1;
		MUGMAN.NumberTextureShootStraight += MUGMAN.SwitchTextureShootStraight;
		MUGMAN.Counter = 0;
}
}
	//Jump
if(MUGMAN.SwitchPose == 2){
	MUGMAN.NumberTextureDuckIdle = 0;
		MUGMAN.Cuphead_offset = MUGMAN.TextureJump_offset[MUGMAN.NumberTextureJump];
		MUGMAN.Cuphead = MUGMAN.TextureJump[MUGMAN.NumberTextureJump];
	if(MUGMAN.Counter > 3){
		MUGMAN.NumberTextureJump += 1;
		if(MUGMAN.NumberTextureJump >= 6)MUGMAN.NumberTextureJump = 0;
		MUGMAN.Counter = 0;
	}	
}
	//Gravitation
if(MUGMAN.SwitchGravitation == 1){
		MUGMAN.SwitchPose = 2;
		MUGMAN.PositionX -= MUGMAN.FizicJump;
		MUGMAN.FizicJump = MUGMAN.FizicJump - 0.5;
if(MUGMAN.FizicJump < 0){
	if(MUGMAN.PositionX >= Ground){
		MUGMAN.FizicJump = 9;
		MUGMAN.SwitchGravitation = 0;
		MUGMAN.PositionX = Ground;
	}
}		
	}

	
	if(MUGMAN.SwitchGravitation == 0){
	if(MUGMAN.PositionX < Ground){
		MUGMAN.SwitchPose = 2;
		MUGMAN.PositionX += 4;
	}
	}
	//Duck Idle
if(MUGMAN.SwitchPose == 4){
		MUGMAN.Cuphead_offset = MUGMAN.TextureDuckIdle_offset[MUGMAN.NumberTextureDuckIdle];
		MUGMAN.Cuphead = MUGMAN.TextureDuckIdle[MUGMAN.NumberTextureDuckIdle];
	if(MUGMAN.Counter > 3){
		if(MUGMAN.NumberTextureDuckIdle <= 0) MUGMAN.SwitchTextureDuckIdle =  1;
		if(MUGMAN.NumberTextureDuckIdle <= 7) MUGMAN.SwitchTextureDuckIdle =  1;
		if(MUGMAN.NumberTextureDuckIdle >= 11) MUGMAN.SwitchTextureDuckIdle = -1;
		MUGMAN.NumberTextureDuckIdle += MUGMAN.SwitchTextureDuckIdle;
		MUGMAN.Counter = 0;
	}		
	}
	//Duck Shoot	
if(MUGMAN.SwitchPose == 5){
	if(MUGMAN.NumberTextureDuckIdle <= 6){
	if(MUGMAN.Counter > 3){
		MUGMAN.Cuphead_offset = MUGMAN.TextureDuckIdle_offset[MUGMAN.NumberTextureDuckIdle];
		MUGMAN.Cuphead = MUGMAN.TextureDuckIdle[MUGMAN.NumberTextureDuckIdle];
		MUGMAN.NumberTextureDuckIdle += 1;
		MUGMAN.Counter = 0;
	}	
		}else{
		MUGMAN.Cuphead_offset = MUGMAN.TextureDuckShoot_offset[MUGMAN.NumberTextureDuckShoot];
		MUGMAN.Cuphead = MUGMAN.TextureDuckShoot[MUGMAN.NumberTextureDuckShoot];
	if(MUGMAN.Counter > 1){
		if(MUGMAN.NumberTextureDuckShoot >= 2) MUGMAN.SwitchTextureDuckShoot = -1;
		if(MUGMAN.NumberTextureDuckShoot <= 0) MUGMAN.SwitchTextureDuckShoot =  1;
		MUGMAN.NumberTextureDuckShoot += MUGMAN.SwitchTextureDuckShoot;
		MUGMAN.Counter = 0;
	}
}
}

	//Run Shoot
if(MUGMAN.SwitchPose == 6){
	MUGMAN.NumberTextureDuckIdle = 0;	
		MUGMAN.Cuphead_offset = MUGMAN.TextureRunShoot_offset[MUGMAN.NumberTextureRunShoot];
		MUGMAN.Cuphead = MUGMAN.TextureRunShoot[MUGMAN.NumberTextureRunShoot];
	if(MUGMAN.Counter > 2){
		MUGMAN.NumberTextureRunShoot += 1;
		if(MUGMAN.NumberTextureRunShoot >= 15)MUGMAN.NumberTextureRunShoot = 0;
		MUGMAN.Counter = 0;
	}	
}	
	//Aim Up
if(MUGMAN.SwitchPose == 7){
	MUGMAN.NumberTextureDuckIdle = 0;	
	MUGMAN.Cuphead_offset = MUGMAN.TextureAimUp_offset[MUGMAN.NumberTextureAimUp];
	MUGMAN.Cuphead = MUGMAN.TextureAimUp[MUGMAN.NumberTextureAimUp];
	if(MUGMAN.Counter > 3){		
		if(MUGMAN.NumberTextureAimUp <= 0) MUGMAN.SwitchTextureAimUp =  1;
		if(MUGMAN.NumberTextureAimUp >= 4) MUGMAN.SwitchTextureAimUp = -1;
		MUGMAN.NumberTextureAimUp += MUGMAN.SwitchTextureAimUp;
		MUGMAN.Counter = 0;
	}	
}
	//Shoot Up
if(MUGMAN.SwitchPose == 8){
	MUGMAN.NumberTextureDuckIdle = 0;
		MUGMAN.Cuphead_offset = MUGMAN.TextureShootUp_offset[MUGMAN.NumberTextureShootUp];
		MUGMAN.Cuphead = MUGMAN.TextureShootUp[MUGMAN.NumberTextureShootUp];
	if(MUGMAN.Counter > 3){
		if(MUGMAN.NumberTextureShootUp >= 2) MUGMAN.SwitchTextureShootUp = -1;
		if(MUGMAN.NumberTextureShootUp <= 0) MUGMAN.SwitchTextureShootUp =  1;
		MUGMAN.NumberTextureShootUp += MUGMAN.SwitchTextureShootUp;
		MUGMAN.Counter = 0;
}
}
	
if(MUGMAN.PositionX == Ground)MUGMAN.SwitchPose = 0;
if(MUGMAN.PositionY < 0)MUGMAN.PositionY = 0;
if(MUGMAN.PositionY > 840)MUGMAN.PositionY = 840;
}

DrawMatrix( &MUGMAN.Cuphead_offset, &MUGMAN.Cuphead, 100, 100, MUGMAN.PositionY, MUGMAN.PositionX, 0, 0, MUGMAN.Turn, MUGMAN.Color);
}
