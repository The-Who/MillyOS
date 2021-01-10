#ifndef KERNEL_H
#define KERNEL_H

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;

#define VGAddress  0xB8000
#define bufSize    2200

uint16* VGAbuffer;

#define null 0

enum VGAcolor
{
    black,
    blue,
    green,
    cyan,
    red,
    magenta,
    brown,
    lightGray,
    darkGray,
    lightBlue,
    lightGreen,
    lightCyan,
    lightRed,
    lightMagenta,
    yellow,
    white,
};

#endif
