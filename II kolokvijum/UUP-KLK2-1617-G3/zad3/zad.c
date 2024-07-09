#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
// ispisuje poslednju crticu i nije menjan string
Napisati program koji menja uneti string koji sadrži cifre i znak '-', tako što cifre između
znaka - šiftuje za jedno mesto u desno.

Primer: 345-135-3217
Rezultat: 534-513-7321
*/


int broj(int n){
    int cifra = n % 10;
    int novi_br = 0;
    int copy = n;
    int nod;
    while (copy){
        copy /= 10;
        nod++;
    }
    novi_br = cifra * pow(10, nod - 1);
    n /= 10;
    novi_br += n;
    return novi_br;
}

int main (){
  
    char s[] = "345-135-3217";
    int array[10];
    int j = 0;
    int cifra, n, p;
    p = strlen(s);
    char *token;
    token = strtok(s, "-");
    while (token != NULL){
        char *c = token;
        n = atoi(c);
        array[j++] = broj(n);
        token = strtok(NULL, "-");
    }
    for (int i = 0; i < j; i++){
        printf("%d", array[i]);
        if (i != j - 1) putchar('-');
    }
    
    return 0;
}