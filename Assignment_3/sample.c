#include <stdio.h>
int b;
int i;
char s;

int foo(int a) {
  foo(a);
  return 0;
}

int main() {
  int a;
  a = 3;
  if (a < 3) {
    foo(a);
  }
  return 0;
}
