#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){

  char *qr;
  for (int i=0; i<10; i++){
    qr = malloc(10 * 1024 * 1024, sizeof(char));
    memset(qr, 0, 10 * 1024 * 1024 *sizeof(char));
    sleep(1);
  }

  return 0;
}
