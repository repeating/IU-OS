#include <unistd.h>
#include <memory.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
void F(int id) {
    if (id == SIGTERM)
        printf("SIGTERM!\n");
}
int main(){
    int T[2], co;
    pipe(T);
    pid_t id1, id2, retId , tmp;
    id1 = fork();
    if (id1 == 0) {
    	printf("1st child id is %d\n", getpid());
    	sleep(10);
    	read(T[0], retId, sizeof(retId));
    	kill(retId, SIGSTOP);
    }
    if (id2 == 0) {
    	sleep(10);
    	printf("2nd child ID is %d\n", getpid());
    } 
	else {
    	write(T[1], tmp, sizeof(tmp)+1);
    	waitpid(id2, &co, 0);
    }
    close(T[0]);
    close(T[1]);
}
