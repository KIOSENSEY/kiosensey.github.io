#include "includes.h"

padInfo padinfo;
padData paddata_01;
padData paddata_02;

int SwitchButtonPause;
int TimerButtonPause;
int SwitchCrossButtonPad01;
int SwitchCrossButtonPad02;

void InitPad(){
	ioPadInit(6);
}
void ReadPad(){
	ioPadGetInfo(&padinfo);
//////////////////////////////// GAMEPAD 1: ////////////////////////////////	
	if(padinfo.status[0]){
	ioPadGetData(0, &paddata_01);
//BUTTON LEFT
	if(paddata_01.BTN_LEFT){

	}
//BUTTON RIGHT
	if(paddata_01.BTN_RIGHT){

	}
//BUTTON UP
	if(paddata_01.BTN_UP){
SwitchEpisodes = 1;
	}
//BUTTON DOWN
	if(paddata_01.BTN_DOWN){
SwitchEpisodes = 2;
	}
//BUTTON CROSS
	if(paddata_01.BTN_CROSS){
		if(GamePause == 0){
			if(CUPHEAD.FizicJump > 3){
				CUPHEAD.CounterCrossButton += 1;
			if(CUPHEAD.CounterCrossButton == 10){
				CUPHEAD.FizicJump = 9;
			}
			}			
			if(SwitchCrossButtonPad01 == 0){
				CUPHEAD.SwitchGravitation = 1;
			}
				SwitchCrossButtonPad01 = 1;			
		}
	}else{
		if(CUPHEAD.SwitchGravitation == 0){
			SwitchCrossButtonPad01 = 0;
			CUPHEAD.CounterCrossButton = 0;
		}
	}
//BUTTON TRIANGLE
	if(paddata_01.BTN_TRIANGLE){
//sysProcessExit(1);
	}	
//BUTTON CIRCLE
	if(paddata_01.BTN_CIRCLE){
		if(GamePause == 0){
			CUPHEAD.Color = 0x555555FF;
		}
	}else{
			CUPHEAD.Color = 0xffffffff;
		}
//BUTTON SELECT
	if(paddata_01.BTN_SELECT){
		sysProcessExitSpawn2("/dev_hdd0/game/NPEB88888/USRDIR/GAME.self", NULL, NULL, NULL, 0, 1001, SYS_PROCESS_SPAWN_STACK_SIZE_1M);
	}
//BUTTON START
	if(paddata_01.BTN_START){
		if(SwitchButtonPause == 0){
		if(GamePause == 0){
			GamePause = 1;
		}else{
			GamePause = 0;
		}
		SwitchButtonPause = 1;
		}
		TimerButtonPause += 1;
	}
	
	if(TimerButtonPause < 1){
		SwitchButtonPause = 0;
	}
		TimerButtonPause = 0;
//BUTTON L1
	if(paddata_01.BTN_L1){
		
	}
//BUTTON L2
	if(paddata_01.BTN_L2){

	}
//BUTTON R1
	if(paddata_01.BTN_R1){

	}	
//BUTTON R2
	if(paddata_01.BTN_R2){

	}	
//ANALOG RIGHT: HORIZINTAL LEFT
	if(paddata_01.ANA_R_H <= 1){
		
	}
//ANALOG RIGHT: HORIZINTAL RIGHT
	if(paddata_01.ANA_R_H >= 255){
		
	}	
//ANALOG RIGHT: VERTICAL UP
	if(paddata_01.ANA_R_V <= 1 ){
		
	}
//ANALOG RIGHT: VERTICAL DOWN
	if(paddata_01.ANA_R_V >= 255){
		
	}
//ANALOG LEFT: HORIZINTAL LEFT
	if(paddata_01.ANA_L_H <= 100){
if(GamePause == 0){	
PEASHOOTER[0].ButtonLeft = 1;	
		if(CUPHEAD.SwitchPose == 0){
CUPHEAD.SwitchPose = 1;
		}
CUPHEAD.Turn = 1;		
if(CUPHEAD.SwitchMovingR == 0)CUPHEAD.PositionY -= 5;

if(CUPHEAD.PositionY > 200 && CUPHEAD.PositionY < 640  ){
}else{
	if(CUPHEAD.PositionY > 1 && CUPHEAD.PositionY < 839 )RUSEOFANOOZE.Position_02Y += 0.1, RUSEOFANOOZE.Position_01Y += 0.2;
}
}

	}else{
		PEASHOOTER[0].ButtonLeft = 0;
	}
//ANALOG LEFT: HORIZINTAL RIGHT
	if(paddata_01.ANA_L_H >= 200){
if(GamePause == 0){
	PEASHOOTER[0].ButtonRight = 1;
		if(CUPHEAD.SwitchPose == 0){
CUPHEAD.SwitchPose = 1;
		}
CUPHEAD.Turn = 0;
if(CUPHEAD.SwitchMovingR == 0)CUPHEAD.PositionY += 5;
	
if(CUPHEAD.PositionY > 200 && CUPHEAD.PositionY < 640  ){
}else{
	if(CUPHEAD.PositionY > 1 && CUPHEAD.PositionY < 839 )RUSEOFANOOZE.Position_02Y -= 0.1, RUSEOFANOOZE.Position_01Y -= 0.2;
}
}	
	}else{
		PEASHOOTER[0].ButtonRight = 0;
	}
//ANALOG LEFT: VERTICAL UP
	if(paddata_01.ANA_L_V <= 100 ){
if(GamePause == 0){		
		if(CUPHEAD.SwitchPose == 0)CUPHEAD.SwitchPose = 7;
		PEASHOOTER[0].ButtonUp = 1;

}
	}else{
		PEASHOOTER[0].ButtonUp = 0;
	}
//ANALOG LEFT: VERTICAL DOWN
	if(paddata_01.ANA_L_V >= 200){
if(GamePause == 0){			
		if(CUPHEAD.SwitchPose == 0)CUPHEAD.SwitchPose = 4;
}
	}
//BUTTON SQUARE
	if(paddata_01.BTN_SQUARE){
if(GamePause == 0){
PEASHOOTER[0].Switch = 1;	
		if(CUPHEAD.SwitchPose == 0)CUPHEAD.SwitchPose = 3;
		if(CUPHEAD.SwitchPose == 4)CUPHEAD.SwitchPose = 5;
		if(CUPHEAD.SwitchPose == 1)CUPHEAD.SwitchPose = 6;
		if(CUPHEAD.SwitchPose == 7)CUPHEAD.SwitchPose = 8;
}
	}	
	}

//////////////////////////////// GAMEPAD 2: ////////////////////////////////	
	if(padinfo.status[1]){
	ioPadGetData(1, &paddata_02);
//BUTTON LEFT
	if(paddata_02.BTN_LEFT){

	}
//BUTTON RIGHT
	if(paddata_02.BTN_RIGHT){

	}
//BUTTON UP
	if(paddata_02.BTN_UP){

	}
//BUTTON DOWN
	if(paddata_02.BTN_DOWN){
		
	}
//BUTTON CROSS
	if(paddata_02.BTN_CROSS){
		if(GamePause == 0){
			if(MUGMAN.FizicJump > 3){
				MUGMAN.CounterCrossButton += 1;
			if(MUGMAN.CounterCrossButton == 10){
				MUGMAN.FizicJump = 9;
			}
			}
			if(SwitchCrossButtonPad02 == 0){
				MUGMAN.SwitchGravitation = 1;
			}
			SwitchCrossButtonPad02 = 1;
			}
		}else{
		if(MUGMAN.SwitchGravitation == 0){
			SwitchCrossButtonPad02 = 0;
		MUGMAN.CounterCrossButton = 0;
		}
	}		

//BUTTON TRIANGLE
	if(paddata_02.BTN_TRIANGLE){

	}	
//BUTTON CIRCLE
	if(paddata_02.BTN_CIRCLE){

	}
//BUTTON SELECT
	if(paddata_02.BTN_SELECT){

	}
//BUTTON START
	if(paddata_02.BTN_START){
		sysProcessExit(1);
	}		
//BUTTON L1
	if(paddata_02.BTN_L1){

	}
//BUTTON L2
	if(paddata_02.BTN_L2){

	}
//BUTTON R1
	if(paddata_02.BTN_R1){

	}	
//BUTTON R2
	if(paddata_02.BTN_R2){

	}
//ANALOG LEFT: HORIZINTAL LEFT
	if(paddata_02.ANA_L_H <= 100){
if(GamePause == 0){		
		if(MUGMAN.SwitchPose == 0){
MUGMAN.SwitchPose = 1;
		}
MUGMAN.Turn = 1;		
if(MUGMAN.SwitchMovingR == 0)MUGMAN.PositionY -= 5;

if(MUGMAN.PositionY > 200 && MUGMAN.PositionY < 640  ){
}else{
	if(MUGMAN.PositionY > 1 && MUGMAN.PositionY < 839 )RUSEOFANOOZE.Position_02Y += 0.1, RUSEOFANOOZE.Position_01Y += 0.2;
}
}

	}
//ANALOG LEFT: HORIZINTAL RIGHT
	if(paddata_02.ANA_L_H >= 200){
if(GamePause == 0){	
		if(MUGMAN.SwitchPose == 0){
MUGMAN.SwitchPose = 1;
		}
MUGMAN.Turn = 0;
if(MUGMAN.SwitchMovingR == 0)MUGMAN.PositionY += 5;
	
if(MUGMAN.PositionY > 200 && MUGMAN.PositionY < 640  ){
}else{
	if(MUGMAN.PositionY > 1 && MUGMAN.PositionY < 839 )RUSEOFANOOZE.Position_02Y -= 0.1, RUSEOFANOOZE.Position_01Y -= 0.2;
}
}
	}	
//ANALOG LEFT: VERTICAL UP
	if(paddata_02.ANA_L_V <= 1 ){
if(GamePause == 0){			
		if(MUGMAN.SwitchPose == 0)MUGMAN.SwitchPose = 7;

}
	}
//ANALOG LEFT: VERTICAL DOWN
	if(paddata_02.ANA_L_V >= 255){

	}	
//ANALOG RIGHT: HORIZINTAL LEFT
	if(paddata_02.ANA_R_H <= 1){
		
	}
//ANALOG RIGHT: HORIZINTAL RIGHT
	if(paddata_02.ANA_R_H >= 255){
		
	}	
//ANALOG RIGHT: VERTICAL UP
	if(paddata_02.ANA_R_V <= 1 ){
		
	}
//ANALOG RIGHT: VERTICAL DOWN
	if(paddata_02.ANA_R_V >= 255){
		
	}
//BUTTON SQUARE
	if(paddata_02.BTN_SQUARE){
if(GamePause == 0){			
		if(MUGMAN.SwitchPose == 0)MUGMAN.SwitchPose = 3;
		if(MUGMAN.SwitchPose == 4)MUGMAN.SwitchPose = 5;
		if(MUGMAN.SwitchPose == 1)MUGMAN.SwitchPose = 6;
		if(MUGMAN.SwitchPose == 7)MUGMAN.SwitchPose = 8;
}
	}	
	}
		
}

