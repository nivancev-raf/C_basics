#include <stdio.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/03_matrica_zvezdica

Ulaz
5 5
Izlaz
*****
*****
*****
*****
*****
*/

void matrica_zvezdica(int n, int m){
    if(n == 0)
        return;
    for(int i=0; i<m; i++)
        printf("*");
    printf("\n");
    matrica_zvezdica(n-1, m);
}
int main (){
    int n = 5, m = 5;
    matrica_zvezdica(n, m);


    return 0;
}