#include <stdio.h>
#include <stdlib.h>

//http://www.ue.eti.pg.gda.pl/fpgalab/zadania.spartan3/zad_vga_struktura_pliku_bmp_en.html
//https://en.wikipedia.org/wiki/BMP_file_format
//https://programmer.ink/think/bmp-image-reading.html


typedef struct
{
    unsigned short signature;
    unsigned int fileSize;
    unsigned int reserved;
    unsigned int dataOffset;  
} BITMAPFILEHEADER;

typedef struct 
{
    unsigned int size;
    unsigned int width, height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int imageSize; /* Compressed image size. */
    int xPixelsPerM; /* Horizontal Resolution */
    int yPixelsPerM; /* Vertical Resolution */
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} BITMAPINFOHEADER;

typedef struct 
{
    unsigned char r,g,b,reserved;
} COLORTABLE;

typedef struct 
{
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    COLORTABLE colorTable;
} BMPIMAGE;


void (*bmpread)();
void eightBitImage(BMPIMAGE* image, unsigned char  color[], FILE *fptr); /* color parameter for grey or grey rgb */ 
void twentyFourBitImage(BMPIMAGE* image, unsigned char  color[], FILE *fptr);

