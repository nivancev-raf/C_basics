#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
Primer: 345-1354-321
Rezultat: 453-3541-213
*/

int promena_broja(int a){
    int copy = a, cifra, p = 10;
    int copy2 = a;
    int nod = 0, n;
    while (copy){
        copy /= 10;
        nod++;
    }
    n = a / pow(10, nod - 1);
    while(copy2 > 10){
        cifra = copy2 % 10;
        copy2 /= 10;
        n += cifra*p;
        p*=10;
    }
    return n;
}

int main (){
    int n;
    char s[] = "345-1354-321";
    char s2[100];
    char s3[100];
    int array[100];
    int j = 0;
    char *token;
    token = strtok(s, "-");
        while (token != NULL){
            char *c = token;
            n = atoi(c);
            array[j++] = promena_broja(n);
            token = strtok(NULL, "-");
        }
        for (int i = 0; i < j; i++){
            printf("%d", array[i]);
            if (i != j - 1) putchar('-');
        }
    return 0;
}