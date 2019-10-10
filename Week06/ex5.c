#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
void F(int id) {
    if (id == SIGTERM)
        puts("SIGTERM!");
}
int main() {
    pid_t id;
    id = fork();
    if (id == -1) {
        perror("fork error");
        exit(1);
    }
    if (id == 0) {
        while (1) {
            puts("Hello, it's me!");
            sleep(1);
        }
    } else {
        sleep(10);
        if (signal(SIGTERM, F) == SIG_ERR)
            puts("NO SIGKILL");
    }
    return 0;
}
