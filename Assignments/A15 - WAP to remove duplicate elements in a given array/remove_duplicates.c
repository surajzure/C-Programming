#include <stdio.h>
void fun(int arr1[], int size, int arr2[], int *new_size)
{
    int i,j,duplicate;
    * new_size=0;
    
    // 1. Reset the "Remote Control" to 0. 
    // This changes the variable inside main() to 0
    for(i=0;i<size;i++)
    {
        duplicate=0;
        // 2. Check the basket (arr2).
        // We look up to the current value of *new_size
        for(j=0;j<*new_size;j++)
        {
            
            if(arr1[i]==arr2[j])
            {
                duplicate=1;
                break;
            }
        }
        // 3. If unique, add to arr2 and press "Up" on the remote
        if(duplicate==0)
        {
            // Use *new_size as the index
            arr2[*new_size]=arr1[i];
            // IMPORTANT: Increment the value the pointer points to.
            // We use parentheses (*new_size)++ to be safe.
            (*new_size)++;
        }
    }
}
int main()
{
    int i,size,new_size=0;
    printf("Enter the size: ");
    scanf("%d",&size);
    int arr1[size],arr2[size];
    
    printf("Enter elements into the array:");
    
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr1[i]);
    }
    fun(arr1,size,arr2,&new_size);
    printf("After removing duplicates: ");
    for(i=0;i<new_size;i++)
    {
        printf("%d ",arr2[i]);
    }
}