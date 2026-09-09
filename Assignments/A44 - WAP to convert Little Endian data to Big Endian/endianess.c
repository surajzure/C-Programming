/*Name:Suraj zure
Date:10/02/2026
Description:Check the memory assigning order of variables for checking whether little endian or big endian machine
Little Endian:
--------------
Say int i = 10; gets stored in memory at
1000
1001
1002
1003
where 1000 contains LSB of i and 1003 contains MSB of i
char *ptr = &i; the ptr will now contain 1000

Big Endian:
 -----------
Say int i = 10; gets stored in memory at
1000
1001           
1001
1003  
where 1000 contains MSB of i and 1003 contains LSB of i
char *ptr = &i; the ptr will now contain 1000

Read 2 byte or 4 byte data according to given size(short or Int).
Swap the bytes and convert the given data to Big Endian 
Sample input output

Enter the size: 2
Enter any number in Hexadecimal: ABCD
After conversion CDAB

Enter the size: 4
Enter any number in Hexadecimal: 12345678
After conversion 78563412*/
#include<stdio.h>
int little_to_big(void *ptr,int size);
int main()
{
    unsigned int num;
    unsigned short int num1;
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    if(size==2)
    {
        printf("Enter any number in Hexadecimal: ");
        scanf("%hx",&num1);
        little_to_big(&num1,size);
        printf("After conversion %X",num1);
    }
    else if(size == 4)
    {
        printf("Enter any number in Hexadecimal:");
        scanf("%x",&num);
        little_to_big(&num,size);
        printf("After conversion %X",num);
    }
    else
    {
        printf("Invalid input");
    }
}

int little_to_big(void *ptr,int size)
{ 
    char * swap =(char *)ptr; // Type casting and storing it in swap
    for(int i =0;i<size/2;i++)
    {
        char temp = swap[i];
        swap[i] = swap[size-i-1];
        swap[size-i-1] = temp;

    }
}