/*Name: Suraj Sunil Zure
Date 22/12/2025
Description:int getword(char *word)
Create a function named getword.
Function will receive the string from main
Function should return the length of the first word.
Sampel input and Output:

Enter the string : Welcome to Emertxe
You entered Welcome and the length is 7

Test Case 2:
Enter the string : Hello
You entered Hello and the length is 5*/
#include <stdio.h>

int getword(char str[]);

int main()
{
    int len = 0;
    char str[100];

    scanf(" %[^\n]", str);

    len = getword(str);

    printf("You entered ");
    for(int i = 0; i < len; i++)
    {
     printf("%c", str[i]);
    }
    printf(" and the length is %d\n", len);

}

int getword(char str[])
{
    int len = 0;
    while(str[len] != '\0' && str[len] != ' ')
    {
        len++;
    }
    return len;
}
