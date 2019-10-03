#include <stdio.h>
#include <stdlib.h>

int main(){
  int m,*a;
  scanf("%d", &m);
  a = malloc(m*sizeof(int));
  for (int i=0;i<m;i++)
    a[i]=i;
  for (int i=0; i<m; i++)
    printf("%d ", a[i]);
  free(a);
  return 0;
}
