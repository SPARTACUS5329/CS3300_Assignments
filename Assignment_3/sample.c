#include <stdio.h>
int b;

int foo(int x) { return 0; }

int main() {
  int a = 3;

  b = 17;

  foo(2);
  foo(b);

  if (a < 3)
    a = 3;
  else
    a = 2;

  char str[10];
  /* As long as this is working */
  /* And this
   * is working */
  printf("Something\n"); // And this is also working
  // comments should be fine

  return 0;
}
