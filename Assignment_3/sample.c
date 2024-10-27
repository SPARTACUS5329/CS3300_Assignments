// MiniC program for complex expression
#include<stdio.h>

int zero()
{
   printf("This is a zero\n");
   return 0;
}

int one()
{
   printf("This is a one\n");
   return 1;
}

int main() {
   
   int a; int b; int c; int d; 
   int e; int f; int g; int h; 
   int i; int j; int k; int l;

   int result;
   a = 10; b = -3; c= -4; d=1;
   e = -10; f = -17; g = -80; h = (3*3)*(3*3); 
   i = -1/-1; j=3*5; k=7- -4; l=+1;


   result = (((a + (b * c)) - d) / ( (e - f) / (g + h))) + ((i * j) - (k / l));
   printf("Thala for a reason %d\n",result); 
   result = 1/2;
   printf("This should be zero = %d\n",result);

   result = (((zero())/(one()))  + (((one())+(zero()))*(one())));

   return 0;
}
