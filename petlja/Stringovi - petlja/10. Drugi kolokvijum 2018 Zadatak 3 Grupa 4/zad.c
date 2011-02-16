#include <stdio.h>
#include <string.h>

/*
https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/11_drugiKolokvijum2018Zadatak3Grupa4

Ulaz
    // samo reci koje su se ponovile se stampaju 
prvi drugi prvi treci drugi
Izlaz
prvi drugi
*/

int main (){
    char s[] = "drugi treci prvi prvi treci drugi";
    char out[100];
    char* token = strtok(s, " ");
    while (token != NULL){
        //printf("%s\n", token);
        // ovaj uslov (!strstr(out, token)) sluzi da ne stampa ponovo ponovoljene tokene
        // ovaj uslov (strstr(token + strlen(token) + 1, token) ??  
        if (!strstr(out, token) && strstr(token + strlen(token) + 1, token)) {
        strcat(out, token);
        out[strlen(out)] = ' ';
        }
        token = strtok(NULL, " ");
    }
    puts(out);

    return 0;
}