
#include "includes.h"

#define SPURS_PREFIX_NAME "gemsample"

gemAttribute gem_attr;
gemInfo gem_info;
gemVideoConvertAttribute gem_video_convert;
gemState gem_state;
gemInertialState gem_inertial_state;
u16 oldGemPad = 0;
u16 newGemPad = 0;
u16 newGemAnalogT = 0;
extern int tracking;
extern cameraReadInfo camread;
extern cameraInfoEx camInf;
Spurs *spurs ATTRIBUTE_PRXPTR;
void *gem_memory ATTRIBUTE_PRXPTR;
//extern rsxBuffer buffers[MAX_BUFFERS];
extern int currentBuffer;
float rx, ry;

int dx = 200;			// default step x
int dy = 100;			// default step y
gemImageState image_state;
void *buffer_mem ATTRIBUTE_PRXPTR;
void *video_out ATTRIBUTE_PRXPTR;
u8 video_frame[640*480*4];
extern int tracking;
extern int pos_x;
extern int pos_y;

static inline float vec_array (vec_float4 vec, unsigned int idx) {
  union {
    vec_float4 vec;
    float array[4];
  } v;

  v.vec = vec;

  if (idx > 3)
    return -1;
  return v.array[idx];
}

static inline void initAttributeGem (gemAttribute * attribute, u32 max_connect, void *memory_ptr, Spurs * spurs, const u8 spu_priorities[8]){
  int i;
  attribute->version = 2;
  attribute->max = max_connect;
  attribute->spurs = spurs;
  attribute->memory = memory_ptr;
  for (i = 0; i < 8; ++i)
    attribute->spu_priorities[i] = spu_priorities[i];
}

int InitGem(){
  int ret;
  sys_ppu_thread_t ppu_thread_id;
  int ppu_prio;
  unsigned int nthread;
  ret = sysSpuInitialize (6, 0);
  ret = sysThreadGetId (&ppu_thread_id);
  ret = sysThreadGetPriority (ppu_thread_id, &ppu_prio);
  spurs = (void *) memalign (SPURS_ALIGN, sizeof (Spurs));
  SpursAttribute attributeSpurs;
  ret = spursAttributeInitialize (&attributeSpurs, 5, 250, ppu_prio - 1, true);
  if (ret)return (ret);
  ret = spursAttributeSetNamePrefix (&attributeSpurs, SPURS_PREFIX_NAME, strlen (SPURS_PREFIX_NAME));
  if (ret)return (ret);
  ret = spursInitializeWithAttribute (spurs, &attributeSpurs);
  if (ret) return (ret);
  ret = spursGetNumSpuThread (spurs, &nthread);
  sys_spu_thread_t *threads = (sys_spu_thread_t *) malloc (sizeof (sys_spu_thread_t) * nthread);
  ret = spursGetSpuThreadId (spurs, threads, &nthread);
  SpursInfo info;
  ret = spursGetInfo (spurs, &info);
  ret = gemGetMemorySize (1);
  gem_memory = malloc (ret);
  u8 gem_spu_priorities[8] = { 1, 1, 1, 1, 1, 0, 0, 0 };
  gemAttribute gem_attr;
  initAttributeGem (&gem_attr, 1, gem_memory, spurs, gem_spu_priorities);
  ret = gemInit (&gem_attr);
  ret = gemPrepareCamera (128, 0.5);
  ret = gemReset(0);
  return ret;
}

void readGemAccPosition (int num_gem){
  vec_float4 position;
  gemGetAccelerometerPositionInDevice (num_gem, &position);
  printf (" accelerometer device coordinates [%f,%f,%f,%f]\n",
      vec_array (position, 0), vec_array (position, 1), vec_array (position, 2),
      vec_array (position, 3));
}
int swPos;
void readGemInertial (int num_gem){
  int ret;
  ret = gemGetInertialState (num_gem, 0, -22000, &gem_inertial_state);
  printf ("gemGetInertialState return %X\n", ret);
  printf ("counter %d temperature %f\n", gem_inertial_state.counter,
      gem_inertial_state.temperature);

  printf (" accelerometer sensor   [%f,%f,%f,%f]\n",
      vec_array (gem_inertial_state.accelerometer, 0),
      vec_array (gem_inertial_state.accelerometer, 1),
      vec_array (gem_inertial_state.accelerometer, 2),
      vec_array (gem_inertial_state.accelerometer, 3));
	    
			
  printf (" accelerometer_bias sensor   [%f,%f,%f,%f]\n",
      vec_array (gem_inertial_state.accelerometer_bias, 0),
      vec_array (gem_inertial_state.accelerometer_bias, 1),
      vec_array (gem_inertial_state.accelerometer_bias, 2),
      vec_array (gem_inertial_state.accelerometer_bias, 3));


  printf (" gyro sensor  [%f,%f,%f,%f]\n", vec_array (gem_inertial_state.gyro,
	  0), vec_array (gem_inertial_state.gyro, 1),
      vec_array (gem_inertial_state.gyro, 2),
      vec_array (gem_inertial_state.gyro, 3));


  printf (" gyro_bias sensor  [%f,%f,%f,%f]\n",
      vec_array (gem_inertial_state.gyro_bias, 0),
      vec_array (gem_inertial_state.gyro_bias, 1),
      vec_array (gem_inertial_state.gyro_bias, 2),
      vec_array (gem_inertial_state.gyro_bias, 3));
	  
	  
	  if(GamePause == 0){
	  ///////////////////////

	  /////////////////////// 
	  }	  
	  

}
void CameraFrame(){};
void ReadGem(){
  gemUpdateStart (*CameraFrame, 2);
  gemUpdateFinish();
  gemForceRGB (0, 2, 2, 2);
  readGemAccPosition (0);
  readGemInertial (0);

  int ret;
  ret = gemGetState (0, 0, -22000, &gem_state);
  newGemPad = gem_state.paddata.buttons & (~oldGemPad);
  newGemAnalogT = gem_state.paddata.ANA_T;
  oldGemPad = gem_state.paddata.buttons;

  switch (newGemPad) {
    case 1:
      printf ("Select pressed \n");
     break;
    case 2:
	printf ("T pressed \n");

      break;
    case 4:
      printf ("Move pressed \n");
      gemCalibrate (0);

      break;
    case 8:
      printf ("Start pressed \n");

      break;
    case 16:
      printf ("Triangle pressed \n");

      break;
    case 32:
      printf ("Circle pressed \n");

      break;
    case 64:
      printf ("Cross pressed \n");

      printf ("X,Y,Z position (mm) %f %f %f\n", vec_array (gem_state.pos, 0),
	  vec_array (gem_state.pos, 1), vec_array (gem_state.pos, 2));
      readGemAccPosition (0);
      break;
    case 128:
      printf ("Square pressed \n");

      readGemInertial (0);
      break;
    default:
      break;
  } 
}
