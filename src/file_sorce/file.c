//
// Created by i9607 on 06.08.2021.
//
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

void cp_file(const char source[], const char destination[]){

    printf("source: %s destination: %s\n", source, destination);
    FILE *f;
    int N = 0;
    char buffer[19];
    f = fopen(source, "rb");
    signed char c;

    if (f == NULL){
        perror("get_in_file: file not found");
        exit(-1);
    }
    int ctr = 0;
    while ((c= fgetc(f)) !=EOF){
        buffer[ctr] = c;
        ctr++;
    }
    buffer[ctr] = 0;
    fclose(f);
    f = fopen(destination, "wb");
    if (f == NULL){
        perror("get_in_file: file not found");
        exit(-1);
    }
    fprintf(f, "%s", buffer);
    fclose(f);
    printf("%s", buffer);
}





