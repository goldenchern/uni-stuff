#include <stdio.h>

int main() 
{                 
    int year;
    char *horoscope;
    
    while (1) {
        printf("Enter your birth year:\n");
        scanf("%d", &year);
        
        if (year == -1) break;
        
        year %= 12;
        
        switch (year) {
            case 0:
                horoscope = "Monkey";
                break;
            case 1:
                horoscope = "Rooster";
                break;
            case 2:
                horoscope = "Dog";
                break;
            case 3:
                horoscope = "Pig";
                break;
            case 4:
                horoscope = "Rat";
                break;
            case 5:
                horoscope = "Cow";
                break;
            case 6:
                horoscope = "Tiger";
                break;
            case 7:
                horoscope = "Rabbit";
                break;
            case 8:
                horoscope = "Dragon";
                break;
            case 9:
                horoscope = "Snake";
                break;
            case 10:
                horoscope = "Horse";
                break;
            case 11:
                horoscope = "Goat";
        }
        printf("chineseHoroscope: %s\n", horoscope);
    }

   return 0;
}