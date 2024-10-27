// MiniC program for Nested function calls as functional arguments

#include<stdio.h>

int print(int x, int y)
{
    return x+y;
}
int main() 
{
    int x;
    x = print
    (   print
        (   print
            (   print(3,9),
                print(4,-9)
            ),
            print
            (   print
                (   print(0,67),
                    print(7,8)
                ),
                print
                (   print(3,9),
                    print(4,-9)
                )
            )
        ),
        print
        (   print(-1,-3), 
            print(2,5)
        )
    );
    printf("Value of x = %d\n",x);
    return 0;
}