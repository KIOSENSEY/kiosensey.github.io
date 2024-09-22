#include "includes.h"

	//u32 texture_offset[255];
	//pngData texture[255];
	u32* texture_mem;
	u32* texture_pointer;

	
void InitPNG(){
	texture_mem = tiny3d_AllocTexture(64*1024*1024);
	texture_pointer = texture_mem;
}

char* buff;
void LoadingFiles(const char* first, int f){
	const char* second[255] = {"001.png", "002.png", "003.png", "004.png", "005.png", "006.png", "007.png", "008.png", "009.png", "010.png", "011.png", "012.png", "013.png", "014.png", "015.png", "016.png", "017.png", "018.png", "019.png", "020.png"};
    buff = calloc(strlen(first) + strlen(second[f]) + 1, 1);
    strcat(buff, first);
    strcat(buff, second[f]);
}

void LoadingPngFile(u32 texture_offset[0], pngData texture[0], char *PngFile){

	file = fopen(PngFile, "rb");if(!file){sysProcessExit(1);}else{fclose(file);}
	pngLoadFromFile(PngFile, &texture[0]);
	
    if(texture[0].bmp_out) {
        memcpy(texture_pointer, texture[0].bmp_out, texture[0].pitch * texture[0].height);       
        free(texture[0].bmp_out);
        texture[0].bmp_out= texture_pointer;
        texture_pointer += (texture[0].pitch/4 * texture[0].height + 3) & ~3;
        texture_offset[0] = tiny3d_TextureOffset(texture[0].bmp_out);
     }	
	tiny3d_SetTextureWrap(0, texture_offset[0], texture[0].width, texture[0].height, texture[0].pitch,  TINY3D_TEX_FORMAT_A8R8G8B8,
                TEXTWRAP_CLAMP, TEXTWRAP_CLAMP, TEXTURE_LINEAR);

}

void DrawMatrix(u32 texture_offset[0], pngData texture[0], float rx, float ry, float HorizontalPosition, float VerticalPosition, float RotationYap, float RotationZ, float RotationY, long Color){

	float x = rx / 2;
	float y = ry / 2;
	float posX1;
	float posX2;
	float posY1;
	float posY2;
	
	if(RotationY == 0){
		posX1 = -x;
		posX2 =  x;
	}else{
		posX1 =  x;
		posX2 = -x;
	}
	if(RotationZ == 0){
		posY1 = -y;
		posY2 =  y;
	}else{
		posY1 =  y;
		posY2 = -y;
	}

	MATRIX tmp;
	
    tiny3d_Project2D();
	tmp = MatrixTranslation(HorizontalPosition, VerticalPosition, 0);
	
	matrix = MatrixRotationZ(RotationYap);
    matrix = MatrixMultiply(matrix, tmp);
	
	tiny3d_SetMatrixModelView(&matrix);
	
	tiny3d_SetTextureWrap(0, texture_offset[0], texture[0].width, texture[0].height, texture[0].pitch,  TINY3D_TEX_FORMAT_A8R8G8B8, TEXTWRAP_CLAMP, TEXTWRAP_CLAMP, TEXTURE_LINEAR);
	tiny3d_SetPolygon(TINY3D_QUADS);
    tiny3d_VertexPos(posX1, posY1, 0);
	tiny3d_VertexColor(Color);
    tiny3d_VertexTexture(0.0f, 0.0f);
    tiny3d_VertexPos(posX2, posY1, 0);
	tiny3d_VertexTexture(0.99f, 0.0f);
    tiny3d_VertexPos(posX2, posY2, 0);
	tiny3d_VertexTexture(0.99f, 0.99f);
    tiny3d_VertexPos(posX1, posY2, 0);
	tiny3d_VertexTexture(0.0f, 0.99f);
    tiny3d_End();	
	tiny3d_SetMatrixModelView(NULL);	
}
