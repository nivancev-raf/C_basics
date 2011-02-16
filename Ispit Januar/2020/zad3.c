#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
a) (7p) učitavanje podataka, unosi se naziv fajla koji sadrži opisane podatke i učitava se u listu
uređenu od najmanjeg ka najvecem po godini i mesecu,
b) (8p) ispis broja meseci u kome je rođeno više od određenog broja dece, unosi se broj i treba
ispisati koliko ima meseci u kojima je ukupan broj rođenih vedi od unetog broja, ovu funkcionalnost
je potrebno implementirati na dva načina, iterativno i rekurzivno,
c) (10p) ispis broja rođenih dečaka i devojčica u jednoj godini sortirano po ukupnom broju rođenih,
posmatra se broj rođenih u jednoj godini i ispisuje se broj rođenih dečaka, broj rođenih devojčica i
godina sortirano po ukupnom broju rođenih u godini (dozvoljeno je praviti nove strukture podataka).
Primer: 2 2018 120 150
*/


typedef struct Element{
    int mesec, godina, brDec, brDev;
    struct Element* sledeci;
}Element;

void meni(){
    printf("1. Ucitavanje podataka:\n");
    printf("2. Ispis broja meseci u kome je rođeno više od određenog broja dece\n");
    printf("3. Ispis broja rođenih dečaka i devojčica u jednoj godini sortirano po ukupnom broju rođenih\n");
    printf("4. Izlaz\n");
}

Element *napraviEl(int mesec, int godina, int brDec, int brDev){
    Element *novi = (Element*)malloc(sizeof(Element));
    novi -> mesec = mesec;
    novi -> godina = godina;
    novi -> brDec = brDec;
    novi -> brDev = brDev;
    novi -> sledeci = NULL;
    return novi;
}

Element *ubaciSortirano(Element *glava, Element *novi){
    if (glava == NULL){
        return novi;
    }
    // ovde se ubacuje element ispred glave
    if (glava -> godina < novi -> godina || 
    (glava -> godina == novi -> godina && glava -> mesec <= novi -> mesec)){
        novi->sledeci = glava;
        return novi;
    }else{
        Element *tekuci = glava;
        while (tekuci->sledeci && (tekuci->sledeci->godina > novi -> godina ||
        (tekuci->sledeci->godina == novi -> godina && tekuci->sledeci->mesec > novi -> mesec))){
            tekuci = tekuci -> sledeci;
        }
        if (!tekuci->sledeci){
            tekuci->sledeci = novi;
        }else{
            novi->sledeci = tekuci->sledeci;
            tekuci->sledeci = novi;
        }
    }
    return glava;
}

void ispisi(Element *glava){
    Element *temp = glava;
    while (temp){
        printf("%d %d %d %d\n", temp->mesec, temp->godina, temp->brDec, temp->brDev);
        temp = temp -> sledeci;
    }   
}

Element* ucitavanje(Element *glava, char* fajl){
    FILE *f;
    f = fopen("C:\\projects\\Ispit Januar\\2020\\grupa2.txt", "r");
    if (f == NULL){
        printf("fajl nije otvoren!\n");
        return NULL;
    }
    int mesec, godina, brDec, brDev;
    while (fscanf(f, "%d%d%d%d", &mesec, &godina, &brDec, &brDev) == 4){
        Element *n = napraviEl(mesec, godina, brDec, brDev);
        glava = ubaciSortirano(glava, n);
        
    }
    fclose(f);
    ispisi(glava);
    return glava;
}


int main (){
    Element *glava = NULL;
    int opcija;
    char fajl[20];
    printf("Unesi naziv fajla:\n");
    scanf("%s", fajl);
    ucitavanje(glava, fajl);
    




    return 0;
}