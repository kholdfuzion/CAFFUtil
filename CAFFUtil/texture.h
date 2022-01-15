#pragma once
#include "types.h"

#define TEXTUREMAGIC "texture"
#define TEXTUREVERSION "04.05.05.0032"

struct TEXTURE_HEADER
{
    /*0x00*/ char textureMagic[8];
    /*0x08*/ char textureVersion[16];
    /*0x18*/ u32 textureFormat;
    /*0x1C*/ u32 textureType;
    /*0x20*/ u32 unk1;
    /*0x24*/ u16 textureWidth;
    /*0x26*/ u16 textureHeight;
    /*0x28*/ u32 textureOffset;
    /*0x2C*/ u32 textureMipOffset;
    /*0x30*/ u32 textureLevels;
    /*0x34*/ u32 texturePtr;
    /*0x38*/ u32 textureDepth;
    /*0x3C*/ u32 texturePAD[13];

};