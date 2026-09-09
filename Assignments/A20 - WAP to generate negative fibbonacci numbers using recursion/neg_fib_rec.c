/* Name: Suraj sunil zure
Date:08/12/2025
Description:In mathematics, the Fibonacci numbers or Fibonacci sequence are the numbers in the following integer sequence  0, 1, -1, 2, -3, 5, -8, 13, -21, 34, -55, 89, -144 . . .
By definition, the first two numbers in the Fibonacci sequence are 0 and 1, each subsequent number is the subtraction of the previous two
Sample input output:
Test Case 1 :
user@emertxe] ./fibbonacci_series
Enter a number: -8
0, 1, -1, 2, -3, 5, -8
Test Case 2:
Enter a number: -10
0, 1, -1, 2, -3, 5, -8
Test Case 3:
Enter a number: -21

0, 1, -1, 2, -3, 5, -8, 13, -21

Test Case 3:
Enter a number: 21

Invalid input

*/
#include <stdio.h>
// Function prototype
void negative_fibonacci(int limit, int first, int second);

int main()
{
    int limit;
    
    printf("Enter the limit : ");
    scanf("%d", &limit);
    
    // VALIDATION: Strictly reject positive numbers
    if (limit > 0)
    {
        printf("Invalid input");
    }
    else
    {
        // Start recursion with 0 and -1 to generate negative sequence
        negative_fibonacci(limit, 0, -1);
    }
    
    return 0;
}

void negative_fibonacci(int limit, int first, int second)
{
    // Stop when the current number drops below the limit
    if(first >= limit)
    {
        printf("%d ", first);
        
        // Recursive step: pass 'second' as the new 'first'
        // and calculate the sum for the new 'second'
        negative_fibonacci(limit, second, first + second);
    }
}