#include <stdio.h>
#include <stdlib.h>
#include "src/file_sorce/file.h"
//Lesson 10


int main(int argc, char **argv) {
    int result = cp_file("../test.txt", "../test2.txt");
    if(result != 0){
        perror("Error copy file");
    }
    return 0;
}




