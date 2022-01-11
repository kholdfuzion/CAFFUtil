#pragma once
#include "types.h"
#include "text.h"

#define CAFFMAGIC 0x43, 0x41, 0x46, 0x46
#define CAFFVERSION "07.08.06.0036"

enum ENDIAN {
    LITTLE,
    BIG
};

typedef struct sCAFFsubheader1 {
    u32 unk0x0;
    u32 unk0x4;
    u32 count1;
    u32 count2;
} sCAFFsubheader1;

typedef struct sCAFFsectionsizeinfo {
    u32 inflatedSize;
    u32 unk0x4;
    u32 unk0x8;
    u32 unk0xC;
    u32 defaltedSize; 
} sCAFFsectionsizeinfo;

typedef struct sCAFFSectionInfo {
    u8 by;
    u32 offset;
    u32 b;
    u32 length1;
    u32 d;
    u32 e;
    u32 f;
    u32 g;
    u32 length2;    
} sCAFFSectionInfo;

typedef struct sFilePartHeader{
    u32 id;
    u32 offset;
    u32 size;
    u8 sectionnum;
    u8 unk0x10;
} sFilePartHeader;

typedef struct sCAFFheader {
    u8 magic[4];
    u8 version[16];
    u32 ptrSectionInfo;  //sCAFFSectionInfo* ptrSectionInfo;
    u32 checksum;
    u32 numfilenames;
    u32 numfileparts;
    sCAFFsubheader1 subheader1_1;
    sCAFFsubheader1 subheader1_2;
    u32 unk0x44;
    u8 endian;
    u8 numsections;
    u8 unk0x4a;
    u8 unk0x4b;
    u32 sizeSectionNames;
    sCAFFsectionsizeinfo filesectioninfo;
    sCAFFsectionsizeinfo unknownsectioninfo;
} sCAFFheader;


