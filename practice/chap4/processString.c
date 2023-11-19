#include <stdio.h>
#include <string.h>
#include <ctype.h>

void processString(char *str, int *totVowels, int *totDigits);

int main()
{
   char str[50], *p;
   int totVowels, totDigits;

   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0'; 
   processString(str, &totVowels, &totDigits);   
   printf("Total vowels = %d\n", totVowels);
   printf("Total digits = %d\n", totDigits);
   return 0;
}

void processString(char *str, int *totVowels, int *totDigits)
{
    char temp;
    *totVowels = *totDigits = 0;
    
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i]))
            (*totDigits)++;
        else {
            temp = toupper(str[i]);
            if (temp == 'A' || temp == 'E' || temp == 'I' || temp == 'O' || temp == 'U')
                (*totVowels)++;
        }
    } 
}