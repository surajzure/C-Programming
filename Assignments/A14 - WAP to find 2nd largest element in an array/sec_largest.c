#include <stdio.h>

int sec_largest(int arr[], int size)
{
    int i,second_largest,ret;
    int small=arr[0],largest=arr[0];
    //Comparing array and finding smallest of the array element
    for(i=0;i<size;i++)
    {
        if(arr[i]<small)
        {
            small=arr[i];
        }
    }
    
 
    //Comparing array and finding largest of the array element
    for(i=0;i<size;i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
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
    return second_largest;
    
}

int main()
{
    int i,size, ret;
    
    //Read size from the user
    printf("Enter the size of the array :");
    scanf("%d", &size);
    
    int arr[size];
    
    //Read elements into the array
    printf("Enter the elements into the array: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    //funtion call
    ret = sec_largest(arr, size);
    
    printf("Second largest element of the array is %d\n", ret);
}