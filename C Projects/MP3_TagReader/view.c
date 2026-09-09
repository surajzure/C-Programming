#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global file pointer so it can be used in multiple functions */
FILE *fp;

unsigned int reverse_v(unsigned int size)
{
    return ((size >> 24) & 0xFF) |
           ((size >> 8) & 0xFF00) |
           ((size << 8) & 0xFF0000) |
           ((size << 24) & 0xFF000000);
}

void display_mp3()
{
    printf("-------------------------------------------------------------\n");

    for(int choice = 0; choice < 6; choice++)
    {
        char id[5];
        unsigned int size;

        /* fp works as it it global variable*/
        /* it will read 4 bytes of ID and added \0 at 4th index to read as string*/
        fread(id, 1, 4, fp);
        id[4] = '\0';

        /* read the 4 bytes of size and reverse as ID3 v2.3 stores size in big endian format */
        fread(&size, 4, 1, fp);
        size = reverse_v(size);

        /* Skip 2 bytes of frame flags */
        fseek(fp, 2, SEEK_CUR);

        /* Allocate memory to store frame data */
        char *data = malloc(size + 1);

        fread(data, 1, size, fp);
        data[size] = '\0';

        switch(choice)
        {
            case 0:
                printf("TITLE   : %s\n", data + 1);
                break;

            case 1:
                printf("ARTIST  : %s\n", data + 1);
                break;

            case 2:
                printf("ALBUM   : %s\n", data + 1);
                break;

            case 3:
                printf("YEAR    : %s\n", data + 1);
                break;

            case 4:
                printf("CONTENT : %s\n", data + 1);
                break;

            case 5:
                printf("COMMENT : %s\n", data + 1);
                break;
        }

        free(data);
    }

    printf("-------------------------------------------------------------\n");
}

void view(const char *filename)
{
    printf("VIEW MODE STARTED...\n");

    fp = fopen(filename, "rb");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    printf("File opened successfully...\n");

    char tag[4];

    /* Reading first 3 bytes to check ID3 tag */
    fread(tag, 1, 3, fp);
    tag[3] = '\0';

    printf("MP3 Tag is %s\n", tag);

    unsigned char version[2];

    fread(version, 1, 2, fp);

    printf("ID3 tag version is 2.%d.%d\n",
            version[0],
            version[1]);

    /* Move file pointer to start of metadata frames */
    fseek(fp, 10, SEEK_SET);

    display_mp3();

    fclose(fp);
}