/*Name:Suraj sunil zure.
Date:26/11/2025.
Description:You should read three intergers from user and find the middle number.
Sample I/p and O/p:
contidtion 1) 20 10 30 middle number is 20
           2) 20 30 10 middle number is 20
           */


#include<stdio.h>
int main()
{
    int num1,num2,num3,middle;
    printf("Enter the Three numbers:\n");
    
    scanf("%d%d%d",&num1,&num2,&num3);
    
    if((num1<num2 && num1>num3) || (num1>num2 && num1<num3))
    {
       
        
            middle=num1;
            printf("The middle number is %d",middle);
        
    }
    else
    {
        if((num2<num1 && num2>num3) ||(num2>num1 && num2<num3))
        {
         
            
            middle=num2;
            printf("The middle number is %d",middle);
            
        }
        else
        {
            middle=num3;
            printf("The middle number is %d",middle);
            
        }
    }
}