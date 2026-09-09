/*Name:Suraj sunil zure 
Date:27/11/20254
Discription: 

*/

#include<stdio.h>
int main()
{
    int day,nday,dest_day;
    printf("Enter the value of 'n':");
    scanf("%d",&nday);
    
    


     if(nday>0 && nday<366)
    {
         printf("Choose First Day :\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n.5Thursday\n6.Friday\n7.Saturday\n");
         printf("Enter the option to set the first day:");
         scanf("%d",&dest_day);
         
           if(dest_day>=1 && dest_day<=7)
             {
               dest_day=(nday+dest_day-1)%7;
                 switch(dest_day)
        
                {
                    case 1:
                    {
                         printf("The day is Sunday\n"); 
                         break;
                    }
                    case 2:
                    {
                       printf("The day is Monday\n"); 
                       break;
                    }
                    case 3:
                    {
                       printf("The day is Tuesday\n"); 
                       break;
                    }
                    case 4:
                    {
                       printf("The day is Wednesday\n"); 
                       break;
                    }
                    case 5:
                    {
                        printf("The day is Thursday\n"); 
                        break;
                    }
                    case 6:
                    {
                        printf("The day is Friday\n"); 
                        break;
                    }
                    case 0:
                    {
                       printf("The day is Saturday\n"); 
                       break;
                    }
                }
            }
            else
            {
                printf("Error:Invalid input, first day should be > 0 and <=7");
            }
    
        
    }
    
    else
    {
        printf("Error:Invalid input, n value should be > 0 and <= 365");
    }
    
  
   
}

