#include <stdio.h>

void read(char *st) 
{
	gets(st); //reading all string until \n
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

