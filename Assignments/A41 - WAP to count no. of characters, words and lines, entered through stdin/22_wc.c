/*Name:SUraj Sunil Zure
Date: 06/02/2026
Description:
Read characters from user till EOF
If EOF received, print the character count, word count, and line count.
Code should exactly work like wc command. 
Sample execution: -
Hello         world
Dennis    Ritchie
Linux
Character count : 39
Line count : 3
Word count : 5

Hello world
Dennis Ritchie
Linux
Character count : 33
Line count : 3
Word count : 5
*/
#include <stdio.h>
int main()
{
    int char_count = 0, line_count = 0, word_count = 0;
    char ch;
    int in_word = 0;   

    while ((ch = getchar()) != EOF) // To check the End Of File 
    {
        char_count++; // to count character

        if (ch == '\n')
        {
            line_count++; // to count number of lines 
        }

        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            in_word = 0;   // to check the there is any \n \t or " " 
        }
        else if (in_word == 0)
        {
            in_word = 1;   
            word_count++;
        }
    }

    printf("Character count : %d\n", char_count);
    printf("Line count      : %d\n", line_count);
    printf("Word count      : %d\n", word_count);

    return 0;
}
