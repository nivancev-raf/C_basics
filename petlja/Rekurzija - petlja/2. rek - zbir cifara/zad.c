#include <stdio.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/02_zbir_cifara_rek

Ulaz
5523
Izlaz
15
*/

int zbir_cif_rek(int a){
    if (a == 0)
        return 0;
    else 
        return a % 10 + zbir_cif_rek(a / 10);
}

int main (){
    int n;
    scanf("%d", &n);
    printf("%d", zbir_cif_rek(n));

    return 0;
}