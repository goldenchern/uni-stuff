	/*edit*/

/*custom header*/


	/*end_edit*/
#include <stdio.h>
#include <math.h>
int main() 
{
	/*edit*/
   /* Write your code here */
   int a1, b1, c1, a2, b2, c2;
   float denominator, x, y;
   
    printf("Enter a1,b1,c1,a2,b2,c2:\n");
    scanf("%d %d %d %d %d %d\n", &a1, &b1, &c1, &a2, &b2, &c2);
    
    denominator = a1 * b2 - a2 * b1;
    
    if (denominator == 0)
        printf("Denominator is zero!\n");
    else {
        x = (b2 * c1 - b1 * c2) / denominator;
        y = (a1 * c2 - a2 * c1) / denominator;
        
        printf("x=%.2f,y=%.2f", x, y);
    }
        
	/*end_edit*/
   return 0;
}