#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int inp1 = open("ex1.txt", O_RDWR), inp2 = open("ex1.memcpy.txt", O_RDWR);
    struct stat st;
    stat("ex1.txt", &st);
    int size = (int) st.st_size;
    ftruncate(inp2, size);
    char *map1 = mmap(NULL, (size_t) size, PROT_READ, MAP_SHARED, inp1, 0);
    char *map2 = mmap(NULL, (size_t) size, PROT_WRITE, MAP_SHARED, inp2, 0);
    strcpy(map2, map1);
    munmap(map1, (size_t) size);
    munmap(map2, (size_t) size);
    close(inp1);
    close(inp2);
    return 0;
}
