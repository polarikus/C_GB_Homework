#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <dir.h>
//Lesson 11

int main(int argc, char **argv) {
    if(argv[1]){
        ls_files(argv[1]);
    } else{
        ls_files(".");
    }
}




