/*Name:Suraj Zure
Date:
Description:
In recreational mathematics, a magic square is an arrangement of distinct numbers (i.e. each number is used once), usually integers, in a square grid, where the numbers in each row, and in each column, and the numbers in the main and secondary diagonals, all add up to the same number
A magic square has the same number of rows as it has columns, and in conventional math notation, "n" stands for the number of rows (and columns) it has. Thus, a magic square always contains n2 numbers, and its size (the number of rows [and columns] it has) is described as being "of order n".
Example: if n = 3, the magic square
8 1  6     
3 5  7  
4 9  2
Read an odd number n from user.
Do error checking.
Check the number is odd or not.
If not, continue step a.
Create an n X n matrix.
Insert 1 to (n * n) numbers into matrix.
Arrange the numbers in such a way that, adding the numbers in any direction, either row wise column wise or diagonal wise, should result in same answer.
Allocate the memory dynamically using calloc.

Sample execution: -
Enter a number: 3
8      1      6
3      5      7
4      9      2

Test Case 2:
Enter a number: 6
Error : Please enter only positive values*/
#include <stdio.h>
#include <stdlib.h>

int **allocate(int n);
void generate_magic(int **mat, int n);
void print_matrix(int **mat, int n);
void free_matrix(int **mat, int n);

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 0 || n % 2 == 0)
    {
        printf(" Error : Please enter only positive odd numbers\n");
        return 0;
    }

    int **mat = allocate(n);

    generate_magic(mat, n);

    print_matrix(mat, n);

    free_matrix(mat, n);

    return 0;
}

int **allocate(int n)
{
    int **mat = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int *)calloc(n, sizeof(int));
    }
    return mat;
}

void generate_magic(int **mat, int n)
{
    int i = 0;
    int j = n / 2;

    for (int num = 1; num <= n * n; num++)
    {
        mat[i][j] = num;

        int new_i = (i - 1 + n) % n;
        int new_j = (j + 1) % n;

        if (mat[new_i][new_j] != 0)
        {
            i = (i + 1) % n;
        }
        else
        {
            i = new_i;
            j = new_j;
        }
    }
}

void print_matrix(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(mat[i]);
    }
    free(mat);
}