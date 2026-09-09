#include <stdio.h>

int my_ispunct(int);

int main()
{
    char ch;
    int ret;
    
    printf("Enter the character:\n");
    scanf("%c", &ch);
    
    ret = my_ispunct(ch);
    /*
        Based on return value, print whether ch is lower case alphabet or not
    */
    if(ret==1)
    {
            printf("Entered character is not punctuation character");
    }
    else
    {
        printf("Entered character is punctuation character");
    }   
}
int my_ispunct(int num)
{
    if((num>=65 && num<=97) || (num>=97 &&  num<=122) || (num>=48 && num<=57))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}