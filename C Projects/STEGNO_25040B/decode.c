#include <stdio.h>
#include <string.h>
#include "decode.h"
#include "common.h"
#include "types.h"

/* Validate decode arguments */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    // USE: strstr and strcmp used to check file extension
    // argv[2] => encoded image, argv[3] => output file (optional)

    // Step 1: Check encoded image extension
    char *src_ptr = strstr(argv[2], ".");

    // If no extension OR not ".bmp", return failure
    if(src_ptr == NULL || strcmp(src_ptr, ".bmp") != 0)
    {
        printf("Error: Encoded image must have .bmp extension\n");
        return e_failure;
    }

    // Step 2: Store encoded image file name
    decInfo->src_image_fname = argv[2];

    // Step 3: Check output file name
    if(argv[3])   // ⚠️ No argc check (can cause issue if argv[3] not passed)
    {
        char *ptr = strstr(argv[3], ".");

        // Remove extension if present
        if(ptr != NULL)
        {
            *ptr = '\0';   // ⚠️ Modifies original argv (not safe)
        }

        decInfo->secret_fname = argv[3];
    }
    else
    {
        // Default output file name
        decInfo->secret_fname = "stego";
    }

    return e_success;
}


/* Open encoded image and skip BMP header */
Status open_decode_files(DecodeInfo *decInfo)
{
    // Open encoded image file
    decInfo->fptr_src_image = fopen(decInfo->src_image_fname, "r"); // ⚠️ Should be "rb" for binary

    if(decInfo->fptr_src_image == NULL)
    {
        printf("ERROR: Unable to open file\n");
        return e_failure;
    }

    /* Skip BMP header (first 54 bytes) */
    fseek(decInfo->fptr_src_image, 54, SEEK_SET);

    return e_success;
}

/* Verify magic string */
Status decode_magic_string(DecodeInfo *decInfo)
{
    char image_buffer[8];   // Buffer to read 8 bytes
    char decoded_char;
    int i = 0;

    // Loop through each character of MAGIC_STRING
    while(MAGIC_STRING[i] != '\0')
    {
        // Read 8 bytes from image
        fread(image_buffer, 1, 8, decInfo->fptr_src_image); // ⚠️ No fread check

        // Decode 1 byte from LSBs
        decoded_char = decode_byte_from_lsb(image_buffer);

        // Compare with original magic string
        if(decoded_char != MAGIC_STRING[i])
        {
            return e_failure;   // Mismatch
        }

        i++;
    }

    return e_success;
}

Status decode_secret_file_extn_size(DecodeInfo *decInfo)
{
    char image_buffer[32];

    // Read 32 bytes to decode integer
    fread(image_buffer, 1, 32, decInfo->fptr_src_image); // ⚠️ No fread check

    // Decode extension size
    decInfo->extn_size = decode_size_from_lsb(image_buffer);

    /* safety check */
    if(decInfo->extn_size > 9)
    {
        printf("Invalid extension size\n");
        return e_failure;
    }

    return e_success;
}

/* Decode 1 byte from 8 image bytes */
char decode_byte_from_lsb(char *image_buffer)
{
    char data = 0;

    // Extract LSB from each byte and build character
    for(int i = 0; i < 8; i++)
    {
        data = data | (image_buffer[i] & 1) << i;  // ⚠️ Bit order must match encoding
    }

    return data;
}

/* Decode integer from 32 bytes */
int decode_size_from_lsb(char *image_buffer)
{
    int data = 0;

    // Extract 32 bits and form integer
    for(int i = 0; i < 32; i++)
    {
        data = data | (image_buffer[i] & 1) << i;  // ⚠️ Bit order must match encoding
    }

    return data;
}

Status decode_secret_file_extn(DecodeInfo *decInfo)
{
    char image_buffer[8];

    // Loop for extension size
    for(int i = 0; i < decInfo->extn_size; i++)
    {
        fread(image_buffer, 1, 8, decInfo->fptr_src_image); // ⚠️ No fread check

        // Decode each character
        decInfo->extn[i] = decode_byte_from_lsb(image_buffer);
    }

    // Null terminate extension string
    decInfo->extn[decInfo->extn_size] = '\0';

    return e_success;
}

Status decode_secret_file_size(DecodeInfo *decInfo)
{
    char image_buffer[32];

    // Read 32 bytes and decode file size
    fread(image_buffer, 1, 32, decInfo->fptr_src_image); // ⚠️ No fread check

    decInfo->secret_file_size = decode_size_from_lsb(image_buffer);

    return e_success;
}

/* Decode secret file data */
Status decode_secret_file_data(DecodeInfo *decInfo)
{
    char image_buffer[8];
    char ch;

    // Loop for each byte of secret file
    for(int i = 0; i < decInfo->secret_file_size; i++)
    {
        // Read 8 bytes from image
        if(fread(image_buffer, 1, 8, decInfo->fptr_src_image) != 8)
        {
            return e_failure;  // Read error
        }

        // Decode character
        ch = decode_byte_from_lsb(image_buffer);

        // Write to output file
        fputc(ch, decInfo->fptr_secret);
    }

    return e_success;
}

/* Control complete decoding process */
Status do_decoding(DecodeInfo *decInfo)
{
    // Step 1: Open file
    if(open_decode_files(decInfo) != e_success)
    {
        printf("Error opening files\n");
        return e_failure;
    }

    printf("Decoding Magic String\n");

    // Step 2: Verify magic string
    if(decode_magic_string(decInfo) != e_success)
    {
        printf("Magic string mismatch\n");
        return e_failure;
    }

    printf("Decoding Extension Size\n");

    // Step 3: Decode extension size
    if(decode_secret_file_extn_size(decInfo) != e_success)
    {
        printf("Error decoding extension size\n");
        return e_failure;
    }

    printf("Decoding Extension\n");

    // Step 4: Decode extension
    if(decode_secret_file_extn(decInfo) != e_success)
    {
        printf("Error decoding extension\n");
        return e_failure;
    }

    printf("Decoding File Size\n");

    // Step 5: Decode file size
    if(decode_secret_file_size(decInfo) != e_success)
    {
        printf("Error decoding file size\n");
        return e_failure;
    }

    char output_fname[50];

    // Combine file name + extension
    sprintf(output_fname, "%s%s", decInfo->secret_fname, decInfo->extn); // ⚠️ No buffer safety

    // Open output file
    decInfo->fptr_secret = fopen(output_fname, "w"); // ⚠️ Should be "wb"

    if(decInfo->fptr_secret == NULL)
    {
        printf("Error creating output file\n");
        return e_failure;
    }

    printf("Decoding Secret Data\n");

    // Step 6: Decode file data
    if(decode_secret_file_data(decInfo) != e_success)
    {
        printf("Error: Unable to decode secret file data\n");
        return e_failure;
    }

    // Close output file
    fclose(decInfo->fptr_secret);

    printf("Decoding completed successfully\n");

    return e_success;
}