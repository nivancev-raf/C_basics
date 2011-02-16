#include <stdio.h>
#include <stdlib.h>

// https://petlja.org/sr-Latn-RS/biblioteka/r/lekcije/uvod-u-programiranje/nedelja_11

typedef struct Element{
    int podatak;
    struct Element* sledeci;
}Element;


// u ovim funkcijama nam je uvek return vrednost glava

Element* dodajNaPocetak(Element *glava, int broj){
    Element *novi = (Element*)malloc(sizeof(Element));
    novi -> podatak = broj;
    novi -> sledeci = glava;
    glava = novi;
    return glava; 
}

Element* dodajNaKraj(Element *glava, int broj){
    Element *novi = (Element*)malloc(sizeof(Element));
    novi -> podatak = broj;
    novi -> sledeci = NULL;
    if (glava == NULL)  // ako je lista prazna
    {
        glava = novi;
    }else{
        Element *tekuci = glava;
        while (tekuci -> sledeci !=  NULL) // ovime ovde smo obezbedili poslednje mesto u listi
        {  
            tekuci = tekuci -> sledeci;
        }
        tekuci -> sledeci = novi;
    }
    return glava;
}

void ispisi_it(Element *glava){
    Element *tekuci = glava;
    while(tekuci != NULL){
        printf(" %d ->", tekuci->podatak);
        tekuci = tekuci->sledeci;
    }  
    printf(" NULL");
}

void ispisi_rek(Element *glava){
    // bazni slucaj:
    if (glava == NULL){
        printf(" NULL");
    }else{
        printf(" %d ->", glava->podatak);
        ispisi_rek(glava -> sledeci);
    }
}

Element *dodaj(Element *glava, int broj){
    Element *tekuci, *prethodni, *novi;
    tekuci = glava;
    prethodni = NULL; // moramo je staviti na null jer bi u suprotnom dobila neku random vrednost
    // i u slucaju da je lista prazna ili da je broj koji dodajemo manji od prvog elementa
    // tada ne ulazimo u while petlju i prethodni mora da bude NULL
    
    // trazimo mesto za novi element
    while (tekuci != NULL && tekuci->podatak < broj){
        prethodni = tekuci;
        tekuci = tekuci->sledeci;
    }

    // nakon petlje novi element treba ubaciti izmedju prethodnog i tekuceg.

    novi = (Element*)malloc(sizeof(Element));
    novi -> podatak = broj;
    // npr broj 18 hocemo da ubacimo izmedju 15 i 20
    // u ovom trenutku onom while petljom nam je tekuci = 20 a prethodni = 15;
    novi -> sledeci = tekuci; // sledeci element u odnosu na nas novi je tekuci odnosno 20
    if(prethodni == NULL) // u slucaju da nismo usli u while petlju
    {
        glava = novi;
    }else{
        prethodni -> sledeci = novi;
    }
    return glava;
}

Element* brisi(Element *glava, int broj){
    Element *tekuci, *prethodni;
    tekuci = glava;
    prethodni = NULL;
    // uslov != zapravo oznacava da proverama listu DO tog broja
    // dakle ako imamo  1 -> 2 -> 6 -> 7 -> NULL
    // i hocemo da izbacumo 6
    // on ce da vrt do 6 i uzece da mu je prethodni = 2, a tekuci = 6;
    while (tekuci != NULL && tekuci -> podatak != broj){
        prethodni = tekuci;
        tekuci = tekuci -> sledeci;
    }
    // tekuci je element koji izbacujemo
    if (tekuci != NULL){
        if (prethodni == NULL){
            // ako je prethodni == NULL znaci da izbacujemo prvi element
            glava = glava -> sledeci;
        }else{
            prethodni -> sledeci = tekuci -> sledeci;
            free(tekuci);
        }
    }else{
        printf("Broj %d nije pronadjen u listi\n", broj);
    }
    return glava;
}

Element* brisiSvaPojavljivanja(Element *glava, int broj){
    Element *tekuci, *prethodni;
    tekuci = glava;
    prethodni = NULL;
    while (tekuci != NULL){
        if (tekuci -> podatak == broj){
            if (prethodni == NULL){
                glava = glava -> sledeci;
                free(tekuci);
                tekuci = glava;
            }else{
                prethodni -> sledeci = tekuci -> sledeci;
                free(tekuci);
                tekuci = prethodni->sledeci;
            }
        }else{
            prethodni = tekuci;
            tekuci = tekuci -> sledeci;
        }
    }
    return glava;
}


// brisanje cele liste, pristupamo svakom elementu pojedinacno
void brisanjeListePok(Element **glavaPok){
    Element *tekuci;
    while (*glavaPok != NULL){
        tekuci = *glavaPok;
        *glavaPok = (*glavaPok) -> sledeci;
        free(tekuci);
    }
}


int brojPojavljivanjaIt(Element *glava, int broj){
    Element *tekuci;
    tekuci = glava;
    int bp = 0;
    while (tekuci != NULL){
        if(tekuci -> podatak == broj) bp++;
        tekuci = tekuci -> sledeci;
    }
    return bp;
}

int brojPojavljivanjaRek(Element *glava, int broj){
    if (glava == NULL){
        return 0;
    }else{
        if (glava -> podatak == broj)
            // 1+.... ubrajamo taj element
            return 1+brojPojavljivanjaRek(glava -> sledeci, broj);
        else
            return brojPojavljivanjaRek(glava -> sledeci, broj);            
    }
}

Element* dodajRek(Element *glava, int broj){
    Element *novi;
    if (glava == NULL || broj < glava -> podatak){
        novi = (Element*)malloc(sizeof(Element));
        novi -> podatak;
        novi -> sledeci = glava;
        return novi;
    }else{
        glava -> sledeci = dodajRek(glava -> sledeci, broj);
        return glava;
    }
}

Element* brisiNaIndexuIt(Element *glava, int index){
    Element *tekuci, *prethodni;
    tekuci = glava;
    prethodni = NULL;
    if (index == 0 && glava != NULL){
        // ako ovde udjemo to znaci da brisemo prvi element
        glava = tekuci -> sledeci;
        free(tekuci);
    }else{
        for (int i = 0; i < index; i++){
            prethodni = tekuci;
            tekuci = tekuci -> sledeci;
        }
        if (tekuci != NULL){
            prethodni -> sledeci = tekuci -> sledeci;
            free(tekuci);
        }
    }
    return glava;
}

Element* brisiNaIndexuRek(Element* glava, int index){
    if (index == 0 && glava != NULL){
        Element *tekuci;
        tekuci = glava;
        glava = glava -> sledeci;
        free(tekuci);
        return glava;
    }else{
        glava -> sledeci = brisiNaIndexuRek(glava -> sledeci, index - 1);
    }
    return glava;
}


int main (){
    Element *glava = NULL;
    glava = dodajNaPocetak(glava, 3);
    glava = dodajNaPocetak(glava, 1);
    glava = dodajNaPocetak(glava, 1);
    glava = dodajNaPocetak(glava, 1);
    glava = dodajNaKraj(glava, 7);
    glava = dodajNaPocetak(glava, 1);
    glava = dodaj(glava, 4);
    brisi(glava, 4);
    brisiSvaPojavljivanja(glava, 6);
    //brisanjeListePok(&glava); // prosledjujemo adresu pokazivaca na prvi element liste
    ispisi_it(glava);
    printf("\n");
    ispisi_rek(glava);
    printf("\n");
    printf("bp_it: %d\n", brojPojavljivanjaIt(glava, 1));
    printf("bp_rek: %d\n", brojPojavljivanjaRek(glava, 1));
    //dodajRek(glava, 2);
    //brisiNaIndexuIt(glava, 5);
    brisiNaIndexuRek(glava, 5);
    ispisi_rek(glava);
    
    return 0;
}

