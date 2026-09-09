/*Name:Suraj Zure
Date:09/12/2025
Description:Read number n from user.
Validate the given number
Call main function from main for calculating factorial.
Prompt for continue option without using loop.
Sample input and output:
Enter the value of N : 7
Factorial of the given number is 5040

Test Case 2:
Enter the value of N : 5
Factorial of the given number is 120

Test case 3:
Enter the value of N : -1
Invalid Input

Test case 4:
Enter the value of N : 0

Factorial of the given number is 1*/

#include <stdio.h>

// 1. Correct Function Prototype
long long int factorial(int n);

int main()
{
    int num;
    printf("Enter the value of N : ");
    scanf("%d", &num);

    // 2. Validate input in main
    if (num < 0)
    {
        printf("Invalid Input\n");
    }
    else
    {
        // 3. Call function and print result
        long long int result = factorial(num);
        printf("Factorial of the given number is %lld\n", result);
    }
    
    return 0;
}

// 4. Clean Recursive Definition
long long int factorial(int n)
{
    // Base Case: 0! = 1
    if (n == 0)
    {
        return 1;
    }
    // Recursive Step
    else
    {
        return n * factorial(n - 1);
    }
}