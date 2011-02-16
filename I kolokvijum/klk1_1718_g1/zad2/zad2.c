#include <stdio.h>
#include <math.h>
/*
2(7p). Koristedi naredbu while i funkciju getchar() za čitanje
karaktera iz ulazne sekvence karaktera
koja se sastoji od slova i cifara izračunati zbir svih brojeva koji se
nalaze između istih slova, pri čemu
se odgovarajude malo i veliko slovo smatraju istim (a je jednako sa A).
primer: ab23Bnh46zu37uj1jht21m
rezultat: 61
(objašnjenje: brojevi koji se nalaze između istih slova su 23, 37 i 1, u zbiru 61)
*/


int main (){

    char c, prev = ' ', karakter1, karakter2;
    int n = 0, sum = 0;
    while ((c = getchar()) != '\n'){
        if (c >= '0' && c <= '9'){
            n = n * 10 + c - '0';
        }
        if (prev >= 'a' && prev <= 'z' && c >= '0' && c <= '9'){
            karakter1 = prev;
        }
        if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && prev >= '0' && prev <= '9'){
            karakter2 = c;
        }    
        if (prev >= 'a' && prev <= 'z' && c >= 'a' && c <= 'z'){
            n = 0;
        }
        else if (karakter2 == karakter1 || abs(karakter1 - karakter2) == 32){
            sum += n;
            n = 0;
            karakter1 = 0;
            karakter2 = 0;
        }
        
    prev = c;
    }
    printf("%d", sum);

    return 0;
}