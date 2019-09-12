#include <stdio.h>
int main()
{
    int pid = fork();
    int n = 256;
    if (pid ==0)
    {
        printf("Hello from child [%d-%d]\n", pid, n);
    }
    else if (pid > 0)
    {
        printf("Hello from parent [%d - %d]\n", pid, n);
    }
	else
    {
        printf("Error\n");
    }    
}
