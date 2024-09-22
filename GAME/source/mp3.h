#include "includes.h"
#ifndef FROM_FILE
#include "spu_soundmodule.bin.h"
#else
void * spu_soundmodule_bin = NULL;
#endif

#include "spu_soundlib.h"
#include "audioplayer.h"

u32 spu = 0;
sysSpuImage spu_image;

#define SPU_SIZE(x) (((x)+127) & ~127)

	u32 inited;
	u32 entry = 0;
	u32 segmentcount = 0;
	sysSpuSegment* segments;
	
#define INITED_CALLBACK     1
#define INITED_SPU          2
#define INITED_SOUNDLIB     4
#define INITED_AUDIOPLAYER  8

void InitMP3(){
	sysSpuInitialize(1, 1);
	sysSpuRawCreate(&spu, NULL);
	sysSpuElfGetInformation(spu_soundmodule_bin, &entry, &segmentcount);
	size_t segmentsize = sizeof(sysSpuSegment) * segmentcount;
	segments = (sysSpuSegment*)memalign(128, SPU_SIZE(segmentsize));
	memset(segments, 0, segmentsize);
	sysSpuElfGetSegments(spu_soundmodule_bin, segments, segmentcount);
	sysSpuImageImport(&spu_image, spu_soundmodule_bin, 0);
    sysSpuRawImageLoad(spu, &spu_image);
    inited |= INITED_SPU ;
	if(SND_Init(spu)==0) inited |= INITED_SOUNDLIB;	
}
//////////////////////////////////////////////

void PlayBackgroundSoundRuse0fAnOoze(){
	FILE *fp = fopen("/dev_hdd0/game/NPEB88888/USRDIR/Sounds/BackgroundSoundRuse0fAnOoze", "rb");
		if(!fp){sysProcessExit(1);
	}else{
		if(PlayAudiofd(fp, 0,  AUDIO_INFINITE_TIME)==0) inited|= INITED_AUDIOPLAYER;
	}
}
void PlayBackgroundSoundForestFollies(){
	FILE *fp = fopen("/dev_hdd0/game/NPEB88888/USRDIR/Sounds/BackgroundSoundForestFollies", "rb");
		if(!fp){sysProcessExit(1);
	}else{
		if(PlayAudiofd(fp, 0,  AUDIO_INFINITE_TIME)==0) inited|= INITED_AUDIOPLAYER;
	}
}
