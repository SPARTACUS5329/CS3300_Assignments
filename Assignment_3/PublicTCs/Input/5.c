// MiniC program for simple max function with if-else
#include<stdio.h>

int max(int a, int b) {
    int ret_val;
    if (a > b) {
        ret_val = a;
    } else {
        ret_val = b;
    }
    return ret_val;
}

int main() {
    int num1;
    int num2; 
    int maximum;
    num1 = 15;
    num2 = 25;
    maximum = max(num1, num2);
    printf("Maximum is %d\n", maximum);
    return 0;
}