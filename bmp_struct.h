#pragma once

#define BF_TYPE 0x4D42

#pragma pack(push,1)

typedef int FXPT2DOT30;
 
struct CIEXYZ
{
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
};
 
struct CIEXYZTRIPLE
{
    CIEXYZ  ciexyzRed; 
    CIEXYZ  ciexyzGreen; 
    CIEXYZ  ciexyzBlue; 
};

struct BitmapFileHeader
{
    unsigned short Type;
    unsigned int Size;
    unsigned short Reserve1;
    unsigned short Reserve2;
    unsigned int OffBits;
};

struct BitmapInfoHeader
{
    unsigned int   Size;
    unsigned int   Width;
    unsigned int   Height;
    unsigned short Planes;
    unsigned short BitCount;
    unsigned int   Compression;
    unsigned int   SizeImage;
    unsigned int   XPelsPerMeter;
    unsigned int   YPelsPerMeter;
    unsigned int   ColorUsed;
    unsigned int   ColorImportant;
    unsigned int   RedMask;
    unsigned int   GreenMask;
    unsigned int   BlueMask;
    unsigned int   AlphaMask;
    unsigned int   CSType;
    CIEXYZTRIPLE   Endpoints;
    unsigned int   GammaRed;
    unsigned int   GammaGreen;
    unsigned int   GammaBlue;
    unsigned int   Intent;
    unsigned int   ProfileData;
    unsigned int   ProfileSize;
    unsigned int   Reserved;
};

struct Pixel
{
    unsigned char A;
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

#pragma pack(pop)