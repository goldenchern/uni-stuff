#include <stdio.h>
#include <string.h>

char *sweepSpace(char *str);


int main()
{
     char str[80], *p;
    
     printf("Enter the string: \n");
     fgets(str, 80, stdin);
     if (p=strchr(str,'\n')) *p = '\0';
     
     printf("sweepSpace(): %s\n", sweepSpace(str));
     return 0;
}


char *sweepSpace(char *str)
{
    int h, k = 0;
    
    for (h = 0; h <= strlen(str); h++, k++) {
        if (str[h] == ' ')
            str[k] = str[++h];
        else
            str[k] = str[h];
    }
    
    return str;
} 