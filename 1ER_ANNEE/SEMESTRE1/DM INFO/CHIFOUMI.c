/*******
* Read input from STDIN
* Use: printf(...) or fprintf( stdout, ...) to output your result to stdout.
* Use: fprintf(stderr, ...);  to output debugging information to stderr.
* ***/
#include <stdlib.h>
#include <stdio.h>
#include "libisograd.h"

int main() {
 char s[1024];

  while (scanf("%s", &s) != EOF) {
      while (s[1] != '\0')
      {
          if ((s[0] == 'P' && s[1] == 'C') || (s[0] == 'C' && s[1] == 'F' ) || (s[0] == 'F' && s[1] == 'P'))
          {
              for(int i = 1; s[i] != '\0'; i++)
              {
                  s[i] = s[i+1];
              }
          }
          else
          {
              for(int i = 0; s[i] != '\0'; i++)
              {
                  s[i] = s[i+1];
              }
          }
          
      }
  }

  printf("%c", s[0]);
  return 0;
}