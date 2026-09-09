/*
Name : Suraj Zure
Date;
Description:
Read the N name from the user
Sort it in alphabetical order
Use 1st dynamic and 2nd static. Char (*name)[20]
No.of names should be dynamic and no.of characters should be static.
Allocate the memory dynamically for no.of names.
Sample execution: -
Enter the size: 5
Enter the 5 names of length max 20 characters in each
[0] -> Delhi
[1] -> Agra
[2] -> Kolkata
[3] -> Bengaluru
[4] -> Chennai

The sorted names are:
Agra
Bengaluru
Chennai
Delhi
Kolkata*/
#include <stdio.h>
#include <stdlib.h>
/* Function declarations */
void read_names(char (*name)[20], int n);
void sort_names(char (*name)[20], int n);
void print_names(char (*name)[20], int n);
int compare(char *s1, char *s2);
void copy(char *dest, char *src);

int main()
{
    int n;

    printf("Enter the size: ");
    scanf("%d", &n);

    /* Dynamic allocation for number of names */
    char (*name)[20] = malloc(n * sizeof(*name));

    if (name == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("\nEnter the %d names of length max 20 characters in each\n", n);

    read_names(name, n);

    sort_names(name, n);

    printf("\nThe sorted names are:\n");
    print_names(name, n);

    free(name);

    return 0;
}

/* Read names */
void read_names(char (*name)[20], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d] -> ", i);
        scanf("%19s", name[i]);
    }
}

/* Manual string comparison */
int compare(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;

        i++;
    }

    /* If one string ends */
    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;
    else if (s1[i] == '\0')
        return -1;
    else
        return 1;
}

/* Manual string copy */
void copy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/* Sort names alphabetically */
void sort_names(char (*name)[20], int n)
{
    char temp[20];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compare(name[i], name[j]) > 0)
            {
                copy(temp, name[i]);
                copy(name[i], name[j]);
                copy(name[j], temp);
            }
        }
    }
}

/* Print names */
void print_names(char (*name)[20], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", name[i]);
    }
}