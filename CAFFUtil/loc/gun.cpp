#define NUMFILENAMES 0x1
#define NUMFILEPARTS 0x1
#define NUMSECTIONS 0x1
#define UNKNOWNSECTIONCOUNT 4

#include "..\types.h"
#include "..\caff.h"
#include "..\text.h"


extern sCAFFSectionInfo sectioninfoarray[NUMSECTIONS];
extern char fnames[84];
extern char dbname[88];
extern char sectionnames[6];
extern sTEXTfileheader file0data;
extern u32 unknownSection[UNKNOWNSECTIONCOUNT];
extern sTEXTentry textentries[0xE0];
extern u8 dummyfilebyte;

//****************************************************************//
//BEGIN HEADER
//bin offset 0x0
sCAFFheader header = {
    {CAFFMAGIC}, //magic
    CAFFVERSION, //version
    (u32)&sectioninfoarray, //ptrSectionInfo
    0x0E71DEF0, //checksum    NOT ACTUALLY CHECKED IN BEAN!!!
    NUMFILENAMES, //numfilenames
    NUMFILEPARTS, //numfileparts
    { //sCAFFheader.subheader1_1;
       0x0, //unk0x0
       0x0, //unk0x4
       0x0, //count1
       0x0, //count2
    },
    { //sCAFFheader.subheader1_2;
       0x0, //unk0x0
       0x0, //unk0x4
       0x1, //count1
       0x1, //count2
    },
    0x0, //unk0x44
    BIG, //endian
    NUMSECTIONS, //numsections
    0x0, //unk0x4a
    0x0, //unk0x4b
    sizeof(sectionnames), //sizeSectionNames
    { //sCAFFheader.sectionsizeinfo2_1;
       ((u32)&unknownSection-(u32)&sectioninfoarray), //sizeof(section_0) //inflatedSize
       0x0, //unk0x4
       0x0, //unk0x8
       0x0, //unk0xC
       ((u32)&unknownSection-(u32)&sectioninfoarray), //sizeof(section_0) //defaltedSize
    },
    { //sCAFFheader.sectionsizeinfo2_2;
       sizeof(unknownSection), //sizeof(section_1) //inflatedSize
       0x0, //unk0x4
       0x0, //unk0x8
       0x0, //unk0xC
       (u32)sizeof(unknownSection), //sizeof(section_1) //defaltedSize
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
    0, //by
    0x5, //offset
    0x0, //b
    0x1A30, //sizeof(FILES) //length1 u or c
    0x0, //d
    0x0, //e
    0x0, //f
    0x0, //g
    0x1A30, //sizeof(FILES) //length2 u or c
};
//END compiled as seperate file
 
//BEGIN compiled as seperate file
char sectionnames[6] = 
{
    ".data"
};
//END compiled as seperate file
 
//BEGIN compiled as seperate file
#define FNAMESLEN 84
u32 fnamesSize = FNAMESLEN; ////sizeof(fnames)
u32 fnamesOffsets[] = {0x0}; //namesOffsetTable
char fnames[FNAMESLEN] = "D:\\Work\\GoldenEye\\dev\\bean\\Assets\\UberRoot\\loc\\english\\gun\\XENONBETA_v1\\default.str";
//END compiled as seperate file
 
//BEGIN compiled as seperate file
#define DBSTRLEN 88
u32 dbnameSize = DBSTRLEN; //sizeof(dbname)
char dbname[DBSTRLEN] = { "D:\\Work\\GoldenEye\\dev\\bean\\Assets\\UberRoot\\loc\\english\\gun\\XENONBETA_v1\\default.str.adb" };
//END compiled as seperate file
 
//BEGIN compiled as seperate file
sFilePartHeader fileheaders[NUMFILEPARTS] = {
    1, //id
    0, //offset
    ((u32)&dummyfilebyte-(u32)&file0data), //sizeof(FILE_0) //size
    1, //sectionnum
    5, //unk0x10
};
//END compiled as seperate file

//END linked as section_0





//BEGIN linked as section_1
//bin offset 0x168
//BEGIN compiled as seperate file
u32 unknownSection[UNKNOWNSECTIONCOUNT] = {
    0x1, //
    0x1, //
    0x1, //
    0x14, //
};
//END compiled as seperate file

//END linked as section_1

//END SECTIONS
//****************************************************************//











//****************************************************************//
//BEGIN FILES
//bin offset 0x178
//BEGIN FILE_0

//BEGIN compiled as seperate file
sTEXTfileheader file0data = {
    TEXTMAGIC, //magic
    TEXTVERSION, //version
    sizeof(file0data), //ptrsTEXTdataheader
    0x0, //unk0x18
    0x0, //unk0x1C
};
//END compiled as seperate file

//BEGIN compiled as seperate file
sTEXTdataheader lsbdata = {
    LSB2MAGIC, //magic
    0x1000000, //unk0x24
    0x2000000, //unk0x28
    sizeof(lsbdata), //unk0x2C size or ptr to textheader
    0x4, //unk0x30
    sizeof(lsbdata), //unk0x34 size or ptr to textheader 
    0x0, //unk0x38
    0x0, //unk0x3C
    0x0, //unk0x40
};
//END compiled as seperate file

//BEGIN compiled as seperate file
#define NUMTEXTSTRINGS 0xDF
#define NUMTEXTENTRIES NUMTEXTSTRINGS+1
sTEXTentriesheader textheader = {
    sizeof(textentries), //size
    NUMTEXTSTRINGS    //count
};
//END compiled as seperate file

//BEGIN compiled as seperate file
//COMPILED AND LINKED FIRST!!!!!
//.rdata based at 0x00000000
//second column is offset based on char count not bytes 
//wchar_t is 2 bytes
sTEXTentry textentries[NUMTEXTENTRIES] = {
    {0x9800, L"   D5K\n"},
    {0x9801, L"   Issue\n"},
    {0x9802, L"   Mine\n"},
    {0x9803, L"   PP7\n"},
    {0x9804, L"  DD44\n"},
    {0x9805, L"  Gun\n"},
    {0x9806, L"  Knife\n"},
    {0x9807, L"  Mine\n"},
    {0x9808, L" KF7\n"},
    {0x9809, L" Mine\n"},
    {0x980A, L" Rifle\n"},
    {0x980B, L" Rocket\n"},
    {0x980C, L" Shotgun\n"},
    {0x980D, L"(Proximity)\n"},
    {0x980E, L"(Remote)\n"},
    {0x980F, L"(Timed)\n"},
    {0x9810, L"(silenced)\n"},
    {0x9811, L"-\n"},
    {0x9812, L"Assault\n"},
    {0x9813, L"Attract\n"},
    {0x9814, L"Audio Tape\n"},
    {0x9815, L"Automatic Shotgun\n"},
    {0x9816, L"Automatic\n"},
    {0x9817, L"Blackbox\n"},
    {0x9818, L"Blueprints\n"},
    {0x9819, L"Bolt Key\n"},
    {0x981A, L"Bomb Case\n"},
    {0x981B, L"Bomb Defuser\n"},
    {0x981C, L"Briefcase\n"},
    {0x981D, L"Bug Detector\n"},
    {0x981E, L"Bug\n"},
    {0x981F, L"Bungee\n"},
    {0x9820, L"Camera\n"},
    {0x9821, L"Circuit Board\n"},
    {0x9822, L"Clipboard\n"},
    {0x9823, L"Communicator\n"},
    {0x9824, L"Controller\n"},
    {0x9825, L"Cougar Magnum\n"},
    {0x9826, L"Cougar\n"},
    {0x9827, L"Credit Card\n"},
    {0x9828, L"D5K (silenced)\n"},
    {0x9829, L"D5K Deutsche\n"},
    {0x982A, L"DD44 Dostovei\n"},
    {0x982B, L"Dark Glasses\n"},
    {0x982C, L"Dat Tape\n"},
    {0x982D, L"Datathief\n"},
    {0x982E, L"Detonator\n"},
    {0x982F, L"Deutsche\n"},
    {0x9830, L"Door Decoder\n"},
    {0x9831, L"Door Exploder\n"},
    {0x9832, L"Dostovei\n"},
    {0x9833, L"Guidance Data\n"},
    {0x9834, L"Flare Pistol\n"},
    {0x9835, L"Gas Keyring\n"},
    {0x9836, L"Geiger Counter\n"},
    {0x9837, L"Gold Bar\n"},
    {0x9838, L"Gold PP7\n"},
    {0x9839, L"Golden Gun\n"},
    {0x983A, L"GoldenEye Key\n"},
    {0x983B, L"Golden\n"},
    {0x983C, L"Grenade Launcher\n"},
    {0x983D, L"Grenade\n"},
    {0x983E, L"Hand Grenade\n"},
    {0x983F, L"Heroine\n"},
    {0x9840, L"Hunting Knife\n"},
    {0x9841, L"Identifier\n"},
    {0x9842, L"KF7 Soviet\n"},
    {0x9843, L"Key Analyser Case\n"},
    {0x9844, L"Key Analyser\n"},
    {0x9845, L"Keycard\n"},
    {0x9846, L"Knife\n"},
    {0x9847, L"Laser\n"},
    {0x9848, L"Launcher\n"},
    {0x9849, L"Lectre\n"},
    {0x984A, L"Lock Exploder\n"},
    {0x984B, L"Magnet Repel\n"},
    {0x984C, L"Magnum\n"},
    {0x984D, L"Map\n"},
    {0x984E, L"Micro Camera\n"},
    {0x984F, L"Microcode\n"},
    {0x9850, L"Microfilm\n"},
    {0x9851, L"Military Laser\n"},
    {0x9852, L"Military\n"},
    {0x9853, L"Money\n"},
    {0x9854, L"Null\n"},
    {0x9855, L"PP7 (silenced)\n"},
    {0x9856, L"PP7 Special Issue\n"},
    {0x9857, L"PP7 Special\n"},
    {0x9858, L"Phantom\n"},
    {0x9859, L"Piton Gun\n"},
    {0x985A, L"Plans\n"},
    {0x985B, L"Plastique\n"},
    {0x985C, L"Polarized Glasses\n"},
    {0x985D, L"Proximity Mine\n"},
    {0x985E, L"RC-P90\n"},
    {0x985F, L"Red Dossier\n"},
    {0x9860, L"Remote Mine\n"},
    {0x9861, L"Rocket Launcher\n"},
    {0x9862, L"Safecracker Case\n"},
    {0x9863, L"Safecracker\n"},
    {0x9864, L"Shotgun\n"},
    {0x9865, L"Silver PP7\n"},
    {0x9866, L"Sniper Rifle\n"},
    {0x9867, L"Sniper\n"},
    {0x9868, L"Soviet\n"},
    {0x9869, L"Spool Tape\n"},
    {0x986A, L"Spy File\n"},
    {0x986B, L"Klobb\n"},
    {0x986C, L"Staff List\n"},
    {0x986D, L"Suit_lf_hand\n"},
    {0x986E, L"Tank\n"},
    {0x986F, L"Taser\n"},
    {0x9870, L"Throwing Knife\n"},
    {0x9871, L"Throwing\n"},
    {0x9872, L"Timed Mine\n"},
    {0x9873, L"Flag\n"},
    {0x9874, L"US AR33 Assault Rifle\n"},
    {0x9875, L"US AR33\n"},
    {0x9876, L"Unarmed\n"},
    {0x9877, L"Video Tape\n"},
    {0x9878, L"Watch Communicator\n"},
    {0x9879, L"Watch Geiger Counter\n"},
    {0x987A, L"Watch Identifier\n"},
    {0x987B, L"Watch Laser\n"},
    {0x987C, L"Watch Magnet Attract\n"},
    {0x987D, L"Watch Magnet Repel\n"},
    {0x987E, L"Watch Magnet\n"},
    {0x987F, L"Watch\n"},
    {0x9880, L"Weapon Case\n"},
    {0x9881, L"Yale Key\n"},
    {0x9882, L"ZMG (9mm)\n"},
    {0x9883, L"\n"},
    {0x9884, L"ar33\n"},
    {0x9885, L"audio tape\n"},
    {0x9886, L"auto shotgun\n"},
    {0x9887, L"blackbox\n"},
    {0x9888, L"blueprints\n"},
    {0x9889, L"bolt key\n"},
    {0x988A, L"bomb case\n"},
    {0x988B, L"bomb defuser\n"},
    {0x988C, L"briefcase\n"},
    {0x988D, L"bug detector\n"},
    {0x988E, L"bug\n"},
    {0x988F, L"bungee\n"},
    {0x9890, L"camera\n"},
    {0x9891, L"circuit board\n"},
    {0x9892, L"clipboard\n"},
    {0x9893, L"cougar magnum\n"},
    {0x9894, L"credit card\n"},
    {0x9895, L"d5k (silenced)\n"},
    {0x9896, L"d5k\n"},
    {0x9897, L"dark glasses\n"},
    {0x9898, L"dat tape\n"},
    {0x9899, L"datathief\n"},
    {0x989A, L"dd44\n"},
    {0x989B, L"detonator\n"},
    {0x989C, L"door decoder\n"},
    {0x989D, L"door exploder\n"},
    {0x989E, L"guidance data\n"},
    {0x989F, L"flare pistol\n"},
    {0x98A0, L"gas keyring\n"},
    {0x98A1, L"gold bar\n"},
    {0x98A2, L"gold pp7\n"},
    {0x98A3, L"golden gun\n"},
    {0x98A4, L"goldeneye key\n"},
    {0x98A5, L"grenade launcher\n"},
    {0x98A6, L"grenade\n"},
    {0x98A7, L"heroine\n"},
    {0x98A8, L"hunting knife\n"},
    {0x98A9, L"key analyser\n"},
    {0x98AA, L"keycard\n"},
    {0x98AB, L"kf7 soviet\n"},
    {0x98AC, L"laser\n"},
    {0x98AD, L"lectre\n"},
    {0x98AE, L"lock exploder\n"},
    {0x98AF, L"map\n"},
    {0x98B0, L"micro camera\n"},
    {0x98B1, L"microcode\n"},
    {0x98B2, L"microfilm\n"},
    {0x98B3, L"money\n"},
    {0x98B4, L"phantom\n"},
    {0x98B5, L"piton gun\n"},
    {0x98B6, L"plans\n"},
    {0x98B7, L"plastique\n"},
    {0x98B8, L"polarized glasses\n"},
    {0x98B9, L"pp7 (silenced)\n"},
    {0x98BA, L"pp7\n"},
    {0x98BB, L"proximity mine\n"},
    {0x98BC, L"rc-p90\n"},
    {0x98BD, L"red dossier\n"},
    {0x98BE, L"remote mine\n"},
    {0x98BF, L"rocket launcher\n"},
    {0x98C0, L"safecracker\n"},
    {0x98C1, L"shotgun\n"},
    {0x98C2, L"silver pp7\n"},
    {0x98C3, L"sniper rifle\n"},
    {0x98C4, L"spool tape\n"},
    {0x98C5, L"spy file\n"},
    {0x98C6, L"klobb\n"},
    {0x98C7, L"staff list\n"},
    {0x98C8, L"tank\n"},
    {0x98C9, L"taser\n"},
    {0x98CA, L"throwing knife\n"},
    {0x98CB, L"timed mine\n"},
    {0x98CC, L"flag\n"},
    {0x98CD, L"unarmed\n"},
    {0x98CE, L"video tape\n"},
    {0x98CF, L"watch communicator\n"},
    {0x98D0, L"watch geiger counter\n"},
    {0x98D1, L"watch identifier\n"},
    {0x98D2, L"watch laser\n"},
    {0x98D3, L"watch magnet attract\n"},
    {0x98D4, L"watch magnet repel\n"},
    {0x98D5, L"weapon case\n"},
    {0x98D6, L"yale key\n"},
    {0x98D7, L"zmg (9mm)\n"},
    {0x98D8, L"Analysing the GoldenEye key...\n"},
    {0x98D9, L"You do not have the GoldenEye\n key...\n"},
    {0x98DA, L"kill count"},
    {0x98DB, L"died once\n"},
    {0x98DC, L"died"},
    {0x98DD, L"times"},
    {0x98DE, L"suicide count"},
    {0x98DE, 0},
};
//END compiled as seperate file
//END FILE_0

//BEGIN FILE_1 //maybe padding and some addrs above are calculted on that
u8 dummyfilebyte = 0;
//END FILE_1

//END FILES
//****************************************************************//
