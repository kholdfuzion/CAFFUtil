#include <iostream>
#include "util.h"
#include "caff.h"
#include "texture.h"
#include "rgba.h"

const char TEXTUREMagic[8] = { TEXTUREMAGIC };  // "texture"
const char TEXTUREVersion[16] = TEXTUREVERSION;


const char* TEXTURE_GetFormat(u32 format)
{
    switch (format) {
    case 0x1A200152:
        return "D3DFMT_DXT1";
    case 0x1A200153:
        return "D3DFMT_DXT3";
    case 0x1A200154:
        return "D3DFMT_DXT5";
    case 0x1A200171:
        return "D3DFMT_DXN";
    case 0x4900102:
        return "D3DFMT_A8";
    case 0x28000102:
        return "D3DFMT_L8";
    case 0x28280144:
        return "D3DFMT_R5G6B5";
    case 0x28280145:
        return "D3DFMT_R6G5B5";
    case 0x2A200B45:
        return "D3DFMT_L6V5U5";
    case 0x28280143:
        return "D3DFMT_X1R5G5B5";
    case 0x18280143:
        return "D3DFMT_A1R5G5B5";
    case 0x1828014F:
        return "D3DFMT_A4R4G4B4";
    case 0x2828014F:
        return "D3DFMT_X4R4G4B4";
    case 0x1A20AB4F:
        return "D3DFMT_Q4W4V4U4";
    case 0x800014A:
        return "D3DFMT_A8L8";
    case 0x2D20014A:
        return "D3DFMT_G8R8";
    case 0x2D20AB4A:
        return "D3DFMT_V8U8";
    case 0x1A220158:
        return "D3DFMT_D16";
    case 0x28000158:
        return "D3DFMT_L16";
    case 0x2DA2AB5E:
        return "D3DFMT_R16F";
    case 0x2DA2AB5B:
        return "D3DFMT_R16F_EXPAND";
    case 0x1A20014C:
        return "D3DFMT_UYVY";
    case 0x1A20010C:
        return "D3DFMT_LE_UYVY";
    case 0x1828014C:
        return "D3DFMT_G8R8_G8B8";
    case 0x1828014B:
        return "D3DFMT_R8G8_B8G8";
    case 0x1A20014B:
        return "D3DFMT_YUY2";
    case 0x1A20010B:
        return "D3DFMT_LE_YUY2";
    case 0x18280186:
        return "D3DFMT_A8R8G8B8";
    case 0x18280086:
        return "D3DFMT_LIN_A8R8G8B8";
    case 0x28280186:
        return "D3DFMT_X8R8G8B8";
    case 0x1A200186:
        return "D3DFMT_A8B8G8R8";
    case 0x2A200186:
        return "D3DFMT_X8B8G8R8";
    case 0x2A200B86:
        return "D3DFMT_X8L8V8U8";
    case 0x1A20AB86:
        return "D3DFMT_Q8W8V8U8";
    case 0x182801B6:
        return "D3DFMT_A2R10G10B10";
    case 0x282801B6:
        return "D3DFMT_X2R10G10B10";
    case 0x1A2001B6:
        return "D3DFMT_A2B10G10R10";
    case 0x1A202BB6:
        return "D3DFMT_A2W10V10U10";
    case 0x8000199:
        return "D3DFMT_A16L16";
    case 0x2D200199:
        return "D3DFMT_G16R16";
    case 0x2D20AB99:
        return "D3DFMT_V16U16";
    case 0x282801B7:
        return "D3DFMT_R10G11B11";
    case 0x282801B8:
        return "D3DFMT_R11G11B10";
    case 0x2A20ABB7:
        return "D3DFMT_W10V11U11";
    case 0x2A20ABB8:
        return "D3DFMT_W11V11U10";
    case 0x2D22AB9F:
        return "D3DFMT_G16R16F";
    case 0x2D22AB9C:
        return "D3DFMT_G16R16F_EXPAND";
    case 0x280001A1:
        return "D3DFMT_L32";
    case 0x2DA2ABA4:
        return "D3DFMT_R32F";
    case 0x1A20015A:
        return "D3DFMT_A16B16G16R16";
    case 0x1A20AB5A:
        return "D3DFMT_Q16W16V16U16";
    case 0x1A22AB60:
        return "D3DFMT_A16B16G16R16F";
    case 0x1A22AB5D:
        return "D3DFMT_A16B16G16R16F_EXPAND";
    case 0x80001A2:
        return "D3DFMT_A32L32";
    case 0x2D2001A2:
        return "D3DFMT_G32R32";
    case 0x2D20ABA2:
        return "D3DFMT_V32U32";
    case 0x2D22ABA5:
        return "D3DFMT_G32R32F";
    case 0x1A2001A3:
        return "D3DFMT_A32B32G32R32";
    case 0x1A20ABA3:
        return "D3DFMT_Q32W32V32U32";
    case 0x1A22ABA6:
        return "D3DFMT_A32B32G32R32F";
    case 0x28280106:
        return "D3DFMT_LE_X8R8G8B8";
    case 0x18280106:
        return "D3DFMT_LE_A8R8G8B8";
    case 0x28280136:
        return "D3DFMT_LE_X2R10G10B10";
    case 0x18280136:
        return "D3DFMT_LE_A2R10G10B10";
    case 0x1A20017A:
        return "D3DFMT_DXT3A";
    case 0x1A20017D:
        return "D3DFMT_DXT3A_1111";
    case 0x1A20017B:
        return "D3DFMT_DXT5A";
    case 0x1A20017C:
        return "D3DFMT_CTX1";
    case 0x2D200196:
        return "D3DFMT_D24S8";
    case 0x2DA00196:
        return "D3DFMT_D24X8";
    case 0x1A220197:
        return "D3DFMT_D24FS8";
    case 0x1A2201A1:
        return "D3DFMT_D32";

    default:
        return "ERROR NEWFORMAT!!!!!\n";
    }
}

s32 TEXTURE_CheckHeader(const char* buffer)
{

    sTEXTUREFileHeader* header = (sTEXTUREFileHeader*)buffer;
    if (strncmp(header->magic, TEXTUREMagic, sizeof(TEXTUREMagic)))
    {
        printf("Invalid TEXTURE magic\n");
        return 1;
    }
    printf("Valid TEXTURE magic\n");

    if (strncmp(header->version, TEXTUREVersion, sizeof(TEXTUREVersion)))
    {
        printf("Invalid TEXTURE version\n");
        return 2;
    }
    printf("Valid TEXTURE version\n");
    return 0;
}

void TEXTURE_LoadFile(sCAFFFile* caffFile, sTEXTUREFile* textureFile, const char* buffer)
{
    textureFile->header = (sTEXTUREFileHeader* )caffFile->files;
    if(caffFile->header->endian == BIG)
    {
        textureFile->header->Format = ReverseEndianness(textureFile->header->Format);
        textureFile->header->Type = ReverseEndianness(textureFile->header->Type);
        textureFile->header->unk1 = ReverseEndianness(textureFile->header->unk1);
        textureFile->header->Width = ReverseEndianness(textureFile->header->Width);
        textureFile->header->Height = ReverseEndianness(textureFile->header->Height);
        textureFile->header->Offset = ReverseEndianness(textureFile->header->Offset);
        textureFile->header->MipOffset = ReverseEndianness(textureFile->header->MipOffset);
        textureFile->header->Levels = ReverseEndianness(textureFile->header->Levels);
        textureFile->header->Ptr = ReverseEndianness(textureFile->header->Ptr);
        textureFile->header->Depth = ReverseEndianness(textureFile->header->Depth);
    }
    printf("Image Info:\n");
    printf(" Format: %s\n", TEXTURE_GetFormat(textureFile->header->Format));
    printf(" Type: 0x%x\n", textureFile->header->Type);
    printf(" unk1: 0x%x\n", textureFile->header->unk1);
    printf(" Width: %d\n", textureFile->header->Width);
    printf(" Height: %d\n", textureFile->header->Height);
    printf(" Offset: 0x%x\n", textureFile->header->Offset);
    printf(" MipOffset: 0x%x\n", textureFile->header->MipOffset);
    printf(" Levels: 0x%x\n", textureFile->header->Levels);
    printf(" Depth: 0x%x\n", textureFile->header->Depth);
    textureFile->texturedata = (u32*)&buffer[sizeof(sTEXTUREFileHeader)];
}

void TEXTURE_ConvertFile(sTEXTUREFile* texturefile, const char* outfile)
{
    switch(texturefile->header->Format)
    {
    case 0x1A200186:
        RGBA_WRITE_D3DFMT_A8B8G8R8(texturefile, outfile);
    }
}

