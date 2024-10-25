#include <stdio.h>

int foo(int x) { return 0; }

int main() {
  int a = 3;

  foo(2);

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
