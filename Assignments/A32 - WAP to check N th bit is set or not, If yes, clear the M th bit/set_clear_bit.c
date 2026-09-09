/*Name : SURAJ SUNIL ZURE
Date : 29/01/2026 
Description:
This program reads a number, N and M from the user.
It first checks whether the Nth bit of the given number is set (1).
If the Nth bit is set, then it clears the Mth bit of the number
and prints the updated value.
Sample Execution:
Test Case 1:
Enter the number: 19
Enter 'N': 1
Enter 'M': 4
Updated value of num is 3 
Test Case 2:
Enter the number: 19
Enter 'N': 2
Enter 'M': 4
Updated value of num is 19 
*/

#include <stdio.h>

/*
Function Name : update
Input         : num → original number
                n   → bit position to check
                m   → bit position to clear
Output        : Updated number after operation
Description   :
This function checks if the Nth bit is set in num.
If it is set, then the Mth bit is cleared.
Otherwise, num is returned as it is.
*/
int update(int num, int n, int m)
{
    int mask = 1;   // Mask used for bit operations

    /*
    (mask << n) creates a mask with only Nth bit set.
    Bitwise AND checks whether Nth bit of num is set or not.
    */
    if (num & (mask << n))
    {
        /*
        (mask << m) creates a mask with only Mth bit set.
        ~(mask << m) makes all bits 1 except Mth bit.
        Bitwise AND clears the Mth bit of num.
        */
        num = num & (~(mask << m));
    }

    return num;   // Return updated value
}

int main()
{
    int num, n, m;

    /* Read input values from user */
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter 'N': ");
    scanf("%d", &n);

    printf("Enter 'M': ");
    scanf("%d", &m);

    /* Function call */
    int result = update(num, n, m);

    /* Print updated value */
    printf("Updated value of num is %d", result);

    return 0;   // End of program
}
