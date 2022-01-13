#define NUMFILENAMES 0x4
#define NUMFILEPARTS 0x9
#define NUMSECTIONS 0x3
#define UNKNOWNSECTIONCOUNT 4

#include "..\types.h"
#include "..\caff.h"
#include "..\text.h"
extern char sectionnames[19];

sCAFFheader header = {
    {CAFFMAGIC}, //magic
    CAFFVERSION, //version
    sizeof(header), //ptrSectionInfo
    0x0E65B1C0, //checksum    NOT ACTUALLY CHECKED IN BEAN!!!
    NUMFILENAMES, //numFileNames
    NUMFILEPARTS, //numFileParts
    {
        0x0, //unk0x0
        0x0, //unk0x1
        0x9, //unk0x2
        0x3A, //unk0x3
    },
    {
        0x0, //unk0x0
        0x0, //unk0x1
        0x8, //unk0x2
        0x67, //unk0x3
    },
    0xD, //unk0x44
    BIG, //endian
    NUMSECTIONS, //numsections
    0x0, //isCompressed
    0x2, //unk0x4b
    sizeof(sectionnames), //sizeSectionNames
    {
        sizeof(section_0), //inflated
        0x0, //unk0x4
        0x0, //unk0x8
        0x0, //unk0xC
        sizeof(section_0), //deflated
    },
    {
        sizeof(section_1), //inflated
        0x0, //unk0x4
        0x0, //unk0x8
        0x0, //unk0xC
        sizeof(section_1), //deflated
    }
};
//END HEADER
//****************************************************************//








//****************************************************************//
//BEGIN SECTIONS
//bin offset 0x78


//BEGIN linked as section_0
//BEGIN compiled as seperate file
sCAFFSectionInfo sectioninfoarray[NUMSECTIONS] = 
{
    {
        0, //by
        0xC, //offset
        0x2, //b
        0x5000, //sizeof(FILES) //length1 u or c
        0x0, //d
        0x0, //e
        0x0, //f
        0x0, //g
        0x5000, //sizeof(FILES) //length2 u or c
    },
    {
        0, //by
        0x505, //offset
        0x4, //b
        0x2290, //sizeof(FILES) //length1 u or c
        0x0, //d
        0x0, //e
        0x0, //f
        0x0, //g
        0x2290, //sizeof(FILES) //length2 u or c
    },
    {
        0, //by
        0xB02, //offset
        0x0, //b
        0x3BC, //sizeof(FILES) //length1 u or c
        0x0, //d
        0x0, //e
        0x0, //f
        0x0, //g
        0x3BC, //sizeof(FILES) //length2 u or c
    },
};


char sectionnames[19] = 
{
    ".gpu\0"
    ".data\0"
    ".stream"
};

//BEGIN compiled as seperate file
#define FNAMESLEN 0x121
u32 fnamesSize = FNAMESLEN; ////sizeof(fnames)
u32 fnamesOffsets[] = {0x0, 0x59, 0x5E, 0xBF}; //namesOffsetTable
const char fnames[FNAMESLEN] = 
{
    "C:\\Work\\Rare\\GE\\Src\\Xbox360\\Files\\UberRoot\\original\\prop\\alarm1\\XENONBETA_v1\\default.bin\0"
    "pool\0"
    "C:\\Work\\Rare\\GE\\Src\\Xbox360\\Files\\UberRoot\\original\\prop\\alarm1\\XENONBETA_v1\\_0x0D45BD45.rgb.bin\0"
    "C:\\Work\\Rare\\GE\\Src\\Xbox360\\Files\\UberRoot\\original\\prop\\alarm1\\XENONBETA_v1\\_0x0C9CF895.rgba.bin"
};


#define DBSTRLEN 0x5D
u32 dbnameSize = DBSTRLEN; //sizeof(dbname);
const char dbname[DBSTRLEN] = "C:\\Work\\Rare\\GE\\Src\\Xbox360\\Files\\UberRoot\\original\\prop\\alarm1\\XENONBETA_v1\\default.bin.adb";

