#include <stdio.h>
#include <string.h>
#include <ctype.h>

int longWordLength(char *s);

int main() 
{
   char str[80], *p;
   
   printf("Enter a string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';   
   printf("longWordLength(): %d\n", longWordLength(str));    
   return 0;
}

int longWordLength(char *s)
{
    int longestLength = 0, currentLength = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) {
            currentLength++;
        } else {
            if (currentLength > longestLength) 
                longestLength = currentLength;
            currentLength = 0;
        }
    }
    
    return longestLength ? longestLength : currentLength;
}