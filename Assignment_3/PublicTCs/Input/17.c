// MiniC program for Nested functions (ascii art)

#include<stdio.h>

int indent(int ind)
{
    while(ind > 0){printf(" "); ind = ind - 1;}
    return 0;
}

int pattern(int depth, int ind)
{
    if(depth == 9){ printf("-#=========|===============|>\n");}
    else
    {
        indent(11); printf("|"); indent(2*(ind));  if(depth == 6){printf(")\n");} else {printf("(\n");}
        if(depth >= 6){ pattern(depth + 1, ind-1); } else{ pattern(depth + 1, ind+1); }
        indent(11); printf("|"); indent(2*(ind));  if(depth == 6){printf(")\n");} else {printf("(\n");}
    }
    return 0;
}

int main() {
    pattern(1, 0);
    return 0;
}