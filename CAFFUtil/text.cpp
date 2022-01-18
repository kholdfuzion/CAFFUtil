#include <iostream>
#include <wchar.h>
#include "util.h"
#include "caff.h"
#include "text.h"


const char TEXTMagic[5] = { TEXTMAGIC };  // "text"
const char TEXTVersion[15] = TEXTVERSION;

const char LSB2Magic[4] = { LSB2MAGIC };  // "LSB2"

#define STRINGSLOCATION textFile->header->ptrsTEXTdataheader +  sizeof(sTEXTdataheader) + sizeof(sTEXTentriesheader) + (sizeof(sTEXTentry) * (textFile->entriesheader->count + 1))

s32 TEXT_CheckHeader(const char* buffer)
{

    sTEXTfileheader* header = (sTEXTfileheader*)buffer;
    if (strncmp(header->magic, TEXTMagic, sizeof(TEXTMagic)))
    {
        printf("Invalid TEXT magic\n");
        return 1;
    }
    printf("Valid TEXT magic\n");

    if (strncmp(header->version, TEXTVersion, sizeof(TEXTVersion)))
    {
        printf("Invalid TEXT version\n");
        return 2;
    }
    printf("Valid TEXT version\n");
    return 0;
}

s32 LSB2_CheckHeader(const char* buffer)
{

    sTEXTdataheader* header = (sTEXTdataheader*)buffer;
    if (strncmp(header->magic, LSB2Magic, sizeof(LSB2Magic)))
    {
        printf("Invalid LSB2 magic\n");
        return 1;
    }
    printf("Valid LSB2 magic\n");
    return 0;
}

void TEXT_LoadFile(sCAFFFile* caffFile, sTEXTfile* textFile, const char* buffer)
{
    textFile->header = (sTEXTfileheader*)caffFile->files;
    if (caffFile->header->endian == BIG)
    {
        textFile->header->ptrsTEXTdataheader = ReverseEndianness(textFile->header->ptrsTEXTdataheader);
        textFile->header->unk0x18 = ReverseEndianness(textFile->header->unk0x18);
        textFile->header->unk0x1C = ReverseEndianness(textFile->header->unk0x1C);
    }

    if (!LSB2_CheckHeader(&buffer[textFile->header->ptrsTEXTdataheader]))
    {
        textFile->dataheader = (sTEXTdataheader*)&buffer[textFile->header->ptrsTEXTdataheader];
        if (caffFile->header->endian == BIG)
        {
            textFile->dataheader->unk0x24 = ReverseEndianness(textFile->dataheader->unk0x24);
            textFile->dataheader->unk0x28 = ReverseEndianness(textFile->dataheader->unk0x28);
            textFile->dataheader->unk0x2C = ReverseEndianness(textFile->dataheader->unk0x2C);
            textFile->dataheader->unk0x30 = ReverseEndianness(textFile->dataheader->unk0x30);
            textFile->dataheader->unk0x34 = ReverseEndianness(textFile->dataheader->unk0x34);
            textFile->dataheader->unk0x38 = ReverseEndianness(textFile->dataheader->unk0x38);
            textFile->dataheader->unk0x3C = ReverseEndianness(textFile->dataheader->unk0x3C);
            textFile->dataheader->unk0x40 = ReverseEndianness(textFile->dataheader->unk0x40);
        }
    }

    textFile->entriesheader = (sTEXTentriesheader*)&buffer[textFile->header->ptrsTEXTdataheader + sizeof(sTEXTdataheader)];
    textFile->entriesheader->count = ReverseEndianness(textFile->entriesheader->count);
    textFile->entriesheader->size = ReverseEndianness(textFile->entriesheader->size); //size of lsb2 to end of chunk

    textFile->entries = (sTEXTentry*)&buffer[textFile->header->ptrsTEXTdataheader + sizeof(sTEXTdataheader) + sizeof(sTEXTentriesheader)];
    if (caffFile->header->endian == BIG)
    {
        for (int i = 0; i <= textFile->entriesheader->count; i++)
        {
            textFile->entries[i].id = ReverseEndianness(textFile->entries[i].id);
            textFile->entries[i].offset = ReverseEndianness(textFile->entries[i].offset);
        }
    }
    //- textFile->entriesheader->size -
    textFile->strings = (wchar_t*)&buffer[STRINGSLOCATION];
    if (caffFile->header->endian == BIG)
    {
        for (int i = 0; i < ((textFile->entriesheader->size- (STRINGSLOCATION) )/2); i++)
        {
            textFile->strings[i] = ReverseEndianness((u16)textFile->strings[i]);
        }
    }

    //for (int i = 0; i <= textFile->entriesheader->count-1; i++)
    //{
    //    printf("0x%04x ", textFile->entries[i].id);
    //    wprintf(L"\"%ls \"\n", &textFile->strings[textFile->entries[i].offset]);
    //}
    //printf("");
    printf("LSB2 data loaded\n");
}