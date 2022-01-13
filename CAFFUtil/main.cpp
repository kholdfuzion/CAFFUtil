// textextractor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <iostream>
#include "main.h"
#include "file.h"
#include "caff.h"


void printusage(void)
{
        printf("USAGE: CAFFUtil.exe <CAFF file>\n");
}

int _cdecl main(int argc, char* argv[])
{
    printf("Caff Tool\n");

    if (argc != 2)
    {
        printusage();
        return EXITCODE_FAILURE;
    }
    char* buffer = openfile(argv[1]);
    if(!buffer) {
        printf("failed to open file");
    }
    int headercode= CAFF_CheckHeader(&buffer[0]);
    if (headercode)
    {
        printf("bad header! code: %d", headercode);
    }


}
