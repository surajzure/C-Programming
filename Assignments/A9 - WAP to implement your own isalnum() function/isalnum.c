/* Name: Suraj sunil zure
Date:06/12/2025
Description:checks for an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c)).
Sample input and Output :
Enter the character: a
The character 'a' is an alnum character.
Test Case 2:
Enter the character: ?
The character '?' is not an alnum character.
Entered character is not alphanumeric character*/
#include <stdio.h>

int my_isalnum(int );// Function prototype, Function caling

int main()// main Function
{
    char ch; // Character variable
    int ret; //Intigar variable
    
    printf("Enter the character:\n");
    scanf("%c", &ch);
    
    ret = my_isalnum(ch);
    /*
        Based on return value, print whether ch is alphanumeric or not
    */
    if(ret==1)
    {
        //printf("The charcter'%c'is an alnum character.",ch);
        printf("Entered character is alphanumeric character.");
    }
    else
    {
       //printf("The charcter'%c'is not an alnum character",ch); 
       printf("Entered character is not alphanumeric character.");
    }
}

int my_isalnum( int num)
{
   
  {
//conditions for Capital'A'to'Z , Small 'a' to 'z'     , Digit 0 to 9
        if((num>=65 && num<=90)||(num>=97 && num<=122)||(num>=48 && num<=57))
        {
            return 1; // If ture then return the non zero value
        }
        else
        {
            return 0; // if false the return zero
        }
    }
}