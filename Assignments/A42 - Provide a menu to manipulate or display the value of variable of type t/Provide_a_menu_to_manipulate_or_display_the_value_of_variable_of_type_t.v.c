/*Name:Suraj Zure
Date:
Description:
Allocate 8 consecutive bytes in memory
Provide a display menu
1. Add element
2. Remove element
3. Display element
4. Exit from the program
It should allow to add elements of different data types which data type size is less than or equal to 8
Sample execution: -
Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 2
Enter the char : k
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
-------------------------
0 -> k
-------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 1
Enter the int : 10
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
------------------------
0 -> k (char)
1 -> 10 (int)
------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 2
0 -> k
1 -> 10
Enter the index value to be deleted : 0
index 0 successfully deleted.
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 4*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8   // We allocate total 8 bytes of memory

/* Function declarations */
void menu();
void add_element(void *ptr, int *used, int type[], int *elements);
void display_element(void *ptr, int used, int type[], int elements);
void remove_element(void *ptr, int *used, int type[], int *elements);

int main()
{
    void *ptr = malloc(SIZE);   // Allocate 8 bytes dynamically

    int used = 0;               // Number of bytes currently used
    int type[SIZE];             // To store datatype info at each byte position
    int elements = 0;           // Number of elements inserted
    int choice;                 // Menu choice

    while (1)                   // Infinite loop for menu
    {
        menu();                 // Display menu
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_element(ptr, &used, type, &elements);
                break;

            case 2:
                remove_element(ptr, &used, type, &elements);
                break;

            case 3:
                display_element(ptr, used, type, elements);
                break;

            case 4:
                free(ptr);      // Free allocated memory
                exit(0);        // Exit program

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

/* Menu display function */
void menu()
{
    printf("\n1. Add element\n");
    printf("2. Remove element\n");
    printf("3. Display element\n");
    printf("4. Exit from the program\n");
    printf("Choice ---> ");
}

/* Function to add element */
void add_element(void *ptr, int *used, int type[], int *elements)
{
    int choice;

    printf("Enter the type you have to insert:\n");
    printf("1. int\n2. char\n3. float\n4. double\n");
    printf("Choice ---> ");
    scanf("%d", &choice);

    /* Insert INT */
    if (choice == 1 && *used + sizeof(int) <= SIZE)
    {
        int val;
        printf("Enter the int : ");
        scanf("%d", &val);

        // Copy integer bytes into allocated memory
        memcpy((char*)ptr + *used, &val, sizeof(int));

        type[*used] = 1;            // Mark this position as int
        *used += sizeof(int);       // Increase used bytes
        (*elements)++;              // Increase element count
    }

    /* Insert CHAR */
    else if (choice == 2 && *used + sizeof(char) <= SIZE)
    {
        char val;
        printf("Enter the char : ");
        scanf(" %c", &val);

        memcpy((char*)ptr + *used, &val, sizeof(char));

        type[*used] = 2;            // Mark as char
        *used += sizeof(char);
        (*elements)++;
    }

    /* Insert FLOAT */
    else if (choice == 3 && *used + sizeof(float) <= SIZE)
    {
        float val;
        printf("Enter the float : ");
        scanf("%f", &val);

        memcpy((char*)ptr + *used, &val, sizeof(float));

        type[*used] = 3;            // Mark as float
        *used += sizeof(float);
        (*elements)++;
    }

    /* Insert DOUBLE */
    else if (choice == 4 && *used + sizeof(double) <= SIZE)
    {
        double val;
        printf("Enter the double : ");
        scanf("%lf", &val);

        memcpy((char*)ptr + *used, &val, sizeof(double));

        type[*used] = 4;            // Mark as double
        *used += sizeof(double);
        (*elements)++;
    }

    else
    {
        printf("Memory Full!\n");   // If no space available
    }
}

/* Function to display elements */
void display_element(void *ptr, int used, int type[], int elements)
{
    if (elements == 0)
    {
        printf("No elements present.\n");
        return;
    }

    int i = 0;       // Byte tracker
    int index = 0;   // Logical index (0,1,2...)

    printf("-------------------------\n");

    while (i < used)
    {
        /* If INT */
        if (type[i] == 1)
        {
            int val;
            memcpy(&val, (char*)ptr + i, sizeof(int));
            printf("%d -> %d\n", index, val);
            i += sizeof(int);
        }

        /* If CHAR */
        else if (type[i] == 2)
        {
            char val;
            memcpy(&val, (char*)ptr + i, sizeof(char));
            printf("%d -> %c\n", index, val);
            i += sizeof(char);
        }

        /* If FLOAT */
        else if (type[i] == 3)
        {
            float val;
            memcpy(&val, (char*)ptr + i, sizeof(float));
            printf("%d -> %f\n", index, val);
            i += sizeof(float);
        }

        /* If DOUBLE */
        else if (type[i] == 4)
        {
            double val;
            memcpy(&val, (char*)ptr + i, sizeof(double));
            printf("%d -> %lf\n", index, val);
            i += sizeof(double);
        }

        index++;  // Increase logical index
    }

    printf("-------------------------\n");
}

/* Function to remove element using index */
void remove_element(void *ptr, int *used, int type[], int *elements)
{
    if (*elements == 0)
    {
        printf("No elements to delete.\n");
        return;
    }

    display_element(ptr, *used, type, *elements);

    int del_index;
    printf("Enter the index value to be deleted : ");
    scanf("%d", &del_index);

    int i = 0, index = 0;
    int delete_pos = -1;
    int size = 0;

    /* Find the element position */
    while (i < *used)
    {
        if (index == del_index)
        {
            delete_pos = i;

            if (type[i] == 1) size = sizeof(int);
            else if (type[i] == 2) size = sizeof(char);
            else if (type[i] == 3) size = sizeof(float);
            else if (type[i] == 4) size = sizeof(double);

            break;
        }

        if (type[i] == 1) i += sizeof(int);
        else if (type[i] == 2) i += sizeof(char);
        else if (type[i] == 3) i += sizeof(float);
        else if (type[i] == 4) i += sizeof(double);

        index++;
    }

    if (delete_pos == -1)
    {
        printf("Invalid index\n");
        return;
    }

    /* Shift remaining data left using memmove */
    memmove((char*)ptr + delete_pos,
            (char*)ptr + delete_pos + size,
            *used - delete_pos - size);

    *used -= size;       // Reduce used memory
    (*elements)--;       // Reduce element count

    printf("index %d successfully deleted.\n", del_index);
}