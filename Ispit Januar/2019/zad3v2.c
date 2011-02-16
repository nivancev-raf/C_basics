#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
UUP-JAN2019-G1-Z3
3. (25p) Napisati program koji učitava podatke o broju rođenih beba po datumima u jednom gradu i
smešta ih u listu. Podaci se u fajlu nalaze u obliku: dan mesec godina broj beba, svi podaci su
razdvojeni spejsom. Primer: 23 2 2018 12 (23. februara 2018. rođeno je 12 beba).
Napraviti meni za interakciju preko konzole sa slededim opcijama.
a) (7p) učitavanje podataka, unosi se naziv fajla koji sadrži opisane podatke i učitava se u listu
uređenu nerastude po broju rođenih beba,
b) (8p) ispis broja rođenih beba u jednoj godini, unosi se godina i treba ispisati broj rođenih u toj
godini, ovu funkcionalnost je potrebno implementirati na dva načina, iterativno i rekurzivno,
c) (10p) ispis broja rođenih beba po mesecima sortirano rastude po godini i mesecu, posmatra se
broj rođenih beba u konkretnom mesecu (na primer 2.2018.) i ispisuje se mesec, godina i broj
rođenih u tom mesecu, sortirano rastude po mesecu (dozvoljeno je praviti nove strukture podataka).
*/


// Prvo napravimo strukturu koja treba da ima određene podatke.
// Da bismo odlučili koje podatke treba da ima prvo pročitamo zadatak
// i odredimo šta nam je potrebno.
typedef struct Dan Dan;
struct Dan {
    int dan, mesec, godina, broj;
    Dan *sl;
};
// Nakon ovoga pišemo main koji se nalazi skroz na kraju koda.


/** Funkcija meni će ispisivati mogućnosti koje korisnik koji koristi program
može da uradi. To su uglavnom naši zadaci pod a), b), c)... */
void meni() {
    printf("Meni:\n");
    printf("1. Ucitavanje podataka\n");
    printf("2. Ispis broja rodjenih beba u godini\n");
    printf("3. Ispis broja rodjenih beba po mesecima\n");
    printf("4. Izlaz\n");
}


/** Funkcija koja pravi novi element liste. */
Dan *napravi(int dan, int mesec, int godina, int broj) {
    Dan *b = (Dan *)calloc(1, sizeof *b);
    b->broj = broj;
    b->dan = dan;
    b->mesec = mesec;
    b->godina = godina;
    return b;
}


/** Funkcija koja ubacuje novi element na određeno mesto tako da lista ostane sortirana. */
Dan* ubaciUListu(Dan* lista, Dan* novi) {
    // Ako je lista prazna, vratimo samo novu bebu.
    if (lista == NULL) {
        lista = novi;
        return novi;
    }
    else {
        // Ako lista nije prazna, da li da dodamo novi na početak?
        // Dodajemo na početak samo ako važi uslov ispod, jer lista mora da bude sortirana,
        // odnosno ako je broj beba u danu novog elementa veći od broja beba u danu sa početka liste.
        if (novi->broj > lista->broj) {
            novi->sl = lista;
            lista = novi;
        }
        // Ako iznad uslovi nisu tačni, to znači da ne ubacujemo novi element na početak.
        else {
            // Ako ne dodajemo na početak, onda mu tražimo mesto dalje u listi.
            // Pravimo novi pokazivač temp koji će pokazivati na glavu liste (da ne bismo izgubili glavu).
            Dan *temp = lista;
            // Dok postoji sledeći i dok sledeći treba da bude pre novog, idemo dalje.
            // Obratiti pažnju da temp->sl mora da stoji kao prvi uslov, jer ako ne stoji,
            // probali bismo da pristupimo njegovom podatku broj koji ne postoji.
            while(temp->sl && temp->sl->broj > novi->broj)
                temp = temp->sl;

            // Našli smo posle kog treba da bude (to je temp) i ubacujemo nov element posle njega.
            novi->sl = temp->sl;
            temp->sl = novi; /// ???? 
        }

        return lista;
    }
}


/** Funkcija koja pravi listu sa podacima koje učitavamo iz fajla. */
Dan *ucitavanje(char* fajl) { // isto što i char fajl[]
    // Pravimo novu listu.
    Dan *lista = NULL;
    // Fajl iz kojeg učitavamo podatke.
    FILE *f;
    // Otvaramo fajl.
    // Obratiti pažnju da fajl mora da se nalazi u istom folderu gde je i ovaj kod.c.
    f = fopen("C:\\projects\\Ispit Januar\\2019\\grupa1.txt", "r");

    // Ako fajl nije NULL, onda smo uspešno otvorili fajl.
    if (f == NULL) {
        printf("Fajl nije dobro ucitan.");
        return NULL;
    }

    int dan, mesec, godina, broj;
    // Čitamo sve dok mogu da se pročitaju 4 broja iz fajla (broj pročitanih stavki je 4).
    // fscanf vraća broj učitanih promenljivih.
    while(fscanf(f, "%d%d%d%d", &dan, &mesec, &godina, &broj) == 4) {
        // Pravimo novi element liste.
        Dan *novi = napravi(dan, mesec, godina, broj);

        lista = ubaciUListu(lista, novi);
    }

    // Zatvaramo datoteku i vraćamo početak liste.
    fclose(f);
    return lista;
}


/** Vraća koliko je rođenih beba u jednoj godini iterativno. */
int rodjeneIt(Dan *lista, int godina) {
    int ukupno = 0;

    // Sve dok ne dođemo do kraja liste.
    while(lista) {
        // Ako je godina jednaka našoj, saberemo broj beba.
        if (lista->godina == godina) {
            ukupno += lista->broj;
        }

        // Prelazimo na sledeći element u listi.
        lista = lista->sl;
    }

    return ukupno;
}


/** Vraća koliko je rodjenih beba u jednoj godini rekurzivno. */
int rodjeneRek(Dan *lista, int godina) {
    if(!lista)
        return 0;
    // Ovaj skraćeni zapis kaže: izračunaj koliko ih je u ostatku liste i na to dodaj:
                              // ako je odgovarajuća godina, onda broj u ovom elementu
                              // ako nije odgovarajuća godina, onda 0
    return rodjeneRek(lista->sl, godina) + (lista->godina == godina ? lista->broj : 0);
}


/** Pomoćna funkcija koja poziva rodjeneIt i rodjeneRek. */
void rodjeneUGodini(Dan *l) {
    int godina;
    printf("Unesite godinu: ");
    scanf("%d", &godina);

    printf("Broj rodjenih u godini %d (iteracija): %d\n", godina, rodjeneIt(l, godina));
    printf("Broj rodjenih u godini %d (rekurzija): %d\n", godina, rodjeneRek(l, godina));
}


/** Funkcija koja pravi novu listu tako da bude sortirana po mesecima i godinama. */
void rodjeneSortPoMesecu(Dan* lista) {
    // Pravimo novu pomoćnu listu koja ima elemente zbirne po godinama i mesecima.
    // Nema potrebe da se pravi novi tip podatka odnosno nova struktura, dovoljna je ova koju imamo (samo zanemarujemo polje dan).
    Dan* lista2 = NULL;

    // tekuci je stalno za 1 ispred liste2!!!!

    // Prolazimo kroz listu (trenutni element je temp).
    for(Dan* temp = lista; temp; temp = temp->sl) {
        // Ako je nova lista prazna, onda treba dodati novi element na početak.
        if (lista2 == NULL)
            // Pravimo novi element koristeći podatke iz temp (za dan možemo proslediti i 0 ili bilo koji drugi broj).
            lista2 = napravi(temp->dan, temp->mesec, temp->godina, temp->broj);
        else {
            // Ako nova lista nije prazna, onda tražimo gde podaci iz temp treba da se smeste tako da lista
            // bude sortirana.
            // Proveravamo poredak: ako treba da bude na početku, onda se godina ili mesec
            // razlikuju na sledeći način.
            // Ako je godina veća od godine koju ima temp
            if (lista2->godina > temp->godina ||
                // ili ako je godina ista ali je mesec veći
                    (lista2->godina == temp->godina && lista2->mesec > temp->mesec)) {
                // onda temp ubacujemo na početak liste2.
                Dan *n = napravi(temp->dan, temp->mesec, temp->godina, temp->broj);
                n->sl = lista2;
                lista2 = n;
            }
            // Ako su godine i meseci jednaki, onda broj_beba treba dodati na element liste2 koji već postoji.
            else if(lista2->godina == temp->godina && lista2->mesec == temp->mesec) {
                lista2->broj += temp->broj;
            }
            // Inače je trazeni element u listi2 tek posle početka.
            else {
                Dan *t = lista2;
                // Prolazimo kroz listu2 na sličan nacin kao sto smo prolazili kroz listu pri učitavanju.
                // Sve dok postoji sledeći element (mora da bude prvi uslov). Obratiti pažnju i na zagrade.
                while(t->sl &&
                        // Sve dok taj element ima manju godinu od godine iz temp
                        (t->sl->godina < temp->godina ||
                         // ili ima istu godinu ali manji mesec
                         (t->sl->godina == temp->godina && t->sl->mesec < temp->mesec))) {
                    // prelazimo na sledeći element.
                    t = t->sl;
                }
                // I opet iste provere kao u linijama 180-191 (ovde treba proveriti i da li sledeći postoji,
                // da ne bismo probali da pristupimo njegovim podacima, a on bude NULL).
                if (t->sl && t->sl->godina == temp->godina && t->sl->mesec == temp->mesec)
                    t->sl->broj += temp->broj;
                else {
                    Dan *novi = napravi(temp->dan, temp->mesec, temp->godina, temp->broj);
                    novi->sl = t->sl;
                    t->sl = novi;
                }
            }
        }
    }

    // Prolazimo kroz novoformiranu listu, ispisujemo je i brišemo istovremeno.
    for(Dan *temp = lista2; temp;) {
        printf("%2d.%4d. - %2d\n", temp->mesec, temp->godina, temp->broj);
        lista2 = temp;
        temp = temp->sl;
        free(lista2);
    }
}

/** Test ispis za pravilno učitavanje i ujedno brisanje liste. */
void obrisiListu(Dan* lista) {
    while(lista) {
        printf("%2d.%2d.%4d. - %2d\n", lista->dan, lista->mesec, lista->godina, lista->broj);
        Dan* temp = lista;
        lista = lista->sl;
        free(temp);
    }
}

int main() {
    Dan *lista = NULL;
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
                lista = ucitavanje(fajl);
                break;
            case 2:
                rodjeneUGodini(lista);
                break;
            case 3:
                rodjeneSortPoMesecu(lista);
                break;
            case 4:
                obrisiListu(lista);
                return 0;
        }
        printf("\n");
    }
}