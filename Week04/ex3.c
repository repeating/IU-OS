#include <stdio.h>

void read(char *st) 
{
	scanf("%s", st);
}

int main() 
{
	char array[100];
	while (1) 
    {
		printf("$ ");
		read(array);
		system(array);
	}
}
