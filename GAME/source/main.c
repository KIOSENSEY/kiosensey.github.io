#include "includes.h"
#include "gem.h"
#include "pad.h"
#include "png.h"
#include "mp3.h"

#include "episode_forest_follies.h"

#include "episode_ruse_of_an_ooze.h"
#include "goopy_le_grande.h"

#include "cuphead.h"
#include "ammo.h"

#include "mugman.h"

#include "health_points.h"

int main (s32 argc, const char *argv[]){
	tiny3d_Init(1024*1024);
	COLOR_BACKGROUND = 0xFF00000011;
	sysModuleLoad (SYSMODULE_PNGDEC);
	sysModuleLoad (SYSMODULE_CAMERA);
	sysModuleLoad (SYSMODULE_GEM);
	InitPNG();
	InitMP3();
	InitPad();
	InitGem();

////////////////////
SwitchEpisodes = 1;
////////////////////
  while (1) {
		tiny3d_Clear(COLOR_BACKGROUND, TINY3D_CLEAR_ALL);
        tiny3d_AlphaTest(1, 0x10, TINY3D_ALPHA_FUNC_GEQUAL);
        tiny3d_BlendFunc(1, TINY3D_BLEND_FUNC_SRC_RGB_SRC_ALPHA | TINY3D_BLEND_FUNC_SRC_ALPHA_SRC_ALPHA,
            TINY3D_BLEND_FUNC_DST_RGB_ONE_MINUS_SRC_ALPHA | TINY3D_BLEND_FUNC_DST_ALPHA_ZERO,
            TINY3D_BLEND_RGB_FUNC_ADD | TINY3D_BLEND_ALPHA_FUNC_ADD);
	    tiny3d_End();

////////////////////
ReadGem();
ReadPad();

if(SwitchEpisodes == 1){
	if(SwitchEpisodeRuse0fAnOoze == 0){
		EpisodeRuse0fAnOozeLoading();
		GoopyLeGrandeLoadingTexture();
		CupheadLoadingTexture();		
		//MugmanLoadingTexture();
		AmmoLoadingTexture();
		HealthPointsLoadingTexture();
		//PlayBackgroundSoundRuse0fAnOoze();
		SwitchEpisodeForestFollies = 0;		
	}
		SwitchEpisodeRuse0fAnOoze = 1;
		EpisodeRuse0fAnOozeDraw();
		GoopyLeGrandeDraw();
		AmmoDraw();
		CupheadDraw();
		//MugmanDraw();
		HealthPointsDraw();

}
if(SwitchEpisodes == 2){
		if(SwitchEpisodeForestFollies == 0){
		EpisodeForestFolliesLoadingTexture();		
		CupheadLoadingTexture();		
		//MugmanLoadingTexture();
		AmmoLoadingTexture();
		HealthPointsLoadingTexture();
		//PlayBackgroundSoundForestFollies();
		SwitchEpisodeRuse0fAnOoze = 0;		
	}
		SwitchEpisodeForestFollies = 1;
		EpisodeForestFolliesDraw();
		AmmoDraw();
		CupheadDraw();
		//MugmanDraw();
		HealthPointsDraw();
}
if(SwitchEpisodes == 3){

}

////////////////////

	
    
	tiny3d_Flip();
  }
  return 0;
}
