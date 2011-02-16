#include <stdio.h>
#include <math.h>

/*
2 (7p). Koristedi naredbu while i funkciju getchar() za čitanje karaktera
iz ulazne sekvence karaktera
koja se sastoji od slova i cifara izračunati zbir svih brojeva koji 
se nalaze između slova koji su najviše
do dva mesta udaljeni u ASCII tabeli.
primer: ab11cnh23zk37j1jht21m
rezultat: 49
(objašnjenje: brojevi koji se nalaze između slova sa razmakom do dva mesta 11, 37 i 1, u zbiru 49)
*/

int main () {

    char c, start = 0;
    int n = 0, sum = 0;
    while ((c = getchar()) != '\n'){
        if (c >= '0' && c <= '9'){
            n = n * 10 + c - '0'; 
            continue;
        } 
        
        if (!n){
            start = c;
            continue;
        }
       
        if (abs(start - c) <= 2){
            sum += n;
        }
        n = 0;
    }
    printf("%d", sum);

    return 0;

}