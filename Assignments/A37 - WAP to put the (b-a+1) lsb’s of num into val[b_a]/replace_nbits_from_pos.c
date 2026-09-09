/*Name:Suraj Zure
Date:05/2/2026
Description:Read number num from user.
Read number val from user.
Read number a from user.
Read number b from user(a <= b <=31)
Do error checking
Check b is within limit or not.
Call replace_nbits_from_pos function by passing val, b - a + 1, b and n as arguments.
replace_nbits_from_pos(num, a, b, val);
Print the new value of i.
Prompt for continue option.
SAMPLE INPUT OUTPUT
Enter the value of 'num' : 11
Enter the value of 'a' : 3
Enter the value of 'b' : 5
Enter the value of 'val': 174
Result : 158*/
#include <stdio.h>

/* Function prototype to replace n bits from a specified position */
int replace_nbits_from_pos(int, int, int, int);

int main()
{
    int num, a, b, val, res = 0;
    
    // User inputs the source number (num), range [a, b], and target value (val)
    printf("Enter num, a, b, and val:");
    scanf("%d%d%d%d", &num, &a, &b, &val);
    
    // Execute bit replacement logic
    res = replace_nbits_from_pos(num, a, b, val);
    
    printf("Result = %d\n", res);
    return 0;
}

/**
 * replace_nbits_from_pos:
 * Takes 'n' bits from the end of 'num' and puts them into 'val' at the range [a, b].
 */
int replace_nbits_from_pos(int num, int a, int b, int val)
{
    // 1. Calculate number of bits to be replaced (e.g., if a=3, b=5, n=3)
    int n = b - a + 1;
    
    // 2. Create a mask of 'n' bits set to 1 (e.g., if n=3, mask = 0...0111)
    int mask = (1 << n) - 1;
    
    // 3. Extract the last 'n' bits from 'num' using the mask
    int ret1 = num & mask;
    
    // 4. Clear the bits in 'val' at the target range [a, b] 
    // Shift mask to position (b-n+1) and invert it to create a 'hole'
    int ret2 = val & (~(mask << (b - n + 1)));
    
    // 5. Shift extracted bits (ret1) to the target position and OR with the cleared 'val'
    return (ret1 << (b - n + 1)) | ret2;
}
