#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
        int a, b;
        printf("enter value of a:");
        scanf("%d", &a);
        printf("\nenter value of b:");
        scanf("%d", &b);
        swap(&a, &b);
        printf("\nswapped: a = %d, b = %d", a, b);
        return 0;

}
