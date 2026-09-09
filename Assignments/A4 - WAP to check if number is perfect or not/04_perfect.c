/*Name:Suraj sunil zure 
Date:28/11/20254
Discription: 
• In number theory, a perfect number is a positive integer that is equal to the sum of its proper positive divisors, that is, the sum of its positive divisors excluding the number itself (also known as its aliquot sum).

• Equivalently, a perfect number is a number that is half the sum of all of its positive divisors (including itself)

Sample execution: -

Test Case 1:

Enter a number: 6

Yes, entered number is perfect number

Test Case 2:

Enter a number: 10

No, entered number is not a perfect number

Test Case 3:

Enter a number: -1

Error : Invalid Input, Enter only positive number
*/

#include<stdio.h>
int main()
{
    int num,sum=0; // Declaration on variable , sum=0 bec if we will not assign 0 to sum it will add sum + garbage value 
    printf("Enter a number: \n");
    scanf("%d",&num);// taking the input from user 
    if(num>0)
    {
        for(int i=1;i<num;i++)// Loop will run forme 1 to less than entered number 
        {
            if(num % i ==0) // contition to check the number is factor or not
            {
                sum=sum+i; // Adding the sum + factor
            }
         }
     
     
        if(num==sum) // checking the num is equal to sum or not
        {
         printf("Yes,entered number is perfect number");
        }
        else if(num!=sum) // if the num is not equal to sum it will enter the loop
        {
            printf("No, entered number is not a perfect number ");
        }
       
    }
    else
    {
        printf("Error :Invalid input,Enter only positive number");
    }
}










