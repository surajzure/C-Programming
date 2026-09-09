/*
Name        : Suraj Zure
Date        : 04/02/2026
Description:a. Read number num from user.
b. Read number n from user.
c. Read number pos from user.
d. Invert the n number of bits from pos positionth bit of num.
e. Return the new value of num
If num is 10, n is 3, and pos is 5
7 6 5 4 3 2 1 0
10 -> 0 0 0 0 1 0 1 0
return value -> 0 0 1 1 0 0 1 0
So the function should return 50 (0 0 1 1 0 0 1 0)
Sample input output
Test Case 1:
Enter the number: 10
Enter number of bits: 3
Enter the pos: 5
Result = 50
Test Case 2:
Enter the number: 15
Enter number of bits: 2
Enter the pos: 2
Result =  9
*/

#include <stdio.h>

/* Function prototype */
int toggle_nbits_from_pos(int num, int n, int pos);

int main()
{
    int num, n, pos, res = 0;

    /* Read input values from user */
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter the pos: ");
    scanf("%d", &pos);

    /* Function call */
    res = toggle_nbits_from_pos(num, n, pos);

    /* Print the result */
    printf("Result = %d\n", res);

    return 0;   // End of program
}

/*
Function Name : toggle_nbits_from_pos
Input         : num → original number
                n   → number of bits to toggle
                pos → position from where toggling starts
Output        : Updated number after toggling bits
Description   :
This function creates a mask of n bits and shifts it to the required
position. XOR operation is used to toggle the bits.
*/
int toggle_nbits_from_pos(int num, int n, int pos)
{
    int mask;

    /*
    (1 << n) - 1 → creates a mask with n bits set to 1
    Example: n = 3 → mask = 00000111
    */
    mask = (1 << n) - 1;

    /*
    Shift mask to align with required position
    (pos - n + 1) gives correct starting position
    */
    mask = mask << (pos - n + 1);

    /*
    XOR operation toggles the bits where mask has 1s
    */
    num = num ^ mask;

    return num;   // Return updated value
}
