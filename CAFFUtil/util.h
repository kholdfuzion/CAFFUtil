#pragma once
#include "types.h"


inline u16 ReverseEndianness(u16 in)
{
    u16 out;
    ((u8*)&out)[0] = ((u8*)&in)[1];
    ((u8*)&out)[1] = ((u8*)&in)[0];
    return out;
}

inline u32 ReverseEndianness(u32 in)
{
    u32 out;
    ((u8*)&out)[0] = ((u8*)&in)[3];
    ((u8*)&out)[1] = ((u8*)&in)[2];
    ((u8*)&out)[2] = ((u8*)&in)[1];
    ((u8*)&out)[3] = ((u8*)&in)[0];
    return out;
}
inline u32 Readu32(u8 in)
{
    u32 out;
    ((u8*)&out)[0] = ((u8*)&in)[0];
    ((u8*)&out)[1] = ((u8*)&in)[1];
    ((u8*)&out)[2] = ((u8*)&in)[2];
    ((u8*)&out)[3] = ((u8*)&in)[3];
    return out;
}
