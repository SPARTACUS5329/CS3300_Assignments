// MiniC program for Nested function calls as functional arguments

#include<stdio.h>

int print(int x, int y)
{
    printf("%d\n",x);
    return x+y;
}
int main() 
{
    print
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
    return 0;
}