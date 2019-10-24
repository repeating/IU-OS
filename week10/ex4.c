#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *dir_path = "./tmp/";
    DIR* dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Error\n");
        return -1;
    }

    struct dirent *dp;
    while ((dp = readdir(dir)) != NULL) {
        char *name = dp->d_name;
        if (*name != '.') {
            struct stat st;
            char path[50];
            strcpy(path, dir_path);
            strcat(path, name);
            stat(path, &st);
            if (st.st_nlink > 1) {
                printf("File \'%s\' has %hu links\n", name, st.st_nlink);
                char cmd[100];
                strcpy(cmd, "find . -inum ");
                char ino[20];
                sprintf(ino, "%d", st.st_ino);
                strcat(cmd, ino);
                system(cmd);
            }
        }
    }
    closedir(dir);

    return 0;
}
