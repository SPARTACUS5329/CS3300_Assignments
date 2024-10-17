// MiniC program for testing scoping
#include<stdio.h>

int b(int arg)
{
    arg = arg*arg;
    printf("Value at b is %d\n",arg);
    return 0;
}

int a(int arg, int nest)
{
    int ret;
    printf("Current Nesting: %d\n",nest);
    if(arg >= (1024*1024))
    {
    }
    else
    {
        printf("Arg before is %d\n",arg);
        b(arg);
        arg = arg*1024;
        printf("Arg after is %d\n",arg);
        a(arg,nest+1);
        printf("Back to Nesting: %d\n",nest);
    }
    
    return 0;
}

int main()
{
    a(100,1);
    return 0; 
}
