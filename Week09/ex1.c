#include <stdio.h>
#include <stdlib.h>


#define AGING_BITS 31
#define EMPT -1
#define TO_READ 1
#define true 1
#define false 0

typedef int bool;


int Arr2[105] , Arr[105];
int Frames[] = {10, 50, 100};
int main()
{
	int times;
	for (times = 0; times < 3; times++) {
        FILE* fp = fopen("ex1.txt", "r");
        int FRAMES = Frames[times];
        int i;
        for (i = 0; i < FRAMES; i++)
            Arr2[i] = EMPT;
        i = 0;
        int t = 0, misses = 0, j;

        while (fscanf(fp, "%d", &j) == TO_READ) {
            bool fault = true;
            int Eld = 0;

            for (i = 0; i < FRAMES; i++) {
                if (Arr2[i] == j) {
                    Arr[i] = (1 << (AGING_BITS - 1)) & (Arr[i] / 2);
                    fault = false;
                } else {
                    Arr[i] = Arr[i] / 2;
                }
                if (Arr[i] < Arr[Eld] || Arr2[i] == EMPT)
                    Eld = i;
            }

            ++t;
            if (!fault) continue;
            ++misses;
            Arr[Eld] = 1 << (AGING_BITS - 1);
            Arr2[Eld] = j;
        }


        printf("frames => %d\t in total => %d\t #hits => %d\t #misses => %d\n", FRAMES, t, t - misses, misses);
        printf("hits/miss => %.2f\n", (double)(t-misses)/(misses));
        printf("------------\n");
	}

	return 0;
}

