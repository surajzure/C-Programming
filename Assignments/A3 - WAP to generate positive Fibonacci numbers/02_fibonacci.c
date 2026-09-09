/*Name:Suraj sunil zure 
Date:28/11/20254
Discription: Print the Fibonacci numbers or Fibonacci sequence 
Sample input and Output:
Enter a number: 8

0 1 1 2 3 5 8

Test Case 2:

Enter a number: 10

0 1 1 2 3 5 8

Test Case 3:

Enter a number: 21

0 1 1 2 3 5 8 13 21

Test Case 4:

Enter a number: -21

Invalid input
*/
#include<stdio.h>
int main()
{
    int First=0; // First number is zero
    int Second=1;//Second number is and so..
    int Next=0; // it will Store the next number
    int Range;// Variable
    printf("Enter a number: \n");
    scanf("%d",&Range);
    
    if(Range<0) // If range Range is smaller than Zero(0)
    {
        printf("Invalid input");
    }
    else
    {
    while(First<=Range) // If First number number is smaller than the Range it will go inside the loop 
        {
        printf("%d ",First);
        Next=First+Second;
        First=Second;
        Second=Next;
        }
    }
}