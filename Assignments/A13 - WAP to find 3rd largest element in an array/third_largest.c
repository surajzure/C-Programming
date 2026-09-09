#include <stdio.h>

int third_largest(int arr[], int size);

int main()
{
    int i,size, ret;
    
    //Read size from the user
    printf("Enter the size of the array :");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements into the array:");
     for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    
    //Read elements into the array
    
    //funtion call
    ret = third_largest(arr, size);
    
    printf("Third largest element of the array is %d\n", ret);
}

int third_largest(int arr[], int size)
{
    int i,second_largest,ret;
    int small=arr[0];
    int largest=arr[0];
    int third_largest;
    
 
    //Comparing array and finding largest of the array element
     for(i=0;i<size;i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
       //Comparing array and finding smallest of the array element
    for(i=0;i<size;i++)
    {
        if(arr[i]<small)
        {
            small=arr[i];
        }
    }
    
    //Comparing array and finding Second-largest of the array element
    second_largest=small;
    for(i=0;i<size;i++)
    {
        if(arr[i]>second_largest && arr[i]<largest)
        {
        second_largest=arr[i];
        }
    }
    
    //Comparing array and finding Third-largest of the array element
    third_largest=small;
    for(i=0;i<size;i++)
    {
       if(arr[i] > third_largest && arr[i] < second_largest)
       {
        third_largest=arr[i];
        }
    }
    return third_largest;
    
}

