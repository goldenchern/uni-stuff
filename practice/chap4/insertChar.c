#include <stdio.h>
#include <string.h>

void insertChar(char *str1, char *str2, char ch);

int main() 
{
   char a[80],b[80];
   char ch, *p;
   
   printf("Enter a string: \n");  
   fgets(a, 80, stdin);
   if (p=strchr(a,'\n')) *p = '\0'; 
   printf("Enter a character to be inserted: \n");  
   ch = getchar();
   insertChar(a,b,ch);
   printf("insertChar(): ");  
   puts(b);     
   return 0;
}

void insertChar(char *str1, char *str2, char ch)
{
    int ptr;
    char temp;
    
    for (int i = 0, ptr = 0; i <= strlen(str1); i++, ptr++) {
        if (i % 3 == 0 && i != 0) {
            str2[ptr++] = ch;
        }
        str2[ptr] = str1[i];
    }
}