#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to reverse byte order (Big Endian <-> Little Endian) */
unsigned int reverse(unsigned int n)
{
    return ((n >> 24) & 0xFF) |
           ((n >> 8) & 0xFF00) |
           ((n << 8) & 0xFF0000) |
           ((n << 24) & 0xFF000000);
}

void edit(char *target_tag, char *new_data, char *filename)
{
    /* Open original MP3 file in binary read mode */
    FILE *src = fopen(filename, "rb");
    if(src == NULL)
    {
        printf("Cannot open the Source file\n");
        return;
    }

    /* Create temporary file to store modified data */
    FILE *temp = fopen("temp.mp3", "wb");

    if(temp == NULL)
    {
        printf("Cannot create temporary file\n");
        return;
    }

    char header[10];

    if (fread(header, 1, 10, src) != 10)
    {
        printf("Failed in reading header\n");
        fclose(src);
        fclose(temp);
        return;
    }
    fwrite(header, 1, 10, temp);

    while(1)
    {
        char tag[4];
        char flags[2];
        unsigned int size;

        /* Read frame tag */
        if(fread(tag, 1, 4, src) != 4)
            break;

        /* Read frame size */
        if (fread(&size, 4, 1, src) != 1) 
        break;

        /* Read frame flags */
        if (fread(flags, 1, 2, src) != 2) 
        break;

        size = reverse(size);

        if(size == 0)
            break;

        char *data = malloc(size);
        if (data == NULL)
        {
            printf("Memory allocation failed\n");
            break;
        }

        if (fread(data, 1, size, src) != size)
        {
            free(data);
            break;
        }

        if(strncmp(tag, target_tag, 4) == 0)
        {
            unsigned int temp_size = reverse(size);

            fwrite(tag, 1, 4, temp);
            fwrite(&temp_size, 4, 1, temp);
            fwrite(flags, 1, 2, temp);

            data[0] = 0;

            strncpy(data + 1, new_data, size - 1);

            fwrite(data, 1, size, temp);

            printf("Tag Updated Successfully\n");
        }
        else
        {
            unsigned int temp_size = reverse(size);

            fwrite(tag, 1, 4, temp);
            fwrite(&temp_size, 4, 1, temp);
            fwrite(flags, 1, 2, temp);
            fwrite(data, 1, size, temp);
        }

        free(data);
    }

    char ch;

    while((ch = fgetc(src)) != EOF)
    {
        fputc(ch, temp);
    }

    fclose(src);
    fclose(temp);

    remove(filename);
    rename("temp.mp3", filename);

    printf("Editing Done\n");
}