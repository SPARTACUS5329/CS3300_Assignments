#include <stdio.h>

int main() {
  /* As long as this is working */
  /* And this
   * is working */
  // printf("Something\n"); // And this is also working
  // comments should be fine

  int a;
  a = 1;
  char str[10];

  if (a < 4) {
    str[0] = 'B';
    str[1] = 'B';
  } else {
    str[0] = 'C';
    str[1] = 'C';
  }

  str[a + 1] = '\0';
  printf("%s", str);

  return 0;
}
