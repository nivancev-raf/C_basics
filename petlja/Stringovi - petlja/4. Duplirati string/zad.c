#include <stdio.h>
#include <string.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/05_duplirajString

Duplirati string:
Ulaz
abcd
Izlaz
aabbccdd
*/

int main (){
    char s[200] = "abcd";
    char s2[200];
    int n = strlen(s);
    for (int i = 0; i < n; i++){
        s2[i*2] = s[i];
        s2[2*i + 1] = s[i];
    }
    s2[2*n] = '\0';
    printf("%s", s2);
    return 0;
}