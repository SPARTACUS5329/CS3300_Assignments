// MiniC program to test the major constructs

#include<stdio.h>
char ascii[10];

int foo(char str[]) {
   str[0] = 'A';
   return 0;
}

int main()
{
   char str[10];
   str[0] = 'A';
   ascii[1] = 'A';
   foo(str);
   return 0;
}
