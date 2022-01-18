#pragma once
#include "types.h"


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
    u32 deflatedSize; 
} sCAFFsectionsizeinfo;

#pragma pack( 1 )
typedef struct sCAFFSectionInfo {
    u8 by:8;
    u32 offset;
    u32 b;
    u32 length1;
    u32 d;
    u32 e;
    u32 f;
    u32 g;
    u32 length2;    
} sCAFFSectionInfo;

#pragma pack( 1 )
typedef struct sFilePartHeader{
    u32 id;
    u32 offset;
    u32 size;
    u8 sectionnum;
    u8 unk0x10;
} sFilePartHeader;

#pragma pack( 1 )
typedef struct sCAFFheader {
    char magic[4];
    char version[16];

    u32 ptrSections;  //u8* SECTIONS;
    u32 checksum;
    u32 numAssets;
    u32 numSections;
    sCAFFsubheader1 subheader1_1;
    sCAFFsubheader1 subheader1_2;
    u32 unk0x44;
    u8 endian;
    u8 numAllocations;
    u8 isCompressed;
    u8 unk0x4b;
    u32 sizeSectionNames;
    sCAFFsectionsizeinfo filesectioninfo;
    sCAFFsectionsizeinfo unknownsectioninfo;
} sCAFFheader;

typedef struct sCAFFFile {
    sCAFFheader* header;
    sCAFFSectionInfo* sectioninfo;
    char* sectionnames;
    u32 fnamesSize;
    u32* fnamesOffsets;
    char* fnamesArray;
    u32 dbnameSize;
    char* dbnameArray;
    sFilePartHeader* filepartheaders;
    u32* unknownsection;
    void* files;
} sCAFFSection;

s32 CAFF_CheckHeader(const char* buffer);
u32 elfhash(char* buffer, u32 len);
void CAFF_FixupHeader(sCAFFheader* header);
void CAFF_FixupSectionInfo(sCAFFSectionInfo* sectioninfo);
void CAFF_FixupFilePartHeader(sFilePartHeader* filepartheader);
void CAFF_LoadFile(sCAFFFile* caffFile, char* buffer);
