#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main()
{
        int a = INT_MAX;
        float b = FLT_MAX;
        double c = DBL_MAX;
        printf("size integer:%d\n max integer:%d\n", (int)sizeof(a), a);
        printf("size float:%d\n max float:%e\n", (int)sizeof(b), b);
        printf("size double:%d\n max double:%e\n", (int)sizeof(c), c);
        return 0;
}
