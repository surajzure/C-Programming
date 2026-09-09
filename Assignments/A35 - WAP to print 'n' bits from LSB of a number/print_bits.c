/*Name : SURAJ SUNIL ZURE
Date:
Description:
a. Read number num from user.
b. Read number n from user.
c. Do error checking
 -> If n is greater than integer size, assign n value as sizeof integer.
d. Print n number of bits of num from LSB end.
If num is 10 and n is 12, then print last 12 bits of binary representation of 10.
The output should be -> 0 0 0 0 0 0 0 0 1 0 1 0
sample input output
Sample Execution: 
Test Case 1:
Enter the number: 10
Enter number of bits: 12
Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0 
Test Case 2:
Enter the number: 15
Enter number of bits: 4
Binary form of 15: 1 1 1 1
*/

#include <stdio.h>

/* Function prototype */
int print_bits(int num, int n);

int main()
{
    int num, n;

    /* Read number and number of bits from user */
    printf("Enter num, n :\n");
    scanf("%d%d", &num, &n);

    /* Print message before displaying bits */
    printf("Binary form of %d:", num);

    /* Function call to print binary bits */
    print_bits(num, n);

    return 0;   // End of program
}

/*
Function Name : print_bits
Input         : num → number whose bits are to be printed
                n   → number of bits to display
Output        : Prints binary representation on screen
Description   :
This function checks each bit from (n-1)th position down to 0th position
using bitwise AND and prints 1 or 0 accordingly.
*/
int print_bits(int num, int n)
{
    int i;

    /*
    Loop starts from (n-1) to print MSB first
    and goes till 0 to print LSB at the end.
    */
    for (i = n - 1; i >= 0; i--)
    {
        /*
        (1 << i) creates a mask with only ith bit set.
        Bitwise AND checks whether ith bit of num is set or not.
        */
        if (num & (1 << i))
        {
            printf(" 1");   // Print 1 if bit is set
        }
        else
        {
            printf(" 0");   // Print 0 if bit is not set
        }
    }
}
