/*Name : SURAJ SUNIL ZURE
Date :
Description:Read a number num from user.
Read a number n from user.
Pass num and n to the function.
Shift num, n times (towards left).
While shifting the shifted bits should get replaced at the alternate end.
For left shifting, the shifted bits should come at right most side.
Return the new number from the function.
Print the new number.
Example:
If num is -2, and n is 3, in circular_left_shift function
12 -> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
o/p -> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
sample input output
Enter num: 12
Enter n : 3
Result in Binary: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0

Test Case 2: 
Enter num: -2
Enter n : 3
Result in Binary: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1*/

#include <stdio.h>

/* Function prototypes */
int circular_left(unsigned int num, int n);
int print_bits(unsigned int num);

int main()
{
    unsigned int num;
    int n, ret;

    /* Read number from user */
    //printf("Enter the num: \n");
    scanf("%u", &num);

    /* Read number of shifts */
    //printf("Enter n: ");
    scanf("%d", &n);

    /* Perform circular left shift */
    ret = circular_left(num, n);

    /* Print binary representation of result */
    print_bits(ret);

    return 0;   // End of program
}

/*
Function Name : circular_left
Input         : num → unsigned integer value
                n   → number of bits to rotate
Output        : Result after circular left shift
Description   :
This function shifts the number left by n bits and stores the result.
Then it shifts the original number right by (32 - n) bits to get the
overflow bits and combines both using bitwise OR.
*/
int circular_left(unsigned int num, int n)
{
    unsigned int result;

    /* Left shift the number by n bits */
    result = num << n;

    /* Right shift to get wrapped-around bits */
    num = num >> (32 - n);

    /* Combine both parts to form circular left shift */
    num = num | result;

    return num;   // Return rotated value
}

/*
Function Name : print_bits
Input         : num → number whose bits are to be printed
Output        : Prints 32-bit binary representation
Description   :
This function prints all 32 bits of the given number from MSB to LSB.
*/
int print_bits(unsigned int num)
{
    int i;

    /* Loop runs for 32 bits */
    printf("Result in Binary: ");
    for (i = 31; i >= 0; i--)
    {
        /* Check each bit using masking */
        if (num & (1 << i))
        {
            printf(" 1");
        }
        else
        {
            printf(" 0");
        }
    }
}
