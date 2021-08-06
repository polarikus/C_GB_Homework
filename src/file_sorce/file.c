//
// Created by i9607 on 06.08.2021.
//
#include "file.h"
#include <stdio.h>
#include <errno.h>

int cp_file(const char source[], const char destination[]){

    char   buffer[MAX_BSZ];
    int err;
    size_t size, len;
    FILE*  fout, *fin;

    if((fin = fopen(source, "rb")) == NULL)
        return errno;

    if((fout = fopen(destination, "wb")) == NULL){
        err = errno;
        fclose(fin);
        return err;
    }

    err = 0;
    while(((size = fread(buffer, sizeof(char), MAX_BSZ, fin)) > 0) && ((err = ferror(fin)) == 0)){
        len = fwrite(buffer, sizeof(char), size, fout);
        if((len != size) || (ferror(fout) != 0)){
            err = ferror(fout);
            break;
        }
    }
    printf("Copy done. Transfered %zu bytes", len);

    fclose(fin);
    fclose(fout);

    return err;


}





