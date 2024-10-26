#include <stdio.h>

int main() {
  /* As long as this is working */
  /* And this
   * is working */
  // printf("Something\n"); // And this is also working
  // comments should be fine
  char str[10];
  str[0] = 'B';
  str[1] = '\0';
  printf("%s", str);

  return 0;
}
