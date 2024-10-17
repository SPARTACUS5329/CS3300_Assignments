// MiniC program for simple short-circuiting 
#include<stdio.h>

int global;

int sideEffect()
{
    global = global + 1;
    return 0;
}

int factorial(int x)
{
    int res;
    if(x==0)
    {
        res = 1;
    }
    else
    {
        res = x * (factorial(x-1));
    } 
    return res;
}

int main()
{
    int n;
    n = 10;
    global = 0;
    while( sideEffect() > 0 || n>=0)
    {
       printf("Factorial of %d is %d\n",n,factorial(n));
       printf("Global = %d\n",global);
       n = n -1;
    }
    return 0; 
}
