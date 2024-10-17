// MiniC program for gcd

#include<stdio.h>

int gcd(int a, int b)
{
    int result; int flag;
    int quo1; int quo2;

    flag = 1;
    
    if(a < b){result = a;}
    else {result = b;}

    while (flag == 1 && result > 0) 
    {
        quo1 = a/result;
        quo2 = b/result;
        if ((quo1*result == a) && (quo2*result == b)) {
            flag = 0;
        }
        result = result - 1;
    }

    if(flag == 0){result = result + 1;}
    
    return result;
}

int main() 
{
    int a;
    int b;
    a = 98; b = 56;
    printf("GCD of %d and %d is %d\n",a,b,gcd(a,b));
    return 0;
}