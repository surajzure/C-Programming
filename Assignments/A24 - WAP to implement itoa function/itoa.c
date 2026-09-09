/*Name:Suraj sunil zure
Date:2/1/2026
Description:void itoa(int n, char *s)
Convert integer n into a string and store the string in s.
Sample execution: -
Test Case 1:
Enter the number : 1234
Integer to string is 1234
Test Case 2:
Enter the number : -1234
Integer to string is -1234
Test Case 3:
Enter the number : +1234
Integer to string is 1234
Test Case 4:
Enter the number : a1234
Integer to string is 0*/
#include <stdio.h>

void itoa(int num, char str[]);

int main()
{
    int num;
    char str[100];
    
    printf("Enter the number:");
    if(scanf("%d", &num)!=1)
    {
        printf("Integer to string is 0\n");
        return 0;
    }
   
    itoa(num, str);
    
    printf("Integer to string is %s", str);
}
void itoa(int num, char str[])
{
    
    int i=0,sum=0;
   
    if(num<0)
    {
        str[0]='-';
        i=1;
        num=num*(-1);
    }
    while(num!=0)
    {
        sum=num%10;
        str[i]=sum+48;
        num/=10;
        i++;
    }

    
    str[i]='\0';
    int j=0;
    while(str[j])
    {
        j++;
    }
    i=0;
    if(str[0]=='-')
    {
        i=1;
    }
    
    while(i<j-1)
    {
        char temp=str[i];
        str[i]=str[j-1];
        str[j-1]=temp;
        j--;
        i++;
    }
   
}