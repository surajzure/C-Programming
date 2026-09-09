/* 
Name       : Suraj Zure
Date       : 
Description: 
This program extracts n bits from the LSB (Least Significant Bit) of a given number
and returns the decimal value of those extracted bits.
*/

#include <stdio.h>

/* Function prototype */
int get_nbits(int num, int n);

int main()
{
    int num, n, res = 0;

    /* Read the number and number of bits from user */
    printf("Enter num and n: ");
    scanf("%d %d", &num, &n);

    /* Call function to get n bits from LSB */
    res = get_nbits(num, n);

    /* Print the result */
    printf("Result = %d\n", res);

    return 0;
}

/*
Function Name : get_nbits
Input         : num → number from which bits are extracted
                n   → number of bits to extract from LSB
Output        : Decimal value of extracted bits
Description   :
This function creates a mask with n bits set to 1 and performs
bitwise AND with the given number to extract the required bits.
*/
int get_nbits(int num, int n)
{
    int mask;

    /* Create mask with n LSB bits set to 1
       Example: n = 3 → mask = 00000111 */
    mask = (1 << n) - 1;

    /* Extract n bits from LSB using bitwise AND */
    return (num & mask);
}
