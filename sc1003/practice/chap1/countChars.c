	/*edit*/

/*custom header*/
#include <ctype.h>

	/*end_edit*/
#include <stdio.h>
int main() 
{
	/*edit*/
   /* Write your code here */
   int letterCount = 0, numberCount = 0;
   char c;
   
   printf("Enter your characters (# to end):\n");
   
   while(1) {
        scanf("%c", &c);
        
        if (c == '#')
            break;
        else if (isalpha(c))
            letterCount++;
        else if (isdigit(c))
            numberCount++;
   }
   
   printf("The number of digits: %d\n", numberCount);
   printf("The number of letters: %d\n", letterCount);


	/*end_edit*/
   return 0;
}