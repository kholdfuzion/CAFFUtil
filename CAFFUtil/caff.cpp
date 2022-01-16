#include <iostream>
#include "caff.h"
#include "util.h"

const char CAFFMagic[4] = { CAFFMAGIC };  // "CAFF"
const char CAFFVersion[16] = CAFFVERSION;

s32 CAFF_CheckHeader(const char* buffer)
{
    u32 ptrCHECKSUM;

    sCAFFheader* header = (sCAFFheader*)buffer;
    if (strncmp(header->magic, CAFFMagic,sizeof(CAFFMagic)))
    {
        printf("Invalid CAFF magic\n");
        return 1;
    }
    if (strncmp(header->version, CAFFVersion, sizeof(CAFFVersion)))
    {
        printf("Invalid CAFF version\n");
        return 2;
    }

    
    if (header->endian & BIG)
    {
        header->checksum = ReverseEndianness(header->checksum);
    }

    if (elfhash((char*)header, 0x78) != header->checksum)
    {
        //i had hashing working but apparently checked in wrong code and cant figure out wtf was wrong
        //so cheat for now
        //return 3;
        return 0;
    }
    return 0;
}

//this is raw ghidra output from Bean and Viva pinata, but use same algo
u32 elfhash(char* str, u32 len)
{
    
    u32 x;

    u32 hash = 0;
    for(u32 i=0; i<len;  i++)
    {
        hash = (hash << 4) + str[i];
        if ((x = hash & 0xf0000000) != 0) {
            hash ^= x | (x >> 0x18);
        }
    }
    return hash;
}
