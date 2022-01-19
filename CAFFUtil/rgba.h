#pragma once
#include "types.h"
#include "caff.h"
#include "texture.h"

typedef struct rgba_image_header
{
    s16 magic; //IRIS image file magic number
    char storage; //Storage format
    char bpc; //Number of bytes per pixel channel
    u16 dimensions; //Number of dimensions
    u16 xsize; //X size in pixels
    u16 ysize; //Y size in pixels
    u16 zsize; //Number of channels
    u32 pixmin; //Minimum pixel value
    u32 pixmax; //Maximum pixel value
    char dummy1; //Ignored
    char imagename[80]; //Image name
    u32 colormap; //Colormap ID
    char dummy2[404]; //Ignored
} rgba_image_header;

void RGBA_WRITE_D3DFMT_A8B8G8R8(sTEXTUREFile* texturefile, const char* outfile);


