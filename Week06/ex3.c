#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int id) {
    if (id == SIGINT)
        printf("Programm was stopped by intercepting SIGINT signal.\n");
}

int main() {
    signal(SIGINT, handler);
    while (1) 
        sleep(2);
}
