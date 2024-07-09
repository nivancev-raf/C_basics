#include <stdio.h>
#include <string.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/08_izStringaUBroj

Iz stringa u broj:
Ulaz
RAFraf
Izlaz
082065070114097102
R -> 082
*/

int main (){
    char s[] = "RAFraf";
    char c;
    int n = strlen(s);
    for (int i = 0; i < n; i++){
        c = s[i];  
        printf("%.3d", c);
    }
   
    return 0;
}