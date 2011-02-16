#include <stdio.h>
#include <string.h>

/*
(7 poena). Napisati program koji menja unetu rečenicu koja se čuva kao string tako što izbacuje
sve reči koje počinju i završavaju se malim slovom. Pretpostavlja se da se unose samo slova i znak
razmaka (space).
Primer: Recenice se Ne pisu ovakO
Rezultat: Recenice Ne ovakO
*/

int main (){
    char s[100] = "Recenice se Ne pisu ovakO";
    char out[100];
    char* token = strtok(s, " ");
    while (token != NULL){
        char *c = token;
            while (*c){
                if (*c >= 'A' && *c <= 'Z'){
                strcat(out, token);
                out[strlen(out)] = ' ';
                }
                c++;
            }
        token = strtok(NULL, " ");
    }
    puts(out);

    return 0;
}