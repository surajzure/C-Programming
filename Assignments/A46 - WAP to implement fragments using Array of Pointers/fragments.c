/*Name:Suraj sunil Zure
Date:
Description:
Implement fragments using array of pointers.
Rows are static and columns are dynamic. Fixed no.of rows and columns will vary for each row.
Example:
Read no.of rows from user and allocate the memory statically for rows.
Read no.of columns for each row and allocate the memory dynamically.
Let us Assume, Row = 3.
Row[0] = 4 columns, Row[1] = 3 columns and Row[2] = 5 columns.
While allocating the memory for columns you have allocate for no.of columns + 1 dynamically.
After that read the values from user and calculate the average for each row seperatly and store that average in that extra memory block which you added while allocating the memory.
Example is given below.Then sort the array based on the average.

Sample Execution:
Enter no.of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 3
Enter no of columns in row[2] : 5
Enter 4 values for row[0] : 1 2 3 4
Enter 3 values for row[1] : 2 5 9
Enter 5 values for row[2] : 1 3 2 4 1

Before sorting output is:

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

After sorting output is:

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333*/
#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
void scan(float *arr[], int row, int col[]);
void print(float *arr[], int row, int col[]);
void sort(float *arr[], int row, int col[]);

int main()
{
    int row;

    printf("Enter no.of rows : ");
    scanf("%d", &row);

    float *arr[row];   // Static rows
    int col[row];      // Columns for each row

    /* Read columns and allocate dynamically */
    for (int i = 0; i < row; i++)
    {
        printf("Enter no of columns in row[%d] : ", i);
        scanf("%d", &col[i]);

        // Allocate (columns + 1) for storing average
        arr[i] = malloc((col[i] + 1) * sizeof(float));
    }

    /* Read values and calculate average */
    scan(arr, row, col);

    printf("\nBefore sorting output is:\n\n");
    print(arr, row, col);

    /* Sort rows based on average */
    sort(arr, row, col);

    printf("\nAfter sorting output is:\n\n");
    print(arr, row, col);

    /* Free memory */
    for (int i = 0; i < row; i++)
        free(arr[i]);

    return 0;
}

/* Function to read values and store average */
void scan(float *arr[], int row, int col[])
{
    for (int i = 0; i < row; i++)
    {
        float sum = 0;

        printf("Enter %d values for row[%d] : ", col[i], i);

        for (int j = 0; j < col[i]; j++)
        {
            scanf("%f", &arr[i][j]);
            sum += arr[i][j];
        }

        // Store average in extra memory
        arr[i][col[i]] = sum / col[i];
    }
}

/* Function to print rows */
void print(float *arr[], int row, int col[])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= col[i]; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n\n");
    }
}

/* Sort rows based on average (last element of each row) */
void sort(float *arr[], int row, int col[])
{
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = i + 1; j < row; j++)
        {
            if (arr[i][col[i]] > arr[j][col[j]])
            {
                // Swap row pointers
                float *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                // Swap column sizes also
                int t = col[i];
                col[i] = col[j];
                col[j] = t;
            }
        }
    }
}