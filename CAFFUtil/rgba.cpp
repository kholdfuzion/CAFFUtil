#include "types.h"
#include "caff.h"
#include "texture.h"
#include "rgba.h"
#include "file.h"

void RGBA_WRITE_D3DFMT_A8B8G8R8(sTEXTUREFile* texturefile, char* outfile)
{
	rgba_image_header header;
	header.magic = 474;
	header.storage = 0
	header.bpc = 1;
	header.dimensions = 3;
	header.xsize = texturefile->header->Width;
	header.ysize = texturefile->header->Height;
	header.zsize = 4;
	header.pixmin = 0;
	header.pixmax = 255;
	header.colormap = 0;
	u32 size = (header.xsize*header.ysize)+sizeof(rgba_image_header);
	int status = writefile(outfile, , size);
}

