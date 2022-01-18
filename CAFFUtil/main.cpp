// textextractor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <iostream>
#include "main.h"
#include "file.h"
#include "caff.h"
#include "util.h"
#include "text.h"



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


    sCAFFFile caffFile;
    CAFF_LoadFile(&caffFile, &buffer[0]);

    //BEGIN quick hacky for testing
    //should be proper logic to loop through all filesparts, check .data headers (or find where type is stored) to find loader
    if (!TEXT_CheckHeader((char*)caffFile.files))
    {
        printf("CAFF has TEXT data\n");
        sTEXTfile textfile;
        TEXT_LoadFile(&caffFile, &textfile, (char*)caffFile.files);
        //process loaded text
        //destroy
    }
    //END quick hacky for testing




    //printf("%s\n", caffFile.dbnameArray);


}
