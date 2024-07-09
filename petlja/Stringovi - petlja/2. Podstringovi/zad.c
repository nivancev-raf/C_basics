#include <stdio.h>
#include <string.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/02_podstringovi

Podstringovi:
Ulaz
abcd
Izlaz
a
ab
abc
abcd
b
bc
bcd
c
cd
d
*/

int main (){
    char s[4] = {'a', 'b', 'c', 'd'};
    int n = strlen(s);
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            for (int k = i; k <= j; k++){
                putchar(s[k]);
            }
        printf("\n");
        }
    }

    return 0;
}