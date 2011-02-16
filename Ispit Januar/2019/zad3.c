#include <stdio.h>
#include <stdlib.h>

/*
oblik:  dan mesec godina broj_beba
primer: 23 2 2018 12 (23. februara 2018. rođeno je 12 beba).
lista je sortirana od najveceg ka najmanjem po broju rođenih beba

1. Napravi strukturu na osnovu oblika datog u zad
2. Napravi void meni (pravi se na osnovu uslova zadatka: a), b), c)...)
3. Funkcija koja pravi novi element liste (napraviEl)
4. Funkcija koja ubacuje novi element na određeno mesto tako da lista ostane sortirana. (ubaciUListu)
5. Funkcija koja pravi listu sa podacima koje učitavamo iz fajla. (ucitavanje)
6. ispis broja rodjenih beba u godini - it i rek
7. Funkcija koja pravi novu listu tako da bude sortirana po mesecima i godinama

*/

typedef struct Dan {
    int dan;
    int mesec;
    int godina; 
    int br_beba;
    struct Dan* sledeci;
}Dan;

void meni() {
    printf("Meni:\n");
    printf("1. Ucitavanje podataka\n");
    printf("2. Ispis broja rodjenih beba u jednoj godini\n");
    printf("3. Ispis broja rodjenih beba po mesecima\n");
    printf("4. Izlaz\n");
}

Dan* napraviElement(int dan, int mesec, int godina, int br_beba){
    Dan *b = (Dan*)calloc(1, sizeof(Dan));
    b -> dan = dan;
    b -> mesec = mesec;
    b -> godina = godina;
    b -> br_beba = br_beba;
    return b;
}

Dan* ubaciUListu(Dan *glava, Dan *novi){
    if (glava == NULL){
        // ako je lista prazna ubacujemo samo novi element
        glava = novi;
        return novi;
    }else{
        // ako lista nije prazna, novi element ubacujemo na pocetak liste ukoliko
        // je br_beba veci od br_beba sa pocetka liste
        if (novi -> br_beba > glava -> br_beba){
            novi -> sledeci = glava; // moramo da povezemo pokazivace
            glava = novi;
        }else{
            // ako ne dodajemo na početak, onda mu tražimo mesto dalje u listi
            Dan *tekuci = glava;
            while (tekuci -> sledeci && tekuci -> sledeci -> br_beba > novi -> br_beba){
                tekuci = tekuci -> sledeci;
            }
            novi -> sledeci = tekuci -> sledeci;
            tekuci -> sledeci = novi;
        }
        return glava;
    }
}



Dan* ucitavanje(char* fajl){
    // pravimo novu listu
    Dan *glava = NULL;
    FILE *f;
    f = fopen("C:\\projects\\Ispit Januar\\2019\\grupa1.txt", "r");
    if (f == NULL){
        printf("Fajl nije dobro ucitan\n");
        return NULL;
    }
    int dan, mesec, godina, br_beba;
    // ovo == 4 je zbog while funckije, tada se prekida
    while (fscanf(f, "%d%d%d%d", &dan, &mesec, &godina, &br_beba) == 4){
        Dan *novi = napraviElement(dan, mesec, godina, br_beba);
        
        glava = ubaciUListu(glava, novi);
    }
    fclose(f);
    return glava;
}

// koliko je rodjenih beba u jednoj godini it
int rodjene_it(Dan* glava, int godina){
    int ukupno = 0;
    while (glava != NULL){
        if (glava -> godina == godina){
            ukupno += glava -> br_beba;
        }
        glava = glava -> sledeci;
    }
    return ukupno;
}

// koliko je rodjenih beba u jednoj godini rek

int rodjene_rek(Dan* glava, int godina){
    if(glava == NULL)
        return 0;
    else    
        if (glava -> godina == godina){
            return glava->br_beba + rodjene_rek(glava->sledeci, godina);
        }
        else{
            return rodjene_rek(glava->sledeci, godina);
        }
}


/** Pomoćna funkcija koja poziva rodjeneIt i rodjeneRek. */
void rodjeneUGodini(Dan *l) {
    int godina;
    printf("Unesite godinu: ");
    scanf("%d", &godina);

    printf("Broj rodjenih u godini %d (iteracija): %d\n", godina, rodjene_it(l, godina));
    printf("Broj rodjenih u godini %d (rekurzija): %d\n", godina, rodjene_rek(l, godina));
}


// funkcija koja pravi novu listu tako da bude sortirana po mesecima i godinama
void rodjeneSortPoMesecu (Dan* glava){
    // pravimo novu listu
    // koristimo nasu strukuru samo ne koristimo podatak dan, jer se trazi ispis mesec,godina,broj_beba
    Dan *glava2 = NULL;
    
    for (Dan *tekuci = glava; tekuci; tekuci = tekuci->sledeci){
        // ako je nova lista prazna, dodajemo element na pocetak
        if (glava2 == NULL){
            glava2 = napraviElement(tekuci->dan, tekuci->mesec, tekuci->godina, tekuci->br_beba);
        }else{
            // proveramo da li treba da tekuci dodje na pocetak (najmanja godina ide na pocetak)
            // ako ovaj uslov vazi onda tekuci treba da smestimo na pocetak
            if (glava2 -> godina > tekuci -> godina || (glava2 -> godina == tekuci -> godina 
            && glava2 -> mesec > tekuci -> mesec)){
                Dan *n = napraviElement(tekuci->dan, tekuci ->mesec, tekuci ->godina, tekuci -> br_beba);
                n -> sledeci = glava2;
                glava2 = n;
            } else if (glava2 -> godina == tekuci -> godina // ako su godine i meseci jednaki 
            && glava2 -> mesec == tekuci -> mesec){         // treba sabrati br_beba i napisati 
                glava2 -> br_beba += tekuci -> br_beba;     // kao jedan element
            }
            // inace se elementi dodaju posle pocetka
            else{
                Dan *t = glava2;
                while (t->sledeci && (t->sledeci->godina < tekuci->godina ||
                (t->sledeci->godina == tekuci->godina && t->sledeci->mesec < tekuci->mesec))){
                    t = t -> sledeci;
                }
                // ukoliko su godine i meseci jednaki treba sabrati broj beba
                // proveramo i da li sledeci postoji jer ako ne postoji pristupamo NULL podatku
                if (t-> sledeci && t->sledeci->godina == tekuci ->godina &&
                t->sledeci->mesec == tekuci->mesec){
                    t->sledeci->br_beba += tekuci->br_beba;
                }else{
                    Dan *novi = napraviElement(tekuci->dan, tekuci->mesec, tekuci->godina, tekuci->br_beba);
                    novi -> sledeci = tekuci ->sledeci;
                    t -> sledeci = novi;
                }
            } 
        }
    }
    
    for(Dan *temp = glava2; temp;) {
        printf("%2d.%4d. - %2d\n", temp->mesec, temp->godina, temp->br_beba);
        glava2 = temp;
        temp = temp->sledeci;
        free(glava2);
    }

}


/** Test ispis za pravilno učitavanje i ujedno brisanje liste. */
void obrisiListu(Dan* lista) {
    while(lista) {
        printf("%2d.%2d.%4d. - %2d\n", lista->dan, lista->mesec, lista->godina, lista->br_beba);
        Dan* temp = lista;
        lista = lista->sledeci;
        free(temp);
    }
}


int main (){
    Dan *glava = NULL;
    int opcija;
    char fajl[20];

    while(1) {
        meni();
        scanf("%d", &opcija);

        switch(opcija) {
            case 1:
                printf("Unesite naziv datoteke: ");
                scanf("%s", fajl);
                // Ovde bi u normalnim okolnostima trebalo prvo obrisati listu
                // pa onda učitati novu (ali to za ispit nije traženo)!
                glava = ucitavanje(fajl);
                break;
            case 2:
                rodjeneUGodini(glava);
                break;
            case 3:
                rodjeneSortPoMesecu(glava);
                break;
            case 4:
                obrisiListu(glava);
                return 0;
        }
        printf("\n");
    }


    return 0;
}