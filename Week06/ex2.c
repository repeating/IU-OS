#include<stdio.h>
#include<unistd.h>

int main(){
  
  int pip[2];
  pipe(pip);
  pid_t pide = fork();
  if (pide == 0) {
    char str[10];
    close(pip[1]);
    read(pip[0], str, 10);
    printf("%s\n", str);
  } 
  else {
    char str[] = "anything";
    close(pip[0]);
    write(pip[1], str, 10);
  }
}
