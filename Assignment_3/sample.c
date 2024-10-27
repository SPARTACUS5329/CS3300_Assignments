// MiniC program for ascii art (complex short-circuting and char array manipulation)

#include<stdio.h>

char ascii[58];

int print(char ascii_arg[])
{
    printf(ascii_arg, "%s");
    return 0;
}

int main() 
{
    print(ascii);

    return 0;
}
