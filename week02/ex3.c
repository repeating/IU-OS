#include <stdio.h>

int main() {
    int i, j, n, k;
    printf("Enter value of n: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        for (k = 0; k <= n-i-1; k++)
        {
            printf(" ");
        }
        for (j = 1; j <= (2*i-1); j++)
        {
            printf("*");
        }
        printf("\n");

    }
}
