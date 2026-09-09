/* Name: Suraj sunil zure
Date:06/12/2025
Description:checks for a lower case alphabet whether entered character is between 'a' to 'z'.
Sample input and output:
Enter the character: a
Entered character is lower case alphabet
Test Case 2:
Enter the character:3
Entered character is not lower case alphabet*/
#include <stdio.h>

int my_islower(int);

int main()
{
    char ch;
    int ret;
    
    printf("Enter the character:\n");
    scanf("%c", &ch);
    
    ret = my_islower(ch);
    /*
        Based on return value, print whether ch is lower case alphabet or not
    */
    
    if(ret==1)
    {
        printf("Entered character is lower case alphabet");
    }
    else
    {
       printf("Entered character is not lower case alphabet");
    }
}

int my_islower(int num)
{
    if(num>=97 && num<=122)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}