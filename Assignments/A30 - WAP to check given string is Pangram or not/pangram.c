/* Name: Suraj Zure
   Date: 29/12/2025
   Description:
   Read a string from the user.
   Check whether the string is Pangram or not.
   A pangram contains all 26 English alphabets.
*/

#include <stdio.h>

// Function declaration
int pangram(char str[]);

int main()
{
    char str[100] = {0};     // Store input string

    printf("Enter the string: ");
    scanf("%[^\n]", str);    // Read full line including spaces

    // Function call to check pangram
    if (pangram(str))
    {
        printf("The Entered String is a Pangram String");
    }
    else
    {
        printf("The Entered String is not a Pangram String");
    }

    return 0;
}

// Function to check pangram
int pangram(char str[])
{
    int i = 0, index;
    int arr[26] = {0};   // 26 boxes for 26 alphabets (a–z)

    // Step 1: Scan each character of string
    while (str[i] != '\0')
    {
        // If uppercase letter
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            index = str[i] - 'A'; // Convert letter to index (0–25)
            arr[index] = 1;       // Mark letter as present
        }

        // If lowercase letter
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            index = str[i] - 'a'; // Convert letter to index (0–25)
            arr[index] = 1;       // Mark letter as present
        }

        i++;
    }

    // Step 2: Check whether all 26 letters are present
    for (i = 0; i < 26; i++)
    {
        if (arr[i] == 0)      // If any letter is missing
        {
            return 0;         // Not a pangram
        }
    }

    return 1;   // All letters found → pangram
}
