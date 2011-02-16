#include <stdio.h>
#include <string.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/06_brojPojavljivanja

Broj pojavljivanja:
Ulaz
abcdabcbfabxx
abc
Izlaz
2
*/

int main (){
    char s[] = "abcdabcbfabxx";
    char t[] = "abc";
    int n = strlen(s), res = 0;
    for (int i = 0; i < n; i++){
        if (strstr(s + i, t) == s + i) res++;
    }
    printf("%d", res);
    return 0;

}
