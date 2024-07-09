#include <stdio.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/01_stepen_rekurzivno

Ulaz
2 8
Izlaz
256
*/

int pow_rek(int a, int b){
    if (b == 1 || b == 0)
        return a;
    else 
        return a * pow_rek(a, b - 1);
}   

int main () {

    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", pow_rek(n, m));


    return 0;
}