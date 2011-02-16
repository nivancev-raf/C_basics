#include <stdio.h>
#include <string.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/01_izbaciPraznine

Izbaci praznine:
Napisati program kojim se unosi tekst. Ispisati taj tekst bez praznina.
Ulaz
abc def ghi
Izlaz
abcdefghi
*/

int main(){
    char s[200];
    gets(s);
    char s2[200];
    int n = strlen(s);
    int br = 0;
    for (int i = 0; i < n; i++){
        if (s[i] != ' ') s2[br++] = s[i];
    }
    s2[br] = '\0';
    printf("%s", s2);
    return 0;
}
