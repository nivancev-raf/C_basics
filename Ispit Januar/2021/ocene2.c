#include <stdio.h>
#include <stdlib.h>
#define MAX 100
char buffer[MAX];
/*

*/

typedef struct Element{
    int redni_br;
    char predmet[3];
    int ocena;
    char datum[10];
    struct Element *sledeci;
}Element;

void meni(){
    printf("1. Ucitavanje podataka:\n");
    printf("2. ");
}

Element *ucitavanje(){
    Element *glava = NULL;

    FILE *f;
    f = fopen("C:\\projects\\Ispit Januar\\2021\\ocene2.txt", "r");
    if (f == NULL){
        printf("Fajl nije uspesno otvoren!\n");
        return NULL;
    }
    while(fgets(buffer, MAX, f)){
        
    }
    



    fclose(f);
}


int main (){
    Element *glava = NULL;
    int opcija;
    


    return 0;
}