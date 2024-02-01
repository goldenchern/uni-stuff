#include <stdio.h>
#include <string.h>

int strOverWrite(char *s1, char *s2, int pos);

int main()
{ 
   char s1[40], s2[40], *p;
   int pos, total;

   printf("Enter string 1: \n");
   fgets(s1, 80, stdin);
   if (p=strchr(s1,'\n')) *p = '\0'; 
   printf("Enter string 2: \n");
   fgets(s2, 80, stdin);
   if (p=strchr(s2,'\n')) *p = '\0'; 
   printf("Enter position: \n");
   scanf("%d", &pos);
   total = strOverWrite(s1, s2, pos);
   printf("strOverWrite(): %s %d\n", s1, total);
   return 0;
}

int strOverWrite(char *s1, char *s2, int pos)
{
    int replaced = 0;
    
    for (int i = pos, j = 0; i < strlen(s1) && j < strlen(s2); i++) {
        s1[i] = s2[j++];
        replaced++;
    }
    
    return replaced;
}