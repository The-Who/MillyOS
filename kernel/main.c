#include "screen/colors.h"

uint16 VGAentry(unsigned char character, uint8 foreColor, uint8 backColor) 
{
    uint16 ax = 0;

    uint8 ah = 0;
    uint8 al = 0;

    ah   = backColor;
    ah <<= 4;
    ah  |= foreColor;

    ax   = ah;
    ax <<= 8;
    ax  |= al;

    al = character;

    return ax;
}

void clearVGAbuffer(uint16 **buffer, uint8 foreColor, uint8 backColor)
{
    uint32 i;

    for(i = 0; i < bufSize; i++)
    {
        (*buffer)[i] = VGAentry(null, foreColor, backColor);
    }
}

void startVGA(uint8 foreColor, uint8 backColor)
{
    VGAbuffer = (uint16*)VGAddress;
    clearVGAbuffer(&VGAbuffer, foreColor, backColor);
}

void startPoint()
{
    startVGA(white, black);

    VGAbuffer[0] = VGAentry('W', white, black);
    VGAbuffer[1] = VGAentry('e', red, black);
    VGAbuffer[2] = VGAentry('l', blue, black);
    VGAbuffer[3] = VGAentry('c', yellow, black);
    VGAbuffer[4] = VGAentry('o', magenta, black);
    VGAbuffer[5] = VGAentry('m', cyan, black);
    VGAbuffer[6] = VGAentry('e', brown, black);
    VGAbuffer[7] = VGAentry('!', lightGray, black);
}
