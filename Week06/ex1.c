#include<stdio.h>
#include<unistd.h>

int main(){
  int p[2];
  pipe(p);
  char s1[] = "text",s2[100];

  write(p[1], s1, 100);
  read(p[0], s2, 100);
  printf("%s\n", s2);
}
