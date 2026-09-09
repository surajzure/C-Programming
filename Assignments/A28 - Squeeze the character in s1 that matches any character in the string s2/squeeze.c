/*Name:Suraj sunil zure
date:1/1/2026
Description:
Read two strings s1 and s2 from user.
Remove the characters in s1 that matches with s2.
Input string:
string 1: Dennis Ritchie
string 2: Linux
Output String:
After squeeze s1: Des Rtche
Should not use extra array or the pointer
Inputs: -
String1 and String2
Sample execution: -
Test Case 1:
Enter s1 : Dennis Ritchie
Enter s2 : Linux
After squeeze s1 : Des Rtche
Test Case 2:
Enter s1 : Welcome
Enter s2 : Emertxe
After squeeze s1 : Wlco*/
#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char str1[30], str2[30];

    printf("Enter s1 : ");
    scanf("%[^\n]", str1);

    printf("Enter s2 : ");
    scanf(" %[^\n]", str2);

    squeeze(str1, str2);

    printf("After squeeze s1 : %s\n", str1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int found;

    for (i = 0; s1[i] != '\0'; i++)
    {
        found = 0;

        // Check if s1[i] is present in s2
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                found = 1;
                break;
            }
        }

        // If found, shift characters left
        if (found)
        {
            for (k = i; s1[k] != '\0'; k++)
            {
                s1[k] = s1[k + 1];
            }
            i--;   // recheck current position
        }
    }
}
