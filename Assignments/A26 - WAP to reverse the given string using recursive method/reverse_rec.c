/* Name: Suraj Zure
   Date: 23/12/2025
   Description:
   Read a string from user.
   Reverse the string using RECURSION.
   No loops allowed in reverse function.
   Do not print character by character.
   Sample execution: -
    Test Case 1:
    Enter a string : Hello World
    Reverse string is : dlroW olleH
    Test Case 2:
    Enter a string : EMERTXE
    Reverse string is : EXTREME
*/

#include <stdio.h>

// Function declarations
void reverse_recursive(char str[], int start, int end);
int my_length(char str[]);

// Function to find length of string
int my_length(char str[])
{
    int size = 0;

    // Count characters until null character is found
    while (str[size] != '\0')
    {
        size++;
    }

    return size;   // Return total length
}

int main()
{
    char str[30];

    // Read input string
    printf("Enter any string : ");
    scanf("%[^\n]", str);

    // Find length of string
    int length = my_length(str);

    // Call recursive reverse function
    // end index = length - 1
    reverse_recursive(str, 0, length - 1);

    // Print reversed string
    printf("Reversed string is : %s\n", str);

    return 0;
}

// Recursive function to reverse string
void reverse_recursive(char str[], int start, int end)
{
    // Base condition
    // Stop when start crosses end
    if (start < end)
    {
        char temp;

        // Swap first and last characters
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Recursive call for remaining string
        reverse_recursive(str, start + 1, end - 1);
    }
}
