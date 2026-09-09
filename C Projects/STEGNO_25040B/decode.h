#ifndef DECODE_H
#define DECODE_H

#include <stdio.h>
#include "types.h"

/*
 * Structure to store information required for decoding
 */

typedef struct _DecodeInfo
{
    /* Encoded image info */
    char *src_image_fname;
    FILE *fptr_src_image;

    /* Secret output file */
    char *secret_fname;
    FILE *fptr_secret;

    /* Secret file extension */
    int extn_size;
    char extn[10];

    /* Secret file size */
    int secret_file_size;

} DecodeInfo;


/* Function Prototypes */

/* Read and validate arguments */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Open encoded image */
Status open_decode_files(DecodeInfo *decInfo);

/* Decode magic string */
Status decode_magic_string(DecodeInfo *decInfo);

/* Decode extension size */
Status decode_secret_file_extn_size(DecodeInfo *decInfo);

/* Decode extension */
Status decode_secret_file_extn(DecodeInfo *decInfo);

/* Decode secret file size */
Status decode_secret_file_size(DecodeInfo *decInfo);


Status decode_secret_file_data(DecodeInfo *decInfo);

char decode_byte_from_lsb(char *image_buffer);

/* Decode integer from 32 bytes */
int decode_size_from_lsb(char *image_buffer);

Status do_decoding(DecodeInfo *decInfo);



#endif