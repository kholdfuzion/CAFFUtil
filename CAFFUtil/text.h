#pragma once
#include "types.h"

#define TEXTMAGIC "text"
#define TEXTVERSION "02.09.05.0034"
#define LSB2MAGIC 0x4c, 0x53, 0x42, 0x32

typedef struct sTEXTheader1 {
    u8 magic[5];
    u8 version[15];
    u32 ptrsTEXTheader2;
    u32 unk0x18;
    u32 unk0x1C;
} sTEXTheader1;

typedef struct sTEXTheader2 {
    char magic[4];
    u32 unk0x24;
    u32 unk0x28;
    u32 unk0x2C;
    u32 unk0x30;
    u32 unk0x34;
    u32 unk0x38;
    u32 unk0x3C;
    u32 unk0x40;
    u32 size;
    u32 count;
} sTEXTheader2;

typedef struct sTEXTentry {
    u16 id;
    const wchar_t* textstring;
} sTEXTentry;


