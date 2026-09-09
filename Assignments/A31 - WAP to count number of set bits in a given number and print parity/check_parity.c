/*Name : SURAJ SUNIL ZURE
Date : 28/01/2026 
Description:
This program reads an integer from the user and counts the number of set bits (1s)
present in its binary representation. Based on the count of set bits, it determines
whether the bit parity is Odd or Even.
Test Case 1:
Enter the number : 7
Number of set bits = 3
Bit parity is Odd
Test Case 2:
Enter the number : 15
Number of set bits = 4
Bit parity is Even
Test Case 3:
Enter the number : 6
Number of set bits = 2
Bit parity is Even

*/
#include <stdio.h>

/*
Function Name : count_set_bits
Input         : num → integer number entered by the user
Output        : Returns total count of set bits in the number
Description   :
This function checks each bit of the number using bitwise AND and a mask.
If a bit is set (1), the count is incremented.
*/
int count_set_bits(int num)
{
    int count = 0;   // Stores number of set bits
    int i;

    /* Loop runs for 32 times because an integer has 32 bits */
    for (i = 0; i <= 31; i++)
    {
        /* 
        (1 << i) creates a mask with only ith bit set.
        Bitwise AND checks whether ith bit of num is set or not.
        */
        if (num & (1 << i))   // masking operation
        {
            count++;          // Increment count if bit is set
        }
    }

    return count;  // Return total number of set bits
}

int main()
{
    int num, set_bits;

    /* Read number from user */
    printf("Enter the number : ");
    scanf("%d", &num);

    /* Function call to count set bits */
    set_bits = count_set_bits(num);

    /* Display number of set bits */
    printf("Number of set bits = %d\n", set_bits);

    /*
    Parity check:
    If number of set bits is odd → bit parity is Odd
    If number of set bits is even → bit parity is Even
    */
    if (set_bits & 1)   // Checks LSB of set_bits
    {
        printf("Bit parity is Odd\n");
    }
    else
    {
        printf("Bit parity is Even\n");
    }

    return 0;  // End of program
}
