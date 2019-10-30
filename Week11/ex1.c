#include <linux/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char *s = "This is a nice day\n";
    int inp = open("ex1.txt", O_RDWR),size = (int) strlen(s);
    ftruncate(inp, size);
    char *file_addr = mmap(NULL, (size_t) size, PROT_WRITE, MAP_SHARED, inp, 0);

    strcpy(file_addr, s);

    munmap(file_addr, (size_t) size);

    close(inp);

    return 0;
}

