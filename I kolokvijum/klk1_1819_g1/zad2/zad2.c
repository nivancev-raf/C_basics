#include <stdio.h>

/*
2 (7p). Koristeci naredbu while i funkciju getchar() za čitanje 
karaktera iz ulazne sekvence karaktera
koja se sastoji od slova i cifara,
izračunati zbir svih trocifrenih brojeva.
primer: ab123de5000f4g567hh rezultat: 690
(objašnjenje: brojevi koji su trocifreni su 123 i 567, u zbiru su 690)
*/
int numofDegits(int a){
    int numDec = 0;
    while (a){
        a /= 10;
        numDec++;
    }
    return numDec;
}

int main () {
    int n = 0, brojac = 0, sum = 0;
    char c;
    while ((c = getchar()) != '\n'){
        if (c >= '0' && c <= '9'){
            n = n * 10 + c - '0';
            brojac++;
            continue;
        }
        if (brojac == 3){
            sum += n;
            n = 0;
            brojac = 0;
        }else{
            brojac = 0;
            n = 0;
        }
    }
    printf("%d", sum);
    return 0;
}