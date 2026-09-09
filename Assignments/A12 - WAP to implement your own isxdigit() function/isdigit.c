#include <stdio.h>

int is_xdigit(int);

int main()
{
    char ch;
    short ret;
    
    printf("Enter a character: ");
    scanf("%c", &ch);
    
    ret = is_xdigit(ch);
    
    /* Based on the return value of the function print the message */
    
    if(ret==1)
    {
        printf("Entered character is an hexadecimal digit");
    }
    else
    {
        printf("Entered character is not an hexadecimal digit");
    }
    
    return 0;
}
int is_xdigit(int num)
{
    if((num>=48 && num<=57) || (num>=65 && num<=70) || (num>=97 && num<=102))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
