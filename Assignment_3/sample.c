#include <stdio.h>
int b;
int i;
char s;

int foo(int r) { return 0; }

int main() {
  int a;
  a = 3 + 5 * 4;
  b = a + 2;
  foo(a);
  return 0;
}
