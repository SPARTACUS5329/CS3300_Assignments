// MiniC program for printing prime numbers from 2 to 100

#include<stdio.h>

int prime(int n)
{
    int div;
    int quo;
    int ret;
    
    div = 2;
    ret = 1;
    while(div * div < n)
    {
        quo = n/div;
        if(quo*div == n){ret = 0;}
        div =  div + 1;
    }
    return ret;
}
  
int main() 
{
    int n;
    int i;
    n = 100;
    i = 2;

    while(i < n)
    {
        if(prime(i)==1){printf("%d\n",i);}
        i = i+1;
    }
    return 0;
}