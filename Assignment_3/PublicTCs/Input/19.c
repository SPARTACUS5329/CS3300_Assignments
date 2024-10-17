// MiniC program for simple if-else logic
#include<stdio.h>

int main()
{
    int x; int arg1; int arg2; int arg3;
    x = 5;
    arg1 = 0; arg2 = 1; arg3 = 1;
    printf("%d\n",x);
    if(arg1 == 1){x = 6;}
    printf("%d\n",x);
    if(arg2 == 1){x = 7;}
    printf("%d\n",x);
    if(arg3 == 1){x = 8;}
    printf("%d\n",x);
    return 0;
}