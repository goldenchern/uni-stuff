#include <stdio.h>
#include <string.h>

void maxCharToFront(char *str);

int main() 
{
   char str[80], *p;
   
   printf("Enter a string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0'; 
   printf("maxCharToFront(): ");  
   maxCharToFront(str); 
   puts(str);
   return 0;
}

void maxCharToFront(char *str) 
{
    char max = str[0];
    int index = 0, length = strlen(str);
    
    for (int i = 1; i < length; i++) {
        if (str[i] > max) {
            max = str[i];
            index = i;
        }   
            
    }
    
    char prev, temp;
    
    for (int i = 0; i <= index; i++) {
        if (i == 0) {
            prev = max;
        } 
        temp = str[i];
        str[i] = prev;
        prev = temp;
    }
}