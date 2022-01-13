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

    if (calcCheckSum((char*)&header, 0x78) != header->checksum)
    {
        return 3;
    }
    return 0;
}


u32 calcCheckSum(char* str, u32 length) {
    u32 sum = 0;
    u32 x = 0;
    u32 i = 0;

    for (i = 0; i < length; str++, i++)
    {
        sum = (sum << 4) + (*str);

        if ((x = sum & 0xF0000000L) != 0)
        {
            sum ^= x|(x >> 18);
        }

        sum &= ~x;
    }

    return sum;
}