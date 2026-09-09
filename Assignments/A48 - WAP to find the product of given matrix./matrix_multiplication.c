/*Suraj Zure
Date:
Description:
Read no.of rows and columns for 2 arrays from user and allocate the memory dynamically using malloc or calloc (Assume Matrix A and Matrix B).
Read the Matrix A and B from user.
Find the product for matrix A with matrix B amd store the result in Matrix R.
Let say Name of the matrix is A and no. Of rows = columns = 3.
Sample output:

Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :

1      1     1
2      2     2
3      3     3
Product of two matrix :
14      14      14
14      14      14
14      14      14

Test case 2:
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 2
Enter number of columns : 3
Matrix multiplication is not possible*/

#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
int **allocate(int rows, int cols);
void read_matrix(int **mat, int rows, int cols);
void print_matrix(int **mat, int rows, int cols);
void matrix_mul(int **A, int r1, int c1,int **B, int r2, int c2,int **R);

int main()
{
    int r1, c1, r2, c2;

    /* Matrix A */
    printf("Enter number of rows : ");
    scanf("%d", &r1);
    printf("Enter number of columns : ");
    scanf("%d", &c1);

    int **mat_a = allocate(r1, c1);

    printf("Enter values for %d x %d matrix :\n", r1, c1);
    read_matrix(mat_a, r1, c1);

    /* Matrix B */
    printf("Enter number of rows : ");
    scanf("%d", &r2);
    printf("Enter number of columns : ");
    scanf("%d", &c2);

    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible\n");
        return 0;
    }

    int **mat_b = allocate(r2, c2);

    printf("Enter values for %d x %d matrix :\n", r2, c2);
    read_matrix(mat_b, r2, c2);

    /* Result matrix */
    int **result = allocate(r1, c2);

    matrix_mul(mat_a, r1, c1, mat_b, r2, c2, result);

    printf("Product of two matrix :\n");
    print_matrix(result, r1, c2);

    /* Free memory */
    for (int i = 0; i < r1; i++)
        free(mat_a[i]);
    free(mat_a);

    for (int i = 0; i < r2; i++)
        free(mat_b[i]);
    free(mat_b);

    for (int i = 0; i < r1; i++)
        free(result[i]);
    free(result);

    return 0;
}

/* Allocate 2D dynamically */
int **allocate(int rows, int cols)
{
    int **mat = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        mat[i] = malloc(cols * sizeof(int));
    return mat;
}

/* Read matrix values */
void read_matrix(int **mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);
}

/* Print matrix */
void print_matrix(int **mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

/* Matrix multiplication logic */
void matrix_mul(int **A, int r1, int c1,
                int **B, int r2, int c2,
                int **R)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            R[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}