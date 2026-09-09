#include <stdio.h>
#include<string.h>
#include "encode.h"
#include "types.h"
#include "common.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);
    /*Purpose: Move the file pointer to byte 18 of the BMP file
    Why?
    In a BMP file header, the width value starts at byte 18.*/

    /*In a BMP file format, the width of the image is stored at byte position 18–21
     and the height is stored at byte position 22–25 in the header. 
    So we move the file pointer to byte 18 using fseek() and read 4 bytes to get the width.
    After reading width, the file pointer automatically moves to the next 4 bytes,
    from where we read the height using fread().*/

    // Read the width (an int) size of int means 4 byte at a time one by one
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    printf("image size in bmp: %d\n",width * height * 3); // optional
    return width * height * 3;
}

   
uint get_file_size(FILE *fptr)
{
    //Find the size of secret file data
    fseek(fptr, 0, SEEK_END);
    uint size = ftell(fptr); //Ftell is used to get the current file location 
    return size;
}


/*
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    //USE :Strstr AND Strcmp functions can be used to check the file extensions of the input files
    //argv[2] => src image, argv[3] => secret file, argv[4] => dest image 
    //Step : Read the file names from argv and store in encInfo

    //Step 1: Check Source image extension  and store in *src_image_fname
    char *src_ptr = strstr(argv[2], ".");
    //char * src_ptr is used as pointer because it gives the address of substring 
    if(src_ptr == NULL || strcmp(src_ptr, ".bmp") != 0)
    /*We do not use *src_ptr because strcmp() needs a pointer to a string, and src_ptr already points to the string .bmp.
    Using *src_ptr would give only a single character, which is incorrect.*/
    {
        printf("Error: Source image must have .bmp extension\n");
        return e_failure;
    }

    //Step 2: Check the secret file extension and store in *secret_fname
    char *extn_ptr = strstr(argv[3], ".");

    if(extn_ptr == NULL)
    {
        printf("Error: Secret file must have extension\n");
        return e_failure;
    }

    if(strcmp(extn_ptr, ".txt") != 0 && strcmp(extn_ptr, ".c") != 0 && strcmp(extn_ptr, ".sh") != 0)
    {
        printf("Error: Secret file must be .txt / .c / .sh\n");
        return e_failure;
    }

    //Step 3:Check the dest image file extension and store in *dest_image_fname
    if(argv[4] != NULL)
    {
        char *ext_ptr = strstr(argv[4], ".");

        if(ext_ptr == NULL || strcmp(ext_ptr, ".bmp") != 0)
        {
            printf("Error: Destination image must have .bmp extension\n");
            return e_failure;
        }
    }
    //Step 4: 
    else
    {
        argv[4] = "default.bmp";
    }

    // Stored in structure , which is in encode.h 
    encInfo->src_image_fname  = argv[2]; //validating and stored in source image
    encInfo->secret_fname     = argv[3];
    strcpy(encInfo->extn_secret_file, extn_ptr); // Copying .txt in extn_secret_file[5].
    encInfo->dest_image_fname = argv[4];

    return e_success;
}

Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");//So it is not storing file data, it is storing an address., in struct it is pointer 
    /* File is opened,Address of the opened file is stored in the pointer*/
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)// Checking is there is any address or not , if yes go to NEXT step , if not return e failure
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

        return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

        return e_failure;
    }

    // Stego Image file
    encInfo->fptr_dest_image = fopen(encInfo->dest_image_fname, "w");

    /*Open the destination (stego) image in write mode
    If the file does not exist, it will be created
    If it exists, it will be overwritten*/

    // Do Error handling
    if (encInfo->fptr_dest_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->dest_image_fname);

        return e_failure;
    }

    // No failure return e_success
    return e_success;

/* We are storing the address in FILE because we have to use 
File operations like fwrite(), fprintf(), and fclose().
we can write the encoded image data into the destination image*/
}

Status check_capacity(EncodeInfo *encInfo) 
{
    // Step 1 : check_capacity get_image_size_for_bmp(src_fptr) ;
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);
    // Step2 : size_secret_file = get_file_size(secret_fptr);
     encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);
    // Step 3 : check_capacity > ((ALL ARE IN BITES)16+32+32+32)+(size_secret_file *8)

    /*Meaning of each value
        Value	Purpose
        16	bits used to store magic string size
        32	bits used to store magic string
        32	bits used to store secret file extension size
        32	bits used to store secret file size
        size_secret_file * 8	secret file data in bits*/
    if(encInfo->image_capacity <(16 +32 +(strlen(encInfo->extn_secret_file) * 8) +32 +(encInfo->size_secret_file * 8)))
    {
        printf("Error: Insufficient image capacity\n");
        return e_failure;
    }

    return e_success;

} 

Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{   
    char image_buffer[54];// Step 2 : Declare char imageBuffer[54]
    // Step 1 : Rewind the fptr_src_image;
    rewind(fptr_src_image);
    //Step 3 : Read 54 bytes from src image and store into the imageBuffer
    fread(image_buffer,1,54,fptr_src_image);
    //Step 4 : Write the 54 bytes (imageBuffer)into destination image
    fwrite(image_buffer,1,54,fptr_dest_image);
    // Step 5 : Check the offset of both pointer
    if(ftell(fptr_src_image) != ftell(fptr_dest_image))
    {
        return e_failure;
    }
    return e_success;

}

Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    // Step 1 : Declare buffer
    char image_buffer[8];

    int i = 0;

    // Step 2 : Loop through magic string
    while(magic_string[i] != '\0')
    {
        // Step 1 : Read 8 bytes from source image
        fread(image_buffer, 1, 8, encInfo->fptr_src_image);

        // Step 2 : Encode character into LSB
        encode_byte_to_lsb(magic_string[i], image_buffer);

        // Step 3 : Write encoded bytes to destination image
        fwrite(image_buffer, 1, 8, encInfo->fptr_dest_image);

        i++;
    }
    
    // Step 3 : Check the offset of both file pointers
    if(ftell(encInfo->fptr_src_image) != ftell(encInfo->fptr_dest_image))
    {
        return e_failure;
    }

    return e_success;
}

Status encode_secret_file_extn_size(int size, EncodeInfo *encInfo)
{
    // Step 1 : Declare buffer
    char image_buffer[32];

    // Step 2 : Read 32 bytes from source image
    fread(image_buffer, 1, 32, encInfo->fptr_src_image);

    // Step 3 :Call Encode size into LSB
    encode_size_to_lsb(size, image_buffer);

    // Step 4 : Write encoded data to destination image
    fwrite(image_buffer, 1, 32, encInfo->fptr_dest_image);

    // Step 5 : Check the offset of both pointer
    if(ftell(encInfo->fptr_src_image) != ftell(encInfo->fptr_dest_image))
    {
        return e_failure;
    }
    return e_success;
}


Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
    //Step 1 : Declare char image_Buffer[8]
    char image_buffer[8];
    //Step 2 : Generate the loop upto file_extn times
    int i=0;
    while( file_extn[i] != '\0' )
    {   
        //Step 1 : Read 8 bytes from source image
        fread(image_buffer,1,8,encInfo->fptr_src_image);
        //Step 2 : call the encode_byte_to_lsb(file_extn[i] , imagebuffer);
        encode_byte_to_lsb( file_extn[i], image_buffer);
        //Step 3 : Write the imageBuffer into the destination file
        fwrite(image_buffer, 1, 8,encInfo->fptr_dest_image);

        i++;

    }
    // Step 3 : Check the offset of both file pointers
    if(ftell(encInfo->fptr_src_image) != ftell(encInfo->fptr_dest_image))
    {
        return e_failure;
    }
    return e_success;
}


Status encode_secret_file_size(long file_size, EncodeInfo *encInfo)
{
    char image_buffer[32];

    fread(image_buffer,1,32,encInfo->fptr_src_image);

    encode_size_to_lsb(file_size, image_buffer);

    fwrite(image_buffer,1,32,encInfo->fptr_dest_image);

    if(ftell(encInfo->fptr_src_image) != ftell(encInfo->fptr_dest_image))
    {
        return e_failure;
    }

    return e_success;
}

Status encode_secret_file_data(EncodeInfo *encInfo)
{
     // Step 4 : Declare char imageBuffer[8]
    char imageBuffer[8];

    // Step 1 : Rewind the secret file pointer
    rewind(encInfo->fptr_secret);

    // Step 2 : Declare the char secret_file_data[secret_file_size]
    char secret_file_data[encInfo->size_secret_file];

    // Step 3 : Read the data from secret file up to the size times
    fread(secret_file_data, 1, encInfo->size_secret_file, encInfo->fptr_secret);

    // Step 5 : Generate the loop upto secret_file_size times
    for(int i = 0; i < encInfo->size_secret_file; i++)
    {
        // Step 1 : Read 8 bytes from src image store into imageBuffer
        fread(imageBuffer, 1, 8, encInfo->fptr_src_image);

        // Step 2 : call encode_byte_to_lsb
        encode_byte_to_lsb(secret_file_data[i], imageBuffer);

        // Step 3 : Write the imageBuffer into destination file
        fwrite(imageBuffer, 1, 8, encInfo->fptr_dest_image);
    }

    // Step 6 : Check the offset of both pointers
    if(ftell(encInfo->fptr_src_image) != ftell(encInfo->fptr_dest_image))
    {
        return e_failure;
    }
    else
    {
        return e_success;
    }
}

Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    char ch;

    // Step 1 : Generate loop upto EOF
    while (fread(&ch, 1, 1, fptr_src) == 1)
    {
        // Step 2 : Write 1 byte to destination image
        fwrite(&ch, 1, 1, fptr_dest);
    }

    // Step 3 : Check offset of both pointers
    if (ftell(fptr_src) != ftell(fptr_dest))
    {
        return e_failure;
    }
    return e_success;
    
}

Status encode_byte_to_lsb(char data, char *image_buffer)
{
    // Step 1 : generate the loop 8 times
    for(int i=0;i<8;i++)
    {
        // Step 1 : Get the bit from an data
        uint get=(data>>i) & 1;
        // Step 2 : clear the lsb bit of imageBuffer[i]
        image_buffer[i]=(image_buffer[i] & (~1));
        // Step 3 : set the got bit into the lsb bit of imageBuffer[i]
        image_buffer[i]=image_buffer[i]|get;
    }

    return e_success;
}

Status encode_size_to_lsb(int size, char *image_buffer)
{
// Step 1 : generate the loop 32 times
   for(int i=0;i<32;i++)
   {
    // Step 1 : Get the bit from an data
        uint get=(size>>i) & 1;
    // Step 2 : clear the lsb bit of imageBuffer[i]
        image_buffer[i]=(image_buffer[i] & (~1));
    // Step 3 : set the got bit into the lsb bit of imageBuffer[i]
        image_buffer[i]=image_buffer[i]|get;
   }
   
    return e_success;
}

Status do_encoding(EncodeInfo *encInfo)
{
    // Step 1 : Open required files
    if(open_files(encInfo) != e_success)
    {
        printf("Error: Unable to open files\n");
        return e_failure;
    }
    // Step 2 : Check capacity of image
    if(check_capacity(encInfo) != e_success)
    {
        printf("Error: Insufficient image capacity\n");
        return e_failure;
    }
    // Step 3 : Copy BMP header
    if(copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_dest_image) != e_success)
    {
        printf("Error: Failed to copy BMP header\n");
        return e_failure;
    }
    printf("BMP header copied\n");
    // Step 4 : Encode magic string
    if(encode_magic_string(MAGIC_STRING, encInfo) != e_success)
    {
        printf("Error: Magic string encoding failed\n");
        return e_failure;
    }
    printf("Magic string encoding\n");
    // Step 5 : Encode secret file extension size
    if(encode_secret_file_extn_size(strlen(encInfo->extn_secret_file), encInfo) != e_success)
    {
        printf("Error: Extension size encoding failed\n");
        return e_failure;
    }
    printf("Encoded secret file extn size\n");
    // Step 6 : Encode secret file extension
    if(encode_secret_file_extn(encInfo->extn_secret_file, encInfo) != e_success)
    {
        printf("Error: Extension encoding failed\n");
        return e_failure;
    }
    printf("Encoded secret file extn\n");
    // Step 7 : Encode secret file size
    if(encode_secret_file_size(encInfo->size_secret_file, encInfo) != e_success)
    {
        printf("Error: Secret file size encoding failed\n");
        return e_failure;
    }
    printf("Encoded secret file size\n");
    // Step 8 : Encode secret file data
    if(encode_secret_file_data(encInfo) != e_success)
    {
        printf("Error: Secret data encoding failed\n");
        return e_failure;
    }
    printf("Encoded secret file data\n");
    // Step 9 : Copy remaining image data
    if(copy_remaining_img_data(encInfo->fptr_src_image, encInfo->fptr_dest_image) != e_success)
    {
        printf("Error: Failed to copy remaining image data\n");
        return e_failure;
    }
    printf("Copied remaining image data\n");
    //If all the conditions are false then return e_success
    return e_success;
}