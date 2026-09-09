/* Name: Suraj sunil zure
Date:05/12/2025
Description:The median of a finite list of numbers can be found by arranging all the numbers from lowest value to highest value and picking the middle one.
sample input and output:
Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 5

Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 3 7 8 5

Median of array1 : 4
Median of array2 : 7
Median of both arrays : 5.5                         
Test Case 2:
Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 4
Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 13 7 5
Median of array1 : 4
Median of array2 : 9.5                                      
Median of both arrays : 6.75 8
*/
#include<stdio.h>
int main()
{
    int i,j,size,size1;
    float sum=0,sum1=0,avg=0;
    
    //Size OF ARRAY1
    //printf("Enter the 'n' value for Array A: ");
    scanf("%d",&size);
    int arr[size];
    
    //Size OF ARRAY2
    //printf("Enter the 'n' value for Array B: ");
    scanf("%d",&size1);
    int arr1[size1];
    
    // ARRAY 1
    //printf("Enter the element one by one for Array A: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    // for(i=0;i<size;i++)
    // {
    //     printf("%d",arr[i]);
    // }
    
    //ARRAY 2
    //printf("Enter the element one by one for Array B: ");
    for(i=0;i<size1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    //   for(i=0;i<size1;i++)
    // {
    //     printf("%d",arr1[i]);
    // }
    
    //Bubble Sorting 
    //ARRAY 1
    
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
            }
            
        }
    }
    //Bubble Sorting 
    //ARRAY 2
    
    for(i=0;i<size1-1;i++)
    {
        for(j=0;j<size1-1-i;j++)
        {
            if(arr1[j]>arr1[j+1])
            {
                int temp=arr1[j];
                    arr1[j]=arr1[j+1];
                    arr1[j+1]=temp;
            }
            
        }
    }
    
    //Median of ARRAY 1
     // to find median first sum should be zero or it will take garbage value. 
    if(size % 2 == 0)
    {
        sum=arr[size/2]+arr[(size/2)-1];
        sum=sum/2;
    }
    else
    {
        sum=arr[size/2];
    }
    printf("Median of array1 : %g\n",sum);
    
     //Median of ARRAY 2
     // to find median first sum should be zero or it will take garbage value. 
    if(size1 % 2 ==0)
    {
        
        sum1=arr1[size1/2]+arr1[(size1/2)-1];
        sum1=sum1/2;
    }
    else
    {
        sum1=arr1[size1/2];
    }
    printf("Median of array2 : %g\n",sum1);
    
    //Average of two Median
    
    avg=sum+sum1;
    avg=avg/2;
    printf("Median of both arrays : %g\n",avg);
    
}