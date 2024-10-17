// MiniC program for complex boolean expressions
#include<stdio.h>

int dead()
{
    printf("This shouldn't print, if it does, you are cooked!!\n");
    return -1;
}

int main()
{
    if( !(((-1 == -1) || (dead() == 1)) && ((-1 == -1*-1) && (1/0 == 1)) && (dead() == 1)) )
    {
        printf("Hello\n");
    }
    return 0;
}