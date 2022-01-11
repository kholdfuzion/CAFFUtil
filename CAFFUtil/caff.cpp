#include <iostream>
#include "caff.h"

sCAFFheader* CAFF_LoadHeader(const char* buffer)
{
    sCAFFheader* header = (sCAFFheader*)buffer;
    if (header->magic != (u8*)(CAFFMAGIC))
    {
        printf("Invalid CAFF file\n");
        return NULL;
    }
    return header;
}
