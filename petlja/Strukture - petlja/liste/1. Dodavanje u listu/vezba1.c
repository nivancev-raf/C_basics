#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    int podatak;
    struct Element *sledeci;
}Element;

// dodajNaPocetak

Element* dodajNaPocetak(Element *glava, int broj){
    Element *novi = (Element*)malloc(sizeof(Element));
    novi -> podatak = broj;
    novi -> sledeci = glava;
    glava = novi;
    return glava;
}

Element* dodajNaKraj(Element *glava, int broj){
    Element *novi = (Element*)malloc(sizeof(Element));
    // ako je lista prazna
    novi -> podatak = broj;
    novi -> sledeci = NULL;
    if (glava == NULL){
        glava = novi;
    }else{
        Element *tekuci = glava;
        while (tekuci -> sledeci != NULL){
            tekuci = tekuci -> sledeci;
        }
    tekuci -> sledeci = novi;
    }
    return glava; 
}



// novi = (Element*)malloc(sizeof(Element)); 
Element* dodaj(Element* glava, int broj){
    // dodajemo element npr. 15 izmedju 12 i 18
    Element* tekuci, *prethodni, *novi;
    prethodni = NULL;
    tekuci = glava;
    // trazimo mesto izmedju prethodnog i tekuceg
    while (tekuci != NULL && tekuci -> podatak < broj){
        prethodni = tekuci;
        tekuci = tekuci -> sledeci;
    }
    
    novi = (Element*)malloc(sizeof(Element));
    novi -> podatak = broj;
    novi -> sledeci = tekuci;
    if (prethodni == NULL){
        glava = novi;
    }else{
        prethodni -> sledeci = novi;
    }
    return glava;
}



void ispisi(Element *glava){
    Element* tekuci;
    tekuci = glava;
    while(tekuci != NULL){
        printf(" %d ->", tekuci->podatak);
        tekuci = tekuci -> sledeci;
    }
    printf(" NULL");
}


int main (){
    Element *glava = NULL;
    glava = dodajNaPocetak(glava, 6);
    glava = dodajNaPocetak(glava, 2);
    glava = dodajNaKraj(glava, 7);
    glava = dodajNaPocetak(glava, 1);
    glava = dodaj(glava, 4);
    ispisi(glava);
  

    return 0;
}