#include "syscall.h"
#include "stdio.h"
#include "strcat.c"

int main () {
   int i;
   char * fileName = "nonExistent";
   for (i = 2; i <= 20; i++) {
      char * num[32];
      sprintf(num, "%d", i);
      strcat(fileName, num);

      int fdNE = open(fileName);
      printf("fdNE: %d; Supposed to be -1\n", fdNE);
      fdNE = creat(fileName);
      if (i < 16) {
         printf("fdNE: %d; Supposed to be %d\n", fdNE, i);
      } else {
         printf("fdNE: %d; Upper Limit Hit, thus supposed to be -1\n", fdNE);
      }
   }

   halt();
   return 0;
}

