/*
Namw:suraj zure
Date:
Description:
Treat &x and &x + 1 as characters address.
Both addresses difference will be sizeof x
Sample execution: -
Size of int : 4 bytes
Size of char : 1 byte
Size of float : 4 bytes
Size of double : 8 bytes
Size of unsigned int : 4 bytes
Size of long int : 8 bytes*/
#include <stdio.h>
// Macro to calculate size of any variable
// It treats addresses as char pointers to calculate byte difference
#define SIZE(x) ((char*)(&x + 1) - (char*)(&x))

int main()
{
    // Declare variables of different datatypes
    int a;               // integer variable
    char b;              // character variable
    float c;             // float variable
    double d;            // double variable
    unsigned int e;      // unsigned int variable
    long int f;          // long int variable

    // Print sizes using macro

    // &a + 1 → moves to next int location
    // Typecast to (char*) → treat as byte address
    // Difference gives size of int
    printf("Size of int : %ld bytes\n", SIZE(a));

    // Same logic applied for char
    printf("Size of char : %ld bytes\n", SIZE(b));

    // Same logic for float
    printf("Size of float : %ld bytes\n", SIZE(c));

    // Same logic for double
    printf("Size of double : %ld bytes\n", SIZE(d));

    // Same logic for unsigned int
    printf("Size of unsigned int : %ld bytes\n", SIZE(e));

    // Same logic for long int
    printf("Size of long int : %ld bytes\n", SIZE(f));

    return 0;   // Program ends successfully
}