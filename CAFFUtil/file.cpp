#include <iostream>
#include "types.h"
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

int writefile(const char* filename, const char* buffer, u32 size)
{
    FILE* fp;
    errno_t err = fopen_s(&fp, filename, "w+");
    if (err != 0)
    {
        printf("Failed to open file %s\n", filename);
        return err;
    }

    if (!buffer)
    {
        printf("Failed to pass buffer for file\n");
        fclose(fp);
        return 1;
    }
    fwrite(buffer, size, 1, fp);

    fclose(fp);

    return 0;
}