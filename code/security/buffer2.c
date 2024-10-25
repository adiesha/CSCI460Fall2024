#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
  char buf[50];

  strcpy(buf, input);
  printf("You entered %s\n", buf);
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    vulnerable_function(argv[1]);
  } else {
    printf("Please provide an input.\n");
  }
  return 0;
}