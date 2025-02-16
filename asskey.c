#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("Num args: %d", argc);
  for (int i = 1; i < argc; i++) {
    printf("Argument %d: %s", i, argv[i]);
  }
  return 0;
}
