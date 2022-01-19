#pragma once
#include "types.h"

#define TEXTUREMAGIC "texture"
#define TEXTUREVERSION "04.05.05.0032"

#pragma pack ( 1 )
typedef struct sTEXTUREFileHeader
{
    char magic[8];
    char version[16];
    u32 Format;
    u32 Type;
    u32 unk1;
    u16 Width;
    u16 Height;
    u32 Offset;
    u32 MipOffset;
    u32 Levels;
    u32 Ptr;
    u32 Depth;
    u32 PAD[13];
} sTEXTUREFileHeader;

typedef struct sTEXTUREFile
{
    sTEXTUREFileHeader* header;
    u8* texturedata;
} sTEXTUREFile;

s32 TEXTURE_CheckHeader(const char* buffer);
void TEXTURE_LoadFile(sCAFFFile* caffFile, sTEXTUREFile* textureFile, const char* buffer);
void TEXTURE_ConvertFile(sTEXTUREFile* texturefile, const char* outfile);

