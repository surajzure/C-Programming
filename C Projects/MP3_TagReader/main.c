/*
  File Name     : main.c
  Description   : Entry point of the MP3 Tag Reader and Editor project.
                  This file handles command line arguments and decides
                  whether the program runs in view mode, edit mode, or help mode.

  Project Title : MP3 Tag Reader and Editor
  Name          : Suraj zure
  Date          : 09/06/2026
*/

#include <stdio.h>
#include <string.h>

/*Function declarations*/
void view(const char *filename);
void edit(const char *tar_tag, const char *new_name, const char *filename);
void help();

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("ERROR: No arguments provided\n");
        printf("Use '--help' for usage information\n");
        return 0;
    }

    if(strcmp(argv[1], "--help") == 0)
    {
        printf("\n------ MP3 TAG READER / EDITOR HELP ------\n");
        help();
        return 0;
    }

    if(strcmp(argv[1], "-v") == 0)
    {
        if(argc < 3)
        {
            printf("Usage: ./a.out -v <filename.mp3>\n");
            return 0;
        }

        if(strstr(argv[2], ".mp3") == NULL)
        {
            printf("ERROR: Input file must have .mp3 extension\n");
            return 0;
        }
        printf("Read and validation successful...\n");

        view(argv[2]);
        return 0;
    }

    if(strcmp(argv[1], "-e") == 0)
    {
        if(argc < 5)
        {
            printf("Input commands are not added correctly\n");
            printf("Usage: ./a.out -e <tag> new_name filename.mp3\n");
            return 0;
        }

        if (strstr(argv[4], ".mp3") == NULL)
        {
            printf("ERROR: Input file must have .mp3 extension\n");
            return 0;
        }

        if (strcmp(argv[2], "-t") == 0)
        {
            printf("Editing Title...\n");
            edit("TIT2", argv[3], argv[4]);
        }
        else if (strcmp(argv[2], "-a") == 0)
        {
            printf("Editing Artist...\n");
            edit("TPE1", argv[3], argv[4]);
        }
        else if (strcmp(argv[2], "-A") == 0)
        {
            printf("Editing Album...\n");
            edit("TALB", argv[3], argv[4]);
        }
        else if (strcmp(argv[2], "-y") == 0)
        {
            printf("Editing Year...\n");
            edit("TYER", argv[3], argv[4]);
        }
        else if (strcmp(argv[2], "-c") == 0)
        {
            printf("Editing Composer...\n");
            edit("TCOM", argv[3], argv[4]);
        }
        else if (strcmp(argv[2], "-m") == 0)
        {
            printf("Editing Genre...\n");
            edit("TCON", argv[3], argv[4]);
        }
        else
        {
            printf("ERROR: Invalid tag option\n");
        }

        return 0;

    }
    printf("ERROR : ./a.out -> INVALID ARGUMENTS\n");
    printf("To view  -> ./a.out -v filename.mp3\n");
    printf("To edit  -> ./a.out -e -t/-a/-A/-m/-y/-c 'new_name' filename.mp3\n");
    printf("For help -> ./a.out --help\n");

    return 0;


}
