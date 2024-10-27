// MiniC program for printing pascal triangle

#include<stdio.h>

int printPascal(int n)
{
    int line; int space;
    int coef; int i;

    line = 1;
    while(line <= n)
    {
        space = 1;
        while(space <= n - line)
        {
            printf("  ");
            space = space + 1;
        }
        coef = 1;
        i = 1;
        while(i <= line)
        {
            if(coef < 10){ printf("   %d", coef); }
            else{ printf("  %d", coef); }
           
            coef = (coef * (line - i) )/ i;
            i = i+1;
        }
        printf("\n");
        line = line + 1;
    }
    return 0;
} 

int main()
{
    printPascal(6);
    return 0;
}
