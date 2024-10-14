#include <stdio.h>

int add(int a, int b) {
  int result;
  result = a + b;
  return result;
}

int main() {
  int x;
  int y;
  int sum;
  x = 5;
  y = 10;
  sum = add(x, y);
  printf("Sum is %d\n", sum);
  return 0;
}
