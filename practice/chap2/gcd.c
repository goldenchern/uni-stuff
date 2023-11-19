#include <stdio.h>

int gcd1(int num1, int num2);
void gcd2(int num1, int num2, int *result);

int main()
{
   int x,y,result;		
   printf("Enter 2 numbers: \n");
   scanf("%d %d", &x, &y);
   printf("gcd1(): %d\n", gcd1(x, y)); 
   gcd2(x,y,&result);
   printf("gcd2(): %d\n", result);      
   return 0;
}

int gcd1(int num1, int num2) 
{
   int rem;

   while (1) {
      rem = num1%num2;

      if (rem == 0) 
         break;
      else {
         num1 = num2;	
         num2 = rem;
      }
   }
   return num2;		
}

void gcd2(int num1, int num2, int *result) 
{
   int rem;

   while (1) {
      rem = num1 % num2;

      if (rem == 0) 
         break;
      else {
         num1 = num2;	
         num2 = rem;
      }
   }
   *result = num2;		
}