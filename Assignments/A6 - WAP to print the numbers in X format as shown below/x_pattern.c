/*Name:Suraj sunil zure 
Date:1/12/20254
Discription:Read a number from user. Let's say if number is 5,
you need to print numbers in X pattern as shown below: 
Sample Input &sample Output:
Enter the number: 4
1  4
 23
 23
1  4

Enter the number: 5
1   5
 2 4
  3
 2 4
1   5
*/
#include<stdio.h>
int main()
{
    int i,j,num;
    //printf("Enter the number: \n");
    scanf("%d",&num);
    for(i=1;i<=num;i++) // Nested loop ,Outer loop
    {
        for(j=1;j<=num;j++)// Inner loop
        {
            if(i==j || i+j-1==num) //Checking the conditions 
            {
                printf("%d",j);
                
            }
            else
            {
            printf(" "); // Printing space
            }
            
        }
        printf("\n");
    }
}