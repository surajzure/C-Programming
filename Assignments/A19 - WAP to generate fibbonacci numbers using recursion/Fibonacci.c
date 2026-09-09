/* Name: Suraj sunil zure
Date:08/12/2025
Description:Fibonacci sequence are the numbers in the following integer sequence 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . .OR 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . .
Sample input and outpu:
Enter a number: 8
0, 1, 1, 2, 3, 5, 8

Test Case 2:
Enter a number: 10
0, 1, 1, 2, 3, 5, 8

Test Case 3:
Enter a number: 21

0, 1, 1, 2, 3, 5, 8, 13, 21

Test Case 4:
Enter a number: -12

Invalid input*/

#include <stdio.h>

void positive_fibonacci(int limit, int first, int second, int next);// Function prototype

int main() //Main 
{
    int limit;
    
    printf("Enter the limit : ");
    scanf("%d", &limit);
    if(limit>=0)// To check the limit ,it should be greater than 1
    {   
        positive_fibonacci(limit, 0, 1, 0); // calling function
    }
    else
    {
        printf("\nInvalid input");
    }
}

void positive_fibonacci(int limit,int first,int second,int next)
{
  
   if(first<=limit)
   {
       printf("%d,",first);
       next=first+second;
       first=second;
       second=next;
    positive_fibonacci(limit,first,second,next); // Recursion(function calling function itsself in function)
   }
  
}