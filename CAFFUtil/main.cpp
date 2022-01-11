// textextractor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <iostream>
#include "util.h"


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
}
