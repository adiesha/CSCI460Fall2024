#include <stdio.h>
#include<string.h>
int main(int argc, char **argv) {
  int valid =0;
  char str1[8] = "START";
  char str2[8];

  gets(str2);
  if (strncmp(str1, str2, 5) == 0) {
    valid = 1;
  }
  printf("buffer1: str1(%s), str2(%s), valid(%d)\n", str1, str2, valid);
}
