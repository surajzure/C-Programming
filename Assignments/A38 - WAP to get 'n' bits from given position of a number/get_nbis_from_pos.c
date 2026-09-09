/*Name: Suraj Zure
Date: 04/02/26
Description:
a. Read number num from user.
b. Read number n from user.
c. Read number pos from user.
d. Fetch n number of bits from given position 'pos' (starting from LSB)
   of num and return the decimal value of it.

Example:
If num is 12, n is 3 and pos is 4

Bit positions:   7 6 5 4 3 2 1 0
Binary of 12:    0 0 0 0 1 1 0 0

We need to fetch 3 bits starting from position 4:
Bits fetched:    0 1 1  -> decimal value = 3
*/

#include <stdio.h>

/* Function declaration
   This function extracts n bits from position pos of num */
int get_nbits_from_pos(int num, int n, int pos);

int main()
{
    int num, n, pos, res = 0;

    /* Read input values from user */
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &pos);

    /* Function call to extract bits */
    res = get_nbits_from_pos(num, n, pos);

    /* Print final result */
    printf("Result = %d\n", res);
}

/* Function definition */
int get_nbits_from_pos(int num, int n, int pos)
{
    /* mask is initialized to 1
       It will be used to generate required number of 1s */
    int mask = 1;

    /*
    Step 1:
    (mask << n) shifts 1 left by n positions
    Example: n = 3 → 1 << 3 = 1000

    Step 2:
    (mask << n) - 1 gives n number of 1s
    Example: 1000 - 1 = 0111

    Step 3:
    << (pos - n + 1) shifts the mask to required position

    Example:
    num = 12 (00001100)
    n = 3, pos = 4

    (mask << n) - 1        = 00000111
    Shift by (4 - 3 + 1)=2 = 00011100

    AND operation extracts required bits:
    00001100 &
    00011100
    --------
    00001100
    */
    num = num & (((mask << n) - 1) << (pos - n + 1));

    /*
    Step 4:
    Right shift the extracted bits to LSB position
    So that decimal value can be obtained

    00001100 >> 2 = 00000011 (decimal 3)
    */
    num = num >> (pos - n + 1);

    /* Return final extracted decimal value */
    return num;
}
