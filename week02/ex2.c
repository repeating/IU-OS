#include <stdio.h>
#include <string.h>

int main()
{
        char array[100];

        printf("Enter a string to reverse\n");
        gets(array);

        strrev(array);

        printf("Reverse of your string is \n%s\n", array);

    return 0;
}
