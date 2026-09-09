/*Name:Suraj sunil zure
Date:
Description:
Read string1 and string2 from user.
Call my_strtok (string1, string2);
Should treat string2 as delimitter in string1 and should return 1 st field.
If you call again my_strtok (NULL, string2), it should return second field in string1 treating string2 as delimitter.
Sample execution: -
Test Case 1:
Enter string1 : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
Enter string2 : ;./-:
Tokens :
Bangalore
Chennai
Kolkata
Delhi
Mumbai
Test Case 2:
Enter string1 : -;Bangalore;;::---Chennai:;Kolkata:;Delhi:-
Enter string2 : ;./-:
Tokens :
Bangalore
Chennai
Kolkata
Delhi*/
#include <stdio.h>
// #include <string.h>
// #include <stdio_ext.h>

char *my_strtok(char str[], const char delim[]);

int main()
{
    char str[50], delim[50];
    
    //printf("Enter the string  : ");
    scanf("%s %s", str,delim);
    
   
 
    //printf("Enter the delimeter : ");
    //scanf(" %[^\n]", delim);
    
    
    char *token = my_strtok(str, delim);
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }
}
char *my_strtok(char str[], const char delim[])
{
    static char *ptr;
    if(str!=NULL)
    {
        ptr=str;
    }
    static int i=0;
    int start=i;
    while(ptr[i])
    {
       int j=0;
       int count=0;
        while(delim[j])
        {
            
            
            if(ptr[i]==delim[j])
            {
                ptr[i]='\0';
                
               if(ptr[i]=='\0'&&ptr[i-1]=='\0')
               {
                start++;
                count++;
                i++;
                continue;

               }
                i++;
                return &ptr[start];
            }
            j++;
        }
        if(count==0)
        i++;
    }
    if(ptr[start]!='\0')
    {
        return &ptr[start];
    }
    else
    {
        return NULL;
    }
}