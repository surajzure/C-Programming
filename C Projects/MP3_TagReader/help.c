#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void help()
{
    printf("-----------------------------------------------------------------------------\n");

    /* Showing that help section is started */
    printf("HELP MODE STARTED\n");

    /* Instructions for viewing MP3 metadata */
    printf( "TO View the details:\n");
    printf("./a.out -v filename.mp3\n");

    /* Instructions for editing MP3 metadata */
    printf("\nTo edit the details:\n");
    printf("USAGE :\n\t ./a.out -e -t/-a/-A/-y/-m/-c 'new name' filename.mp3\n");

    /* Explanation of each edit option */
    printf("-t\t : Modify a title\n");     
    printf("-a\t : Modify an Artist name\n");     
    printf("-A\t : Modify an Album name\n");     
    printf("-y\t : Modify a Year\n"); 
    printf("-m\t : Modify a Content\n");  
    printf("-c\t : Modify a comment\n");     

    printf("-----------------------------------------------------------------------------\n");
    
    return;
}