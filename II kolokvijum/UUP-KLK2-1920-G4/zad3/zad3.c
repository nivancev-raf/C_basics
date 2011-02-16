#include <stdio.h>
#include <string.h>

/*
(7p) Napisati program koji učitava string sastavljen od malih i velikih slova abacede.
Program treba da pronađe i ispiše najduži podstring koji počinje i završava se istim
slovom nezavisno od veličine slova. Ispisati podstring i dužinu, ako ima više podstringova
sa istom najvećom dužinom ispisati sve.
Primer: amjZdghAshZfgh
Rezultat: duzina 8
podstringovi: amjZdghA ZdghAshZ ghAshZfg hAshZfgh
*/

int main (){
    char s[] = "amjZdghAshZfgh";
    char s2[100];
    strcpy(s2, s);
    int duzina = 0;
    char array[100];
    strupr(s);
    int n = strlen(s);
    for (int i = 0; i < n; i++){
        array[i] = s[i];
    }
    int max_duzina = 1;
    for (int i = 0; i < n; i++){
        duzina = 0;
        for (int j = i + 1; j < n - 1; j++){
            if (array[i] == array[j]){
                duzina = j - i + 1;
                for (int k = i; k <= j; k++){
                    printf("%c", s2[k]);                    
                    }
                    printf(" ");
                }
            if (duzina >= max_duzina){
                max_duzina = duzina;
                }
        }
    }
    printf("\n");
    printf("%d", max_duzina);
    return 0;
}