// MiniC program for ascii art (complex short-circuting and char array manipulation)

#include<stdio.h>

char ascii[58];

int dead()
{
    printf("This shouldn't print, if it does, you are cooked!!\n");
    return -1;
}

int breaks(char ascii_arg[])
{
    printf("This should print first\n");
    ascii_arg[19] = '\n'; ascii_arg[40] = '\n';
    ascii_arg[56] = '\n';
    return 0;
}

int face()
{
    printf("This should print third\n");
    ascii[21] = '='; ascii[27] = '='; 
    ascii[24] = '.'; 
    ascii[20] = '('; ascii[22] = '^'; 
    ascii[26] = '^'; ascii[28] = ')'; 
    return 0;
}

int bubbleout()
{
    int i;
    i = 18;
    printf("This should print fourth\n");
    while(i>=13){ascii[i]='_';i=i-1;}
    ascii[54] = ')'; ascii[55] = '/'; 
    return 0;
}

int bubbletext()
{
    printf("This should print fifth\n");
    ascii[37] = '!'; ascii[34] = 'e';
    ascii[36] = 'w'; ascii[33] = 'm';
    ascii[35] = 'o'; ascii[39] = ')'; 
    ascii[32] = '('; ascii[38] = '_'; 
    return 0;
}

int head(char ascii_arg[])
{
    printf("This should print last\n");
    ascii_arg[1] = '/';  ascii_arg[2] = '\\'; ascii_arg[3] = '_'; ascii_arg[4] = '_';
    ascii_arg[7] = '/';  ascii_arg[8] = '\\'; ascii_arg[5] = '_'; ascii_arg[6] = '_';
    return 0;
}

int paws(char ascii_arg[])
{
    printf("This should print second\n");
    ascii_arg[42] = '('; ascii_arg[46] = '(';
    ascii_arg[44] = ')'; ascii_arg[48] = ')'; 
    ascii_arg[43] = '"'; ascii_arg[47] = '"'; 
    ascii_arg[49] = '_'; ascii_arg[50] = '/'; 
    return 0;
}

int print(char ascii_arg[])
{
    printf("%s",ascii_arg);
    return 0;
}

int main() 
{
    int len;
    len = 56;
    ascii[57] = '\0';
    while(len >= 0)
    {
       ascii[len] = ' ';
       len = len - 1;

    }

    if( breaks(ascii) > 0 && dead() == 0 || paws(ascii) != face() && dead() == 0 || bubbleout() == bubbletext() && head(ascii) == 0 || dead() == 0)
    {print(ascii);}

    return 0;
}