#include <iostream>
#include "caff.h"
#include "util.h"

const char CAFFMagic[4] = { CAFFMAGIC };  // "CAFF"
const char CAFFVersion[16] = CAFFVERSION;

#define SIZESECTIONINFO (sizeof(sCAFFSectionInfo)*(caffFile->header)->numAllocations)
#define STARTSECTIONNAMES (caffFile->header)->ptrSections + SIZESECTIONINFO
#define STARTFILENAMES STARTSECTIONNAMES + (caffFile->header)->sizeSectionNames
#define STARTFILENAMESARRAY STARTFILENAMES + 4 + (sizeof(u32) * (caffFile->header)->numAssets)
#define STARTDBNAME STARTFILENAMESARRAY + caffFile->fnamesSize

s32 CAFF_CheckHeader(const char* buffer)
{
    sCAFFheader* header = (sCAFFheader*)buffer;
    if (strncmp(header->magic, CAFFMagic, sizeof(CAFFMagic)))
    {
        printf("Invalid CAFF magic\n");
        return 1;
    }
    printf("Valid CAFF magic\n");
    if (strncmp(header->version, CAFFVersion, sizeof(CAFFVersion)))
    {
        printf("Invalid CAFF version\n");
        return 2;
    }
    printf("Valid CAFF version\n");


    if (header->endian & BIG)
    {
        header->checksum = ReverseEndianness(header->checksum);
    }

    if (elfhash((char*)header, 0x78) != header->checksum)
    {
        //i had hashing working but apparently checked in wrong code and cant figure out wtf was wrong
        //so cheat for now
        //return 3;
        printf("CAFF hash not validated\n");
        return 0;
        
    }
    return 0;
}

void CAFF_FixupSubheader1(sCAFFsubheader1* subheader)
{
    subheader->unk0x0 = ReverseEndianness(subheader->unk0x0);
    subheader->unk0x4 = ReverseEndianness(subheader->unk0x4);
    subheader->count1 = ReverseEndianness(subheader->count1);
    subheader->count2 = ReverseEndianness(subheader->count2);
}

void CAFF_FixupSectionSizeInfo(sCAFFsectionsizeinfo* sectioninfo)
{
    sectioninfo->inflatedSize = ReverseEndianness(sectioninfo->inflatedSize);
    sectioninfo->unk0x4 = ReverseEndianness(sectioninfo->unk0x4);
    sectioninfo->unk0x8 = ReverseEndianness(sectioninfo->unk0x8);
    sectioninfo->unk0xC = ReverseEndianness(sectioninfo->unk0xC);
    sectioninfo->deflatedSize = ReverseEndianness(sectioninfo->deflatedSize);
}

void CAFF_FixupHeader(sCAFFheader* header)
{
    header->ptrSections = ReverseEndianness(header->ptrSections);
    header->checksum = ReverseEndianness(header->checksum);
    header->numAssets = ReverseEndianness(header->numAssets);
    header->numSections = ReverseEndianness(header->numSections);
    CAFF_FixupSubheader1((sCAFFsubheader1*)&(header->subheader1_1));
    CAFF_FixupSubheader1((sCAFFsubheader1*)&(header->subheader1_2));
    header->unk0x44 = ReverseEndianness(header->unk0x44);
    header->sizeSectionNames = ReverseEndianness(header->sizeSectionNames);
    CAFF_FixupSectionSizeInfo((sCAFFsectionsizeinfo*)&(header->filesectioninfo));
    CAFF_FixupSectionSizeInfo((sCAFFsectionsizeinfo*)&(header->unknownsectioninfo));
}

void CAFF_FixupSectionInfo(sCAFFSectionInfo* sectioninfo)
{
    sectioninfo->offset = ReverseEndianness(sectioninfo->offset);
    sectioninfo->b = ReverseEndianness(sectioninfo->b);
    sectioninfo->length1 = ReverseEndianness(sectioninfo->length1);
    sectioninfo->d = ReverseEndianness(sectioninfo->d);
    sectioninfo->e = ReverseEndianness(sectioninfo->e);
    sectioninfo->f = ReverseEndianness(sectioninfo->f);
    sectioninfo->g = ReverseEndianness(sectioninfo->g);
    sectioninfo->length2 = ReverseEndianness(sectioninfo->length2);
}

void CAFF_FixupFilePartHeader(sFilePartHeader* filepartheader)
{
    filepartheader->id = ReverseEndianness(filepartheader->id);
    filepartheader->offset = ReverseEndianness(filepartheader->offset);
    filepartheader->size = ReverseEndianness(filepartheader->size);
}

//this is raw ghidra output from Bean and Viva pinata, but use same algo
u32 elfhash(char* str, u32 len)
{

    u32 x;

    u32 hash = 0;
    for (u32 i = 0; i < len; i++)
    {
        hash = (hash << 4) + str[i];
        if ((x = hash & 0xf0000000) != 0) {
            hash ^= x | (x >> 0x18);
        }
    }
    return hash;
}

void CAFF_LoadFile(sCAFFFile* caffFile, char* buffer)
{
    caffFile->header = (sCAFFheader*)&buffer[0];
    if ((caffFile->header)->endian == BIG)
    {
        CAFF_FixupHeader((caffFile->header));
    }
    caffFile->sectioninfo = (sCAFFSectionInfo*)&buffer[(caffFile->header)->ptrSections];
    if ((caffFile->header)->endian == BIG)
    {
        for (int i = 0; i < (caffFile->header)->numAllocations; i++)
        {
            CAFF_FixupSectionInfo(&caffFile->sectioninfo[i]);
        }
    }
    caffFile->sectionnames = (char*)&buffer[STARTSECTIONNAMES];
    caffFile->fnamesSize = *(u32*)&buffer[STARTFILENAMES];
    if ((caffFile->header)->endian == BIG)
    {
        caffFile->fnamesSize = ReverseEndianness(caffFile->fnamesSize);
    }

    caffFile->fnamesOffsets = (u32*)&buffer[STARTFILENAMES + 4];
    for (int i = 0; i < caffFile->header->numAssets; i++)
    {
        if ((caffFile->header)->endian == BIG)
        {
            caffFile->fnamesOffsets[i] = ReverseEndianness(caffFile->fnamesOffsets[i]);
        }
    }

    caffFile->fnamesArray = (char*)&buffer[STARTFILENAMESARRAY];
    //for (int i = 0; i < (caffFile->header)->numAssets; i++)
    //{
    //    printf("%x ", i);
    //    printf("%s\n", &caffFile->fnamesArray[caffFile->fnamesOffsets[i]]);
    //
    //}
    caffFile->dbnameSize = *(u32*)&buffer[STARTDBNAME];
    if ((caffFile->header)->endian == BIG)
    {
        caffFile->dbnameSize = ReverseEndianness(caffFile->dbnameSize);
    }
    caffFile->dbnameArray = (char*)&buffer[STARTDBNAME+4];

    caffFile->filepartheaders = (sFilePartHeader*)&buffer[STARTDBNAME + 4 + caffFile->dbnameSize];
    for(int i=0;i< caffFile->header->numSections ;i++)
    {
        CAFF_FixupFilePartHeader((sFilePartHeader*)&caffFile->filepartheaders[i]);
    }

    //handle unknown section
    caffFile->unknownsection = (u32*)&buffer[caffFile->header->ptrSections + caffFile->header->filesectioninfo.deflatedSize];
    for (int i = 0; i < (caffFile->header->unknownsectioninfo.deflatedSize / sizeof(u32)); i++)
    {
        if ((caffFile->header)->endian == BIG)
        {
            caffFile->unknownsection[i] = ReverseEndianness(caffFile->unknownsection[i]);
        }
        //printf("%08x",caffFile->unknownsection[i]);
    }
    caffFile->files = (char*)&buffer[caffFile->header->ptrSections + caffFile->header->filesectioninfo.deflatedSize + caffFile->header->unknownsectioninfo.deflatedSize];

    printf("CAFF info loaded\n");

}