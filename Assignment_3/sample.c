#include <stdio.h>

int main() {
  /* As long as this is working */
  /* And this
   * is working */
  // printf("Something\n"); // And this is also working
  // comments should be fine
  int a = 3;
  int b = 7;
  char str[10];
  if (a <= 3 && b == 7) {
    str[0] = 'P';
    str[1] = 'R';
    str[2] = 'O';
    str[3] = '\0';
  } else {
    str[0] = 'N';
    str[1] = 'O';
    str[2] = 'O';
    str[3] = 'B';
    str[4] = 'S';
    str[5] = '\0';
  }

  printf("%s\n", str);

  return 0;
}
