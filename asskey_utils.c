#include <stdio.h>

int main() {
  int myNum;
  printf("Type a number...");
  // scanf() changes the value of myNum so we need to pass the address of
  // myNum...?
  scanf("%d", &myNum);
  printf("Your number is: %d", myNum);
  return 0;
}
