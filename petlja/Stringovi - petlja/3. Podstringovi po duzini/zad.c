#include <stdio.h>
#include <string.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/03_podstringovi_po_duzini

Podstringovi po dužini:
a
b
c
d
ab
bc
cd
abc
bcd
abcd
*/

int main (){
    char s[5] = "abcd";
    int n = strlen(s);
    // n = 4;
    for (int i = 1; i <= n; i++){
        for (int j = 0; i + j <= n; j++){
            for (int k = j; k < i + j; k++){
                putchar(s[k]);
            }
        printf("\n");
        }
    }
    return 0;
}
/*
            for (int k = j; k <= n; k++){
                putchar(s[k]);
            }
        printf("\n");
*/