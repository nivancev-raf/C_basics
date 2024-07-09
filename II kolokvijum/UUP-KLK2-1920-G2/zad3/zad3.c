#include <stdio.h>
#include <string.h>

/*
Napisati program koji proverava da li je uneta linija teksta palindrom. Palindrom je
tekst koji se isto čita sa leva na desno i sa desna na levo. Pri proveri se ignorišu
razmaci, i parovi slova “nj” i “lj” se tretiraju kao jedno slovo. 
Pretpostavlja se da se unose samo mala slova i znak razmaka.

Primer: i jogurt ujutru goji
Rezultat: jeste palindrom

Primer: neki tekst
Rezultat: nije palindrom

Primer: idu ljudi
Rezultat: jeste palindrom
*/
int main (){
    char s[] = "idu ljudi";
    char s3[100] = {0};
    //strcpy(s3, s);
    int j = 0, j2 = 0;
    int n = strlen(s);
    char s2[100] = {0};
    for (int i = n - 1; i >= 0; i--){
        if (s[i] == ' ') continue;
        s2[j2++] = s[i];
    }
    char* token;
    token = strtok(s, " ");
    while (token != NULL){
        strcat(s3, token);
        token = strtok(NULL, " ");
    }
    int p = strlen(s2);
    char tmp;
    for (int i = 0; i < p; i++){
        if (s2[i] == 'j' && s2[i+1] == 'l'){
            tmp = s2[i];
            s2[i] = s[i + 1];
            s2[i + 1] = tmp;
        }
    }
    puts(s2);
    printf("\n");
    puts(s3);
    if (strcmp(s3, s2) == 0) printf("Rezultat: jeste palindrom\n");
    else printf("Rezultat: nije palindrom\n");
    return 0;
}