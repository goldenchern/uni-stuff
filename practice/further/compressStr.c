#include <stdio.h>
#include <string.h>
#include <ctype.h>

void compressStr(char *str);

int main() 
{
   char str[40]; 
         
   printf("Enter a sequence of characters: \n"); 
   scanf("%s", str);
   printf("compressStr(): ");
   compressStr(str);
   return 0;
}

void compressStr(char *str)
{
    int streak = 1;
    
    for (int i = 1; i <= strlen(str); i++) {
        if (str[i] != str[i - 1]) {
            if (streak == 1) {
                printf("%c", str[i - 1]);
            } else {
                printf("[%d%c]", streak, str[i - 1]);
                streak = 1;
            }
            continue;
        }
        streak++;
    }
}