/* Name : SURAJ SUNIL ZURE
Date : 30/01/2026
Description:
This program reads a number num, number of bits n, and another value val.
It extracts n bits from the LSB of val and replaces them into the last n bits of num.
The updated value of num is returned.
sample input output
Test Case 1:
Enter the number: 10
Enter number of bits: 3
Enter the value: 12
Result = 12
Test Case 2:
Enter the number: 15
Enter number of bits: 2
Enter the value: 1
Result =  13
*/

#include <stdio.h>

/* Function prototype */
int replace_nbits(int num, int n, int val);

int main()
{
    int num, n, val, res = 0;

    /* Read input values */
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter the value: ");
    scanf("%d", &val);

    /* Function call */
    res = replace_nbits(num, n, val);

    /* Display result */
    printf("Result = %d\n", res);

    return 0;
}

/*
Function Name : replace_nbits
Input         : num → original number
                n   → number of bits to replace
                val → value from which bits are taken
Output        : Updated value of num
Description   :
This function extracts n bits from the LSB of val,
clears n bits from the LSB of num,
and replaces them with extracted bits.
*/
int replace_nbits(int num, int n, int val)
{
    int mask;
    int result;

    /* Create mask with n LSB bits set to 1
       Example: n = 3 → mask = 00000111 */
    mask = (1 << n) - 1;

    /* Extract n LSB bits from val */
    result = val & mask;

    /* Clear n LSB bits of num */
    num = num & ~mask;

    /* Replace cleared bits with extracted bits */
    num = num | result;

    return num;   // Return updated number
}
