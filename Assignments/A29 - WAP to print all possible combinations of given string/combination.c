#include<stdio.h> 

void combination(char [],int ,int );
int my_strlen(char []);

int main()

{
        char str[100];
        int n;
        int res;
        printf("Enter a string: ");
        scanf("%100[^\n]",str);    
        n = my_strlen(str);
        combination(str,0,n-1);                       
        return 0;
}
