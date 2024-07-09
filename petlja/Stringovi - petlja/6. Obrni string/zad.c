#include <stdio.h>
#include <string.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/07_obrniString

Obrni string:
Ulaz
abcd
Izlaz
dcba
*/

int somi123(int a){
    return 10;
}

void somi321(int a){
    a = 10;
}

int main (){
    /*
    char s[200];
    gets(s);
    int n = strlen(s);
    for (int i = n - 1; i >= 0; i--){
        putchar(s[i]);
    }
    */
    int a = 15;
    printf("%d", somi123(a)); 

    return 0;
}