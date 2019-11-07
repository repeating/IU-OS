#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main (int argc, char **argv) {
  char buffer[16384];
  read(0, buffer, 16384);
  int size = strlen(buffer);
  if (argc > 1) {
       if (strcmp (argv[1], "-a") == 0) {
            if (argc == 2) {
                printf ("Error: Missing filename after ‘-o’\n");
                return 1;
            }

            for (int i = 2; i < argc; i++) {
                int out = open(argv[i], O_RDWR|O_APPEND);
                write(out, buffer, size);
                close(out);
            }

       } else {
            for (int i = 1; i < argc; i++) {
                 int out = open(argv[i], O_RDWR|O_TRUNC);
                 write(out, buffer, size);
                 close(out);
            }
      }
  }

  printf ("%s", buffer);

  return 0;
}
