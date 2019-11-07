#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


int main() {
    int inp = open("/dev/random", O_RDWR);
    int out = open("ex1.txt", O_RDWR);
    char s[21];
    read(inp, s, 20);
    s[20] = '\0';
    write(out, s, 21);
    close(inp);
    close(out);
    return 0;
}
