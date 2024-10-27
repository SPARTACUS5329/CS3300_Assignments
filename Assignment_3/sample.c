// Minic Program to test globals and arguments evaluation
#include<stdio.h>
int a;
int b;


int set_a()
{
    a = 1;
    printf("12\n");
    return 1;
}

int set_b()
{
    b = 1;
    printf("52\n");
    return 1;
}

int unset_a()
{
    a = 0;
    printf("77\n");
    return a;
}

int unset_b()
{
    b = 0;
    printf("8234\n");
    return a;
}

int main()
{
    a = 0; b = 0;
    if (set_a() == 1 && set_b() == 1) { 
      printf("1241\n");
    } else {
      printf("-1241\n");
    } 
    if (set_b() == 1 && set_a() == 1) { 
      printf("2445\n");
    } else {
      printf("-2445\n");
    }
    if ((unset_a() == 1) && (unset_b() == 1)) {
      printf("4562");
    } else {
      printf("-4562");
    }
    if ((unset_b()==1) && (set_a()==1)) {
      printf("352");
    } else {
      printf("-352");
    }
    if ((set_b()==1) && (unset_a()==1)) {
      printf("986");
    } else {
      printf("-986");
    }
    printf("\n");
    return 0;
}
