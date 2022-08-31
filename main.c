#include "header.h"

int main(int argc, char *argv[])
{

    /*
     /* USAGE
     /*
     /*
     /*
    */
    BMPIMAGE *image = malloc(sizeof(BMPIMAGE));
    FILE *fptr;
    int flag, w, h;
    unsigned char color[4];


    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "Unable to Open .BMP File %s \n", argv[1]);
        exit(-1);
    }
    else
    {
        printf(".BMP File Initialized %s\n", argv[1]);
    }
    // printf("%d", *fptr);
    if (fread(&(image->fileHeader.signature), sizeof(image->fileHeader.signature), 1, fptr) != 1)
    {
        fprintf(stderr, "Failed to read BMP file header\n");
        exit(-1);
    }
    if (image->fileHeader.signature != 0x4D42) /* 0x4D42 is equals to `BM` */
    {
        fprintf(stderr, "File is not a BMP file\n");
        exit(-1);
    }
    do
    {
        if ((flag = fread(&(image->fileHeader.fileSize), sizeof(image->fileHeader.fileSize), 1, fptr)) != 1)
            break;
        if ((flag = fread(&(image->fileHeader.reserved), sizeof(image->fileHeader.reserved), 1, fptr)) != 1)
            break;
        if ((flag = fread(&(image->fileHeader.dataOffset), sizeof(image->fileHeader.dataOffset), 1, fptr)) != 1)
            break;
        printf("file size is %d Bytes\n", image->fileHeader.fileSize);
        printf("file data offset is %d Bytes\n", image->fileHeader.dataOffset);
    } while (0);
    if (flag != 1)
    {
        fprintf(stderr, "Cannot read data from image \n");
        exit(-1);
    }
    /* Read Info header */
    if (fread(&(image->infoHeader), sizeof(image->infoHeader), 1, fptr) != 1)
    {
        fprintf(stderr, "Failed to read BMP info header\n");
        exit(-1);
    }
    printf("Image Size %d %d (Width - Height) \n", image->infoHeader.width, image->infoHeader.height);
    printf("Used colors %d \n", image->infoHeader.colorsUsed);
    printf("Bit count %d \n", image->infoHeader.bitCount);
    if (image->infoHeader.bitCount < 8)
    {
        printf("Too small image map depth (%d < 8)\n", image->infoHeader.bitCount);
        exit(-1);
    }

    fseek(fptr, image->fileHeader.dataOffset, SEEK_SET);
    if (image->infoHeader.bitCount == 24)
    {
        bmpread = twentyFourBitImage;
    }
    else
        bmpread = eightBitImage;


    for (h = 0; h < image->infoHeader.height; h++)
    {
        for (w = 0; w < image->infoHeader.width; w++)
        {
            bmpread(image, color, fptr);
            //printf("R: %d G: %d B: %d \n", color[1], color[2], color[3]);
            //printf("G: %d", color[0]);
        }
        
    }

    printf("Width: %d Height: %d \n", w, h);

    fclose(fptr);
    free(image);
    free(color);

    return 0;
}
