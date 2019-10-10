#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){

  char *qr;
  struct rusage _rusage;

  for (int i=0; i<10; i++){
    qr = calloc(10 * 1024 * 1024, sizeof(char));
    memset(qr, 0, 10 * 1024 * 1024 * sizeof(char));
    getrusage(RUSAGE_SELF, &_rusage);
    printf("%ld KB\n", _rusage.ru_maxrss / 1024);
    sleep(1);
  }

  return 0;
}
