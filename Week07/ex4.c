#include <stdlib.h>
#include <stdio.h>

void *realloc(void *p, size_t siz) {
  void *nxt = NULL;
  if(!siz)
        nxt = malloc(siz);
  if(p && !siz)
    for(char *i=p; i<(char*)p+siz; i++)
      *(char*)nxt = *(char*)i;
  if(p && siz) free(p);
  return nxt;
}

int main(){

        return 0;
}
