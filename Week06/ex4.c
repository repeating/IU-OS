#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void F(int id) {
    if (id == SIGUSR1)
        puts("SIGUSR1");
    else if (id == SIGKILL)
        puts("SIGKILL");
    else if (id == SIGSTOP)
        puts("SIGSTOP");
}
int main() {
    if (signal(SIGKILL, F) == SIG_ERR)
        puts("NO SIGKILL");
    if (signal(SIGSTOP, F) == SIG_ERR)
        puts("NO SIGSTOP");
    if (signal(SIGUSR1, F) == SIG_ERR)
        puts("NO SIGUSR1");
    while(1)
        sleep(1);
}
