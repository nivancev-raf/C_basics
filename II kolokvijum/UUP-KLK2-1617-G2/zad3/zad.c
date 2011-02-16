#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
3. (7 poena) Napisati program koji menja unetu rečenice koja se čuva kao
string tako što izbacuje sve reči koje imaju manje od n karaktera, broj n unosi korisnik.
Pretpostavlja se da se unose samo slova i znak razmaka (space). Primer za n=5.
Primer: Recenica koja ima nekoliko reci
Rezultat: Recenica nekoliko
*/

int main (){
    int n = 5;
    int brojac = 0;
    char s[] = "Recenica koja ima nekoliko reci";
    char out[100];
    char* token = strtok(s, " ");
    while (token != NULL){
        char* c = token;
            while(*c){   
                brojac++;
                c++;
            }
            if(brojac > n){
                strcat(out, token);
                out[strlen(out)] = ' ';
                
            } 
            brojac = 0;
        token = strtok(NULL, " ");
    }
    puts(out);
    return 0;
}

