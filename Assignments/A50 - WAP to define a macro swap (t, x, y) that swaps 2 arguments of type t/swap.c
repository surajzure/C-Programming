/*
Name:Suraj Zure
Date:
Description:
Implement swap concept with the help of macro
The type of arguments to swap will be passed as t
swap (int, x, y) where x and y are of types int.
Sample execution:
1. Int
2. char
3. short
4. float
5. double
6. string
Enter you choice : 1
Enter the num1 : 10
Enter the num2 : 20
After Swapping :
num1 : 20
num2 : 10*/
#include <stdio.h>      // For input-output functions (printf, scanf)
#include <string.h>     // For string functions (strcpy)

// Macro to swap two variables of any datatype
// t → datatype (int, float, char, etc.)
// x, y → variables to swap
// do-while(0) ensures macro behaves like a single statement
#define swap(t, x, y) do { \
    t temp;                /* Step 1: Declare temporary variable of type t */ \
    temp = x;              /* Step 2: Store x value in temp */ \
    x = y;                 /* Step 3: Assign y value to x */ \
    y = temp;              /* Step 4: Assign temp value to y */ \
} while(0)

int main()
{
    int choice;   // Variable to store user choice

    // Display menu
    printf("1. Int\n");
    printf("2. char\n");
    printf("3. short\n");
    printf("4. float\n");
    printf("5. double\n");
    printf("6. string\n");

    // Take user choice
    printf("Enter your choice : ");
    scanf("%d", &choice);

    // Switch case to handle different datatypes
    switch(choice)
    {
        // Case 1: Integer swapping
        case 1:
        {
            int x, y;   // Declare integer variables

            // Input values
            printf("Enter the num1 : ");
            scanf("%d", &x);

            printf("Enter the num2 : ");
            scanf("%d", &y);

            // Call macro to swap values
            swap(int, x, y);

            // Print result
            printf("After Swapping :\n");
            printf("num1 : %d\nnum2 : %d\n", x, y);
            break;
        }

        // Case 2: Character swapping
        case 2:
        {
            char x, y;   // Declare char variables

            // Input characters (space before %c to clear buffer)
            printf("Enter char1 : ");
            scanf(" %c", &x);

            printf("Enter char2 : ");
            scanf(" %c", &y);

            // Swap using macro
            swap(char, x, y);

            // Print result
            printf("After Swapping :\n");
            printf("char1 : %c\nchar2 : %c\n", x, y);
            break;
        }

        // Case 3: Short datatype swapping
        case 3:
        {
            short x, y;   // Declare short variables

            // Input values
            printf("Enter num1 : ");
            scanf("%hd", &x);

            printf("Enter num2 : ");
            scanf("%hd", &y);

            // Swap values
            swap(short, x, y);

            // Print result
            printf("After Swapping :\n");
            printf("num1 : %hd\nnum2 : %hd\n", x, y);
            break;
        }

        // Case 4: Float datatype swapping
        case 4:
        {
            float x, y;   // Declare float variables

            // Input values
            printf("Enter num1 : ");
            scanf("%f", &x);

            printf("Enter num2 : ");
            scanf("%f", &y);

            // Swap values
            swap(float, x, y);

            // Print result
            printf("After Swapping :\n");
            printf("num1 : %f\nnum2 : %f\n", x, y);
            break;
        }

        // Case 5: Double datatype swapping
        case 5:
        {
            double x, y;   // Declare double variables

            // Input values
            printf("Enter num1 : ");
            scanf("%lf", &x);

            printf("Enter num2 : ");
            scanf("%lf", &y);

            // Swap values
            swap(double, x, y);

            // Print result
            printf("After Swapping :\n");
            printf("num1 : %lf\nnum2 : %lf\n", x, y);
            break;
        }

        // Case 6: String swapping (macro cannot be used for arrays)
        case 6:
        {
            char x[100], y[100], temp[100];  
            // x, y → strings to swap
            // temp → temporary string

            // Input strings
            printf("Enter string1 : ");
            scanf("%s", x);

            printf("Enter string2 : ");
            scanf("%s", y);

            // Manual swapping using strcpy
            strcpy(temp, x);   // Copy x into temp
            strcpy(x, y);      // Copy y into x
            strcpy(y, temp);   // Copy temp into y

            // Print result
            printf("After Swapping :\n");
            printf("string1 : %s\nstring2 : %s\n", x, y);
            break;
        }

        // Default case: Invalid choice
        default:
            printf("Invalid choice\n");
    }

    return 0;   // Indicate successful execution
}