/*Name:Suraj sunil zure 
Date:2/12/2025
Discription::pyramid pattern
Sample input and Output:
If n = 5, then,
5
4 5
3 4 5
2 3 4 5
1 2 3 4 5
2 3 4 5
3 4 5
4 5
5
*/
#include<stdio.h>
int main()
{
    int i,j,num;
    printf("Enter the number: ");
    scanf("%d",&num);
    
    
    //There is Nested Loop
   //Top part 
  for(i=num;i>=1;i--)
   {
        for(j=i;j<=num;j++)
        {
            
            printf("%d ",j);
            
        }
            printf("\n");
    }
       
    //Bottom part
     for(i=2;i<=num;i++)
    {
        for(j=i;j<=num;j++)
        {
            
            printf("%d ",j);
            
        }
            printf("\n");
    }
    
}