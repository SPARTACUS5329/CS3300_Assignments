// MiniC program for complex boolean expressions
#include<stdio.h>

int main() {
    int a;
    a = 7;
    int b;
    b = 9;

    if (a > 5 && b < 10) {
        a = b;
    }
    return a == b; //all conditionals return either 1 or 0 integers
}
