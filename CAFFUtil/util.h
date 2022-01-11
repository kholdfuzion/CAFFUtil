#pragma once
#include <windows.h>
#include <iostream>
const int EXITCODE_SUCCESS = 0;
const int EXITCODE_FAILURE = 1;

inline WORD ReverseEndianness(WORD in)
{
    WORD out;
    ((BYTE*)&out)[0] = ((BYTE*)&in)[1];
    ((BYTE*)&out)[1] = ((BYTE*)&in)[0];
    return out;
}

inline DWORD ReverseEndianness(DWORD in)
{
    DWORD out;
    ((BYTE*)&out)[0] = ((BYTE*)&in)[3];
    ((BYTE*)&out)[1] = ((BYTE*)&in)[2];
    ((BYTE*)&out)[2] = ((BYTE*)&in)[1];
    ((BYTE*)&out)[3] = ((BYTE*)&in)[0];
    return out;
}
inline DWORD ReadDWORD(BYTE in)
{
    DWORD out;
    ((BYTE*)&out)[0] = ((BYTE*)&in)[0];
    ((BYTE*)&out)[1] = ((BYTE*)&in)[1];
    ((BYTE*)&out)[2] = ((BYTE*)&in)[2];
    ((BYTE*)&out)[3] = ((BYTE*)&in)[3];
    return out;
}
