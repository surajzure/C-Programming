/*Name : SURAJ SUNIL ZURE
Date :04/02/26
Description:
Read a number num from user.
Read a number n from user.
Pass num and n to the function.
Shift num, n times (towards right).
While shifting the shifted bits should get replaced at the alternate end.
For right shifting, the shifted bits should come at left most side.
Return the new number from the function.
Print the new number.

Example:
If num is 12 and n is 3

Binary of 12:
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0

Output:
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
*/

#include <stdio.h>

/* Function prototypes */
unsigned int circular_right(unsigned int num, int n);
void print_bits(unsigned int num);

int main()
{
    unsigned int num;
    int n;
    unsigned int ret;

    /* Read inputs */
    scanf("%u", &num);
    scanf("%d", &n);

    /* Perform circular right shift */
    ret = circular_right(num, n);

    /* Print result in binary */
    print_bits(ret);

    return 0;
}

/*
Function Name : circular_right
Input         : num → unsigned integer value
                n   → number of bits to rotate
Output        : Result after circular right shift
Description   :
This function shifts the number right by n bits.
Then it shifts the original number left by (32 - n)
to get the wrapped bits and combines both using OR.
*/
unsigned int circular_right(unsigned int num, int n)
{
    unsigned int result;

    /* Right shift by n bits */
    result = num >> n;

    /* Left shift to get wrapped-around bits */
    num = num << (32 - n);

    /* Combine both parts */
    num = num | result;

    return num;
}

/*
Function Name : print_bits
Input         : num → number whose bits are to be printed
Output        : Prints 32-bit binary representation
*/
void print_bits(unsigned int num)
{
    int i;

    printf("Result in Binary:");
    for (i = 31; i >= 0; i--)
    {
        if (num & (1 << i))
        {
            printf(" 1");
        }
        else
        {
            printf(" 0");
        }
    }
    printf("\n");
}
