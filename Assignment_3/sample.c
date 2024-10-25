#include <stdio.h>
int b;
int i;
char s;

int foo(char str[2], int a) { return 0; }

int main() {
  int a = 3;

  if (a < 3)
    a = 2;
  else
    a = 1;

  printf("Hello");

  return 0;
}
