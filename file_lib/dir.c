#include "dir.h"
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>

void ls_files(const char *path) {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(path);

    while ((ent=readdir(dir)) != false) {
        printf("%s\n", ent->d_name);
    }

    closedir(dir);
}
