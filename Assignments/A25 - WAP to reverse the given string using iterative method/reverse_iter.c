/* Name: Suraj Zure
   Date: 23/12/2025
   Description:
   Read a string from user.
   Reverse the string using RECURSION.
   No loops allowed in reverse function.
   Do not print character by character.
   Sample execution: -
    Test Case 1:
    Enter a string : Hello World
    Reverse string is : dlroW olleH
    Test Case 2:
    Enter a string : EMERTXE
    Reverse string is : EXTREME
*/
#include <stdio.h>

void reverse_iterative(char str[]);

int main()
{
    char str[30];
    
    printf("Enter any string : ");
    scanf("%[^\n]", str);
    
    reverse_iterative(str);
    
    printf("Reversed string is %s\n", str);
}
void reverse_iterative(char str[])
{
    int size=0;
    while(str[size] != '\0')
    {
        size++;
    }
    
    char temp;
    int start=0,end=size-1;
    while(start <end)
    {
        temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start ++;
        end--;
    }
}