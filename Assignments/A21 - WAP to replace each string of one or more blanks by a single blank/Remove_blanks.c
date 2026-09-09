/*Name: Suraj Zure
Date: 23/12/2025
Description:Input string:
Pointers         are      sharp           knives.
Output String:
Pointers are sharp knives.
Blank can be spaces or tabs. (replace with single space).
Sample execution: -
Test Case 1:
Enter the string with more spaces in between two words
Pointers     are               sharp     knives.
Pointers are sharp knives.
Test Case 2:
Enter the string with more spaces in between two words
Welcome                to Emertxe
Welcome to Emertxe
Test Case 3:
Enter the string with more spaces in between two words
Welcome to Emertxe
Welcome to Emertxe*/
#include <stdio.h>

// Function to remove extra spaces between words
void replace_blank(char []);

int main()
{
    char str[100];

    // Read a string with multiple spaces
    printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);

    // Function call
    replace_blank(str);

    // Print the modified string
    printf("%s\n", str);

    return 0;
}

// Function definition
void replace_blank(char str[])
{
    int i = 0;

    // Traverse the string character by character
    while (str[i] != '\0')
    {
        // If two consecutive spaces are found
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            int j = i;

            // Shift characters left to remove one space
            while (str[j] != '\0')
            {
                str[j] = str[j + 1];
                j++;
            }
            // i is NOT incremented here
            // Reason: there might be more spaces
        }
        else
        {
            i++;  // Move to next character
        }
    }
}
