/*Project Title:
Image Steganography using LSB Technique in C
Description:
This project implements Image Steganography using the Least Significant Bit (LSB) technique in the C programming language.
The main objective of the project is to securely hide confidential data inside a BMP image file and retrieve it without 
noticeable changes to the image.
Studied the concept of Steganography
Learned how data can be hidden inside an image using LSB (Least Significant Bit)
Understood that:
Each byte of data is stored in 8 bytes of image data
Only the last bit (LSB) is modified, so the image looks unchanged

Name: Suraj zure
Batch:25040B
Batch_No:25026_285
*/
#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

OperationType check_operation_type(char *);

int main(int argc, char *argv[])
{
    EncodeInfo encInfo;
    DecodeInfo decInfo;

    // Step 1 : Check operation type
    OperationType op = check_operation_type(argv[1]);

    if(op == e_encode)
    {
        if(argc != 4 && argc != 5)
        {
            printf("Error: Encoding requires 4 or 5 arguments\n");
            return e_failure;
        }

        printf("Selected Encoding\n");

        // Validate encode arguments
        if(read_and_validate_encode_args(argv, &encInfo) != e_success)
        {
            printf("Error: Argument validation failed\n");
            return e_failure;
        }

        // Perform encoding
        if(do_encoding(&encInfo) != e_success)
        {
            printf("Error: Encoding failed\n");
            return e_failure;
        }
    }
    else if(op == e_decode)
    {
        if(argc != 3 && argc != 4)
        {
            printf("Error: Decoding requires 3 or 4 arguments\n");
            return e_failure;
        }

        printf("Selected Decoding\n");

        // Validate decode arguments
        if(read_and_validate_decode_args(argv, &decInfo) != e_success)
        {
            printf("Error: Argument validation failed\n");
            return e_failure;
        }

        // Perform decoding
        if(do_decoding(&decInfo) != e_success)
        {
            printf("Error: Decoding failed\n");
            return e_failure;
        }
    }
    else
    {
        printf("Error: Unsupported operation\n");
        return e_failure;
    }

    return e_success;
}

OperationType check_operation_type(char *symbol)
{
    if(strcmp(symbol, "-e") == 0)
    {
        return e_encode;
    }
    else if(strcmp(symbol, "-d") == 0)
    {
        return e_decode;
    }

    return e_unsupported;
}