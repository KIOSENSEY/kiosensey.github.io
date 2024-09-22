#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sysmodule/sysmodule.h>
#include <sysutil/sysutil.h>
#include <sysutil/video.h>
#include <rsx/rsx.h>
#include <rsx/gcm_sys.h>
#include <spurs/types.h>
#include <io/pad.h>
#include <io/camera.h>
#include <io/move.h>
#include <sys/thread.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/net.h>
#include <arpa/inet.h>
#include <spurs/types.h>
#include <assert.h>
#include <time.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <tiny3d.h>
#include <libfont.h>
#include <ppu-lv2.h>
#include <ppu-types.h>
#include <ppu-types.h>
#include <lv2/spu.h>
#include <lv2/process.h>
#include <sys/spu.h>
#include <sys/systime.h>
#include <sys/socket.h> 
#include <sys/thread.h>
#include <sys/types.h>  
#include <sys/file.h>
#include <sys/process.h>
#include <sys/memory.h>
#include <sysutil/sysutil.h>
#include <sysmodule/sysmodule.h>
#include <pngdec/pngdec.h>
#include <io/pad.h>
#include <io/mouse.h>
#include <stdio.h>
#include <io/move.h>
#include <sys/memory.h>
#include <ppu-types.h>
#include <io/camera.h>
#include <ppu-types.h>
#include <spurs/spurs.h>
#include <sys/spu.h>
#include <sys/thread.h>
#include <sys/systime.h>
#include <ppu-lv2.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sysutil/video.h>
#include <rsx/gcm_sys.h>
#include <rsx/rsx.h>
#include <io/pad.h>
#include <sysmodule/sysmodule.h>
#include <sysutil/sysutil.h>
#include <sys/memory.h>
#include <io/camera.h>

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sysmodule/sysmodule.h>
#include <sysutil/sysutil.h>
#include <sysutil/video.h>
#include <rsx/rsx.h>
#include <rsx/gcm_sys.h>
#include <spurs/types.h>
#include <io/pad.h>
#include <io/camera.h>
#include <io/move.h>
#include <sys/thread.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/net.h>
#include <arpa/inet.h>
#include <spurs/types.h>
#include <assert.h>

#include <time.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <tiny3d.h>
#include <ppu-lv2.h>
#include <ppu-types.h>
#include <ppu-types.h>
#include <lv2/spu.h>
#include <lv2/process.h>
#include <sys/spu.h>
#include <sys/systime.h>
#include <sys/socket.h> 
#include <sys/thread.h>
#include <sys/types.h>  
#include <sys/file.h>
#include <sys/process.h>
#include <sys/memory.h>
#include <sysutil/sysutil.h>
#include <sysmodule/sysmodule.h>
#include <pngdec/pngdec.h>
#include <io/pad.h>
#include <io/mouse.h>
#include <stdio.h>
#include <io/move.h>
#include <sys/memory.h>
#include <ppu-types.h>
#include <io/camera.h>
#include <ppu-types.h>
#include <spurs/spurs.h>
#include <sys/spu.h>
#include <sys/thread.h>
#include <sys/systime.h>
#include <stdio.h>
#include <io/move.h>
#include <sys/memory.h>
#include <ppu-types.h>
#include <io/camera.h>
#include <ppu-types.h>
#include <spurs/spurs.h>
#include <sys/spu.h>
#include <sys/thread.h>
#include <sys/systime.h>

#include <time.h>
#include <ppu-lv2.h>
#include <sys/spu.h>
#include <lv2/spu.h>
#include <lv2/process.h>
#include <sys/systime.h>
#include <sys/thread.h>
#include <sys/file.h>
#include <sysmodule/sysmodule.h>
#include <sysutil/sysutil.h>
#include <io/pad.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <tiny3d.h>

#include <sysutil/save.h>
#include <sysutil/msg.h>
#include <sysutil/sysutil.h>

long COLOR_BACKGROUND;
int GamePause;
int SwitchEpisodes;
int SwitchEpisodeRuse0fAnOoze;
int SwitchEpisodeForestFollies;

FILE* file;
int i;
MATRIX matrix;

float Ground;

#ifndef _MYLIB_H
#define _MYLIB_H

struct{
	long Color;
	
	u32 Cuphead_offset;	
	pngData Cuphead;
	
	u32 TextureIdle_offset[5];	
	pngData TextureIdle[5];

	u32 TextureRunNormal_offset[16];	
	pngData TextureRunNormal[16];
	
	u32 TextureJump_offset[7];	
	pngData TextureJump[7];
	
	u32 TextureShootStraight_offset[3];	
	pngData TextureShootStraight[3];
	
	u32 TextureDuckIdle_offset[12];	
	pngData TextureDuckIdle[12];

	u32 TextureDuckShoot_offset[3];	
	pngData TextureDuckShoot[3];
	
	u32 TextureRunShoot_offset[16];	
	pngData TextureRunShoot[16];

	u32 TextureShootUp_offset[3];	
	pngData TextureShootUp[3];
	
	u32 TextureAimUp_offset[5];	
	pngData TextureAimUp[5];	
	
	float PositionY;
	float PositionX;
		
	int SwitchGravitation;
	float FizicJump;
	int CounterCrossButton;
	
	int Turn;
	
	int SwitchPose;
	int Counter;
	int Texture;
	
	int NumberTextureIdle;
	int SwitchTextureIdle;
	
	int NumberTextureRunNormal;
	
	int NumberTextureJump;
	
	int NumberTextureShootStraight;
	int SwitchTextureShootStraight;
	
	int SwitchMovingR;
	int SwitchMovingL;
	
	int NumberTextureDuckIdle;
	int SwitchTextureDuckIdle;
	
	int NumberTextureDuckShoot;
	int SwitchTextureDuckShoot;
	
	int NumberTextureRunShoot;
	
	int NumberTextureShootUp;
	int SwitchTextureShootUp;
	
	int NumberTextureAimUp;
	int SwitchTextureAimUp;
	
}CUPHEAD;

struct{
	long Color;
	
	u32 Cuphead_offset;	
	pngData Cuphead;
	
	u32 TextureIdle_offset[5];	
	pngData TextureIdle[5];

	u32 TextureRunNormal_offset[16];	
	pngData TextureRunNormal[16];
	
	u32 TextureJump_offset[7];	
	pngData TextureJump[7];
	
	u32 TextureShootStraight_offset[3];	
	pngData TextureShootStraight[3];
	
	u32 TextureDuckIdle_offset[12];	
	pngData TextureDuckIdle[12];

	u32 TextureDuckShoot_offset[3];	
	pngData TextureDuckShoot[3];
	
	u32 TextureRunShoot_offset[16];	
	pngData TextureRunShoot[16];

	u32 TextureShootUp_offset[3];	
	pngData TextureShootUp[3];
	
	u32 TextureAimUp_offset[5];	
	pngData TextureAimUp[5];	
	
	float PositionY;
	float PositionX;
	
	
	int SwitchGravitation;
	float FizicJump;
	int CounterCrossButton;
	
	int Turn;
	
	int SwitchPose;
	int Counter;
	int Texture;
	
	int NumberTextureIdle;
	int SwitchTextureIdle;
	
	int NumberTextureRunNormal;
	
	int NumberTextureJump;
	
	int NumberTextureShootStraight;
	int SwitchTextureShootStraight;
	
	int SwitchMovingR;
	int SwitchMovingL;
	
	int NumberTextureDuckIdle;
	int SwitchTextureDuckIdle;
	
	int NumberTextureDuckShoot;
	int SwitchTextureDuckShoot;
	
	int NumberTextureRunShoot;
	
	int NumberTextureShootUp;
	int SwitchTextureShootUp;
	
	int NumberTextureAimUp;
	int SwitchTextureAimUp;
	
}MUGMAN;

struct{
	u32 TextureBackground_offset[255];	
	pngData TextureBackground[255];	
	float Position_01Y;
	float Position_02Y;	
}RUSEOFANOOZE;

struct{	
	long Color;
	float PositionY;
	float PositionX;
	float SwitchMoveY;
	int Turn;
	float Ground;	
	float FizicJump;
	int SwitchJump;	
	u32 TextureSlime_offset[255];	
	pngData TextureSlime[255];		
	u32 TextureSlimeJump_offset[255];	
	pngData TextureSlimeJump[255];	
	u32 TextureUpDownTransition_offset[255];
	pngData TextureUpDownTransition[255];
	u32 TextureAirUp_offset[255];
	pngData TextureAirUp[255];
	u32 TextureAirDown_offset[255];
	pngData TextureAirDown[255];
	int SwitchPoseSlim;
	int Counter;	
	int NumberTextureJump;
	int SwitchTextureJump;	
	int NumberTextureUpDownTransition;
	int SwitchTextureUpDownTransition;	
	int NumberTextureAirUp;
	int SwitchTextureAirUp;			
	int NumberTextureAirDown;
	int SwitchTextureAirDown;
	int ShootHit;
	
	u32 TextureDeadh_offset[255];
	pngData TextureDeadh[255];
	int NumberTextureDeadh;
	int SwitchTextureDeadh;
}GOOPYLEGRANDE;

struct{
	u32 TextureBackground_offset[255];	
	pngData TextureBackground[255];	
	float WorldPosition;	
	float Position_01Y;
	float Position_01X;	
	float Position_02Y;
	float Position_02X;	
}FORESTFOLLIES;


struct{
	int Switch;
	int SwitchStop;
	u32 TextureHealthPoints_offset[255];
	pngData TextureHealthPoints[255];
	u32 TextureHealthPointsNumber_offset[255];
	pngData TextureHealthPointsNumber[255];
	u32 TextureHealthPointsDead_offset[255];
	pngData TextureHealthPointsDead[255];
}CUPHEADHEALTPOINTS;

struct{
	int Switch;
	int SwitchTexture;
	int SwitchEnemy;
	int Counter;
	int Turn;
	int TurnTmp;
	u32 TextureShoots_offset[255];
	pngData TextureShoots[255];
	u32 TexturePeashooter_ex_offset[255];
	pngData TexturePeashooter_ex[255];	
	int NumberTexturePeashooter_ex;
	int SwitchTexturePeashooter_ex;
	int ButtonUp;
	int ButtonLeft;
	int ButtonRight;
	float PositionY;
	float PositionX;
	int SwitchPose;
	int TextureTurnOver;
}PEASHOOTER[255];
#endif




