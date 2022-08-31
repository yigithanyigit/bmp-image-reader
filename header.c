#include "header.h"

void eightBitImage(BMPIMAGE *image, unsigned char color[], FILE *fptr)
{
    // color[0] is grey for default input
    /*
    /* color[0] -> grey
    /* color[1] -> Red
    /* color[2] -> Green
    /* color[3] -> Blue
    */
    if (fread(color[0], sizeof(unsigned char), 1, fptr) != 1)
    {
        fprintf(stderr, "Image Unreadable \n");
        exit(-1);
    }
}

void twentyFourBitImage(BMPIMAGE *image, unsigned char color[], FILE *fptr)
{
    // color[0] is grey for default input
    /*
    /* color[0] -> grey
    /* color[1] -> Red
    /* color[2] -> Green
    /* color[3] -> Blue
    */
    int flag;
    unsigned char r, g, b;
    do
    {
        /*
        if ((flag = fread(&b, sizeof(unsigned char), 1, fptr)) != 1)
            break;
        if ((flag = fread(&g, sizeof(unsigned char), 1, fptr)) != 1)
            break;
        if ((flag = fread(&r, sizeof(unsigned char), 1, fptr)) != 1)
            break;
        */
        if ((flag = fread(&color[3], sizeof(unsigned char), 1, fptr)) != 1)
        {
            printf("B: %d", color[3]);
            break;
        }

        if ((flag = fread(&color[2], sizeof(unsigned char), 1, fptr)) != 1)
        {
            printf("G: %d", color[2]);
            break;
        }
        if ((flag = fread(&color[1], sizeof(unsigned char), 1, fptr)) != 1)
        {
            printf("R: %d", color[1]);
            break;
        }
        //printf("R: %d \n", color[1]);
       
    } while (0);
    if (flag != 1)
    {
        fprintf(stderr, "An error occured while image reading \n");
        exit(-1);
    }

    // printf("R: %d G: %d B: %d \n", color[1], color[2], color[3]);
    // printf("R: %d G: %d B: %d \n", r, g, b);
}