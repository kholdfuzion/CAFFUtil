#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "caff.h"
#include "texture.h"
#include "rgba.h"
#include "file.h"
#include "util.h"

void RGBA_WRITE_D3DFMT_A8B8G8R8(sTEXTUREFile* texturefile, const char* outfile)
{
	rgba_image_header header;
	header.magic = ReverseEndianness((u16)474);
	header.storage = 0;
	header.bpc = 1;
	header.dimensions = ReverseEndianness((u16)3);
	header.xsize = ReverseEndianness((u16)texturefile->header->Width);
	header.ysize = ReverseEndianness((u16)texturefile->header->Height);
	header.zsize = ReverseEndianness((u16)4);
	header.pixmin = ReverseEndianness((u32)0);
	header.pixmax = ReverseEndianness((u32)255);
	header.dummy1 = 0;
	
	//header.imagename = "";
	for (int i = 0; i <= sizeof(header.imagename); i++)
	{
		header.imagename[i]=0;
	}
	
	header.colormap = 0;
	//header.dummy2 = 0;
	for (int i = 0; i < sizeof(header.dummy2); i++)
	{
		header.dummy2[i] = 0;
	}

	u32 size = ((texturefile->header->Width * texturefile->header->Height) * 8)+sizeof(rgba_image_header);
	printf("sizergbaimagefile : %08x\n", size);
	char* buffer = (char*)calloc(1,size);
	
	memcpy(&buffer[0], &header, sizeof(rgba_image_header));
	for (int i = 0; i < (texturefile->header->Width * texturefile->header->Height); i++)
	{
		texturefile->texturedata[i] = ReverseEndianness(texturefile->texturedata[i]);
		//printf("%03d ", i);
	}
	//should fix alpha and deswizzle first
	memcpy(&buffer[sizeof(rgba_image_header)], texturefile->texturedata, (texturefile->header->Width * texturefile->header->Height * 8) );
	int status = writefile(outfile, (const char*)buffer, size);
	free(buffer);
}

