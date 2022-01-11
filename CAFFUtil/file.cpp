#include <iostream>
#include "file.h"

char* openfile(const char* filename)
{
    FILE* fp;
    errno_t err = fopen_s(&fp, filename, "rb");
    if (err != 0)
    {
        printf("Failed to open file %s\n", filename);
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* buffer = (char*)malloc(size);
    if (!buffer)
    {
        printf("Failed to allocate memory for file\n");
        fclose(fp);
        return NULL;
    }

    fread(buffer, size, 1, fp);

    fclose(fp);

    return buffer;
};