// MiniC program for ascii art (complex short-circuting and char array manipulation)

#include<stdio.h>

char ascii[58];

int dead()
{
    printf("This shouldn't print, if it does, you are cooked!!\n");
    return -1;
}

int breaks(char ascii[])
{
    printf("This should print first\n");
    ascii[19] = '\n'; ascii[40] = '\n';
    ascii[56] = '\n';
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

int head(char ascii[])
{
    printf("This should print last\n");
    ascii[1] = '/';  ascii[2] = '\\'; ascii[3] = '_'; ascii[4] = '_';
    ascii[7] = '/';  ascii[8] = '\\'; ascii[5] = '_'; ascii[6] = '_';
    return 0;
}

int paws(char ascii[])
{
    printf("This should print second\n");
    ascii[42] = '('; ascii[46] = '(';
    ascii[44] = ')'; ascii[48] = ')'; 
    ascii[43] = '"'; ascii[47] = '"'; 
    ascii[49] = '_'; ascii[50] = '/'; 
    return 0;
}

int print(char ascii[])
{
    printf("%s",ascii);
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