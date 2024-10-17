// MiniC program to test the major constructs

#include<stdio.h>
int glob_1;
int glob_2;
char yes_no[6];

int zero()
{
   printf("This is a zero\n");
   return 0;
}

int one()
{
   printf("This is a one\n");
   return 0;
}

int add(int x, int y, int z, int a, int b)
{
    return ((x+y)+((z+a)+b));
}

int print_yes()
{
    int i;
    char dummy[1];
    i=0;
    while(i<6)
    {
        dummy[0] = yes_no[i];
        printf("%s",dummy);
        i = i +2;
    }
    printf("\n");
    return zero();
}

int print_no()
{
    int i;
    char dummy[1];
    i=1;
    while(i<6)
    {
        dummy[0] = yes_no[i];
        printf("%s",dummy);
        i = i +2;
    }
    printf("\n");
    return ((zero())+1);
}

int fibonacci(int n)
{
    int ret;
    if(n <= 2){ ret = n-1;}
    else{ ret = (fibonacci(n-1)) + (fibonacci(n-2));}
    return ret;
}

int mess_around(int a, char b[], int c, int d, char e[])
{
    int f; int g; int h;
    f = (a+c)*d;
    g = ((f-d)/a)*(a+c);
    printf("g = %d\n",g);
    return (((f+g)));
}

int main()
{
    int i;
    int dum;
    int flag;
    flag = 1;
    i=10;
    yes_no[0] = 'Y'; yes_no[1] = 'N'; yes_no[2] = 'E';
    yes_no[3] = 'O'; yes_no[4] = 'S'; yes_no[5] = '\0';
    printf("%d\n",fibonacci(10));
    mess_around(10,yes_no,10,2,yes_no);


    while((i>0) && flag==1)
    {
        dum = i/2;
        if( (dum*2 == i) || (!(zero()==0) || (!(print_no() == zero()) && !(print_yes() == zero()))))
        {
            printf("Yes\n");
        }
        else
        {
            if(1>=2 || 2<=1 || 1==2 || 1>2 || 1!=1 || 1<2)
            {
                printf("No\n");
            }
        }
        i = i -1;
    }

    dum = (((zero()) + (one())) + (((one())+(zero()))+(one())));
    printf("Value = %d\n",dum);
    dum = add((one()),(zero()),(one()),(zero()),(zero()));
    printf("Value = %d\n",dum);


    return 0;
}