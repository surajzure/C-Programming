/* Name:Suraj Sunil Zure.
Date:
Description:Read n and n no.of elements from user and store them into an array.
Run a loop for printing the elements in sorted order.
Sample input and output:

Enter the size : 5
Enter 5 elements 
10 1 3  8 -1
After sorting: -1 1 3 8 10
Original array values 10 1 3 8 -1

Test Case 2:
Enter the size : 7
Enter 7 elements 
1 3 2 5 4 7 6
After sorting: 1 2 3 4 5 6 7
Original array values 1 3 2 5 4 7 6

Test Case 3:
Enter the size : 4
Enter 4 elements 
-1 -2  4 3
After sorting: -2 -1 3 4
Original array values -1 -2  4 3
*/
#include <stdio.h>
void print_sort(int arr[],int size)
{
    int iter,j,temp;
    for(iter = 0 ; iter < size-1; iter++)
    {
       for( j= 0; j< size-iter-1; j++)
       {
           if(arr[j] > arr[j+1] )
           {
               temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
    }
    
    for(iter = 0 ;iter < size; iter++)
    {
        printf("%d ",arr[iter]);
    }
     
    
}

int main()
{
    int size, iter;
    //printf("Enter the size: ");
    scanf("%d", &size);
    
    int arr[size],arr1[size];
    
   // printf("Enter %d elements\n",size);
    
    for (iter = 0; iter < size; iter++)
    {
        scanf("%d", &arr[iter]);
    }
    
    for( iter = 0; iter < size; iter++)
    {
        arr1[iter]=arr[iter];
    }
    
    printf(" After sorting ");
    
    print_sort(arr, size);
    
    printf("\nOriginal array values");
    
       for(iter = 0 ;iter < size; iter++)
    {
        printf(" %d ",arr1[iter]);
    }
    
 
}