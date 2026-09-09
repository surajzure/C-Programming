/*Name:Suraj sunil zure
Date:2/1/2026
Description:
int my_atoi(const char *s)
The function will recieve a string and covert the number stored in the string into exact integer number.
Return the number.
Sample execution: -
Test Case 1 :
Enter a numeric string: 12345
String to integer is 12345

Test Case 2 :
Enter a numeric string: -12345
String to integer is -12345

Test Case 3 :
Enter a numeric string: +12345
String to integer is 12345

Test Case 4 :
Enter a numeric string: +-12345
String to integer is 0

Test Case 5 :
Enter a numeric string: 12345-
String to integer is 12345

Test Case 6 :
Enter a numeric string: abcd12345
String to integer is 0

Test Case 7 :
Enter a numeric string: 12345abcd

String to integer is 12345*/
#include <stdio.h>

int my_atoi(const char []);

int main()
{
    char str[20];
    
    printf("Enter a numeric string : ");
    scanf("%s", str);
    
    printf("String to integer is %d\n", my_atoi(str));
}
int my_atoi(const char str[])
{
    int i=0,num=0,digit;
    if(str[0]=='-'||str[0]=='+')
    {
        i=1;
    }
    while(str[i]>='0'&&str[i]<='9')
    {
         //digit=str[i]-48;
         num=num*10+(str[i]-48);
         i++;
        
    }
    if(str[0]=='-')
    {
        return num*(-1);
    }
    return num;
}