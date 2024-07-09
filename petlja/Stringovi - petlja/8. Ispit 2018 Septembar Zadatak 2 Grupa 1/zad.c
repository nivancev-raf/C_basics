#include <stdio.h>
#include <string.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/09_ispit2018SeptZadatak2Grupa1

Ulaz
abbcfffggtt
Izlaz
a-bb-c-fff-gg-tt-
*/

int main (){
    char s[128];
    gets(s);
    int n = strlen(s);
    //char s2[128];
    int i = 0;
    while (s[i] != '\0'){
        if (s[i] != s[i + 1]){ 
            putchar(s[i]);
            putchar('-');       
        }else{
            putchar(s[i]);
        }
        i++;
    }
    s[n] = '\0';
    return 0;
}