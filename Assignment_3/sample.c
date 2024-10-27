// MiniC program for nested if-else and loops
#include<stdio.h>
int main()
{
   int x;
   if(1>0)
   {
        if(2<0){printf("No printing\n");}
        else{
            if(3>0)
            {
                if(0==0)
                {
                    x = 3; 
                    while(x*x <= 6561)
                    {
                        printf("I love 3s\n");
                        x = x*x;
                    }
                }
            }
        }
   }
   return 0;
}
