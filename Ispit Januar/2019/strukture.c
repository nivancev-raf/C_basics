#include <stdio.h>
#include <stdlib.h>

// Primer: 23 2 2018 12 (23. februara 2018. rođeno je 12 beba).
/*
a) (7p) učitavanje podataka, unosi se naziv fajla koji sadrži opisane podatke i učitava se u listu
uređenu nerastuce po broju rođenih beba,
b) (8p) ispis broja rođenih beba u jednoj godini, unosi se godina i treba ispisati broj rođenih u toj
godini, ovu funkcionalnost je potrebno implementirati na dva načina, iterativno i rekurzivno,
c) (10p) ispis broja rođenih beba po mesecima sortirano rastude po godini i mesecu, posmatra se
broj rođenih beba u konkretnom mesecu (na primer 2.2018.) i ispisuje se mesec, godina i broj
rođenih u tom mesecu, sortirano rastude po mesecu (dozvoljeno je praviti nove strukture podataka).

1. Napravi strukturu na osnovu oblika datog u zad
2. Napravi void meni (pravi se na osnovu uslova zadatka: a), b), c)...)
3. Funkcija koja pravi novi element liste (napraviEl)
4. Funkcija koja ubacuje novi element na određeno mesto tako da lista ostane sortirana. (ubaciUListu)
5. Funkcija koja pravi listu sa podacima koje učitavamo iz fajla. (ucitavanje)
6. ispis broja rodjenih beba u godini - it i rek
7. Funkcija koja pravi novu listu tako da bude sortirana po mesecima i godinama
*/

typedef struct Element{
    int dan, mesec, godina, br_beba;
    struct Element *sledeci;
}Element;

void meni(){
    printf("Meni:\n");
    printf("1. ucitavanje podataka:\n");
    printf("2. ispis broja rodjenih beba u jednoj godini:\n");
    printf("3. ispis broja rodjenih beba sortirano po mesecima:\n");
    printf("4. Izlaz\n");
}

Element* napraviEl(int dan, int mesec, int godina, int br_beba){
    Element *a = (Element*)calloc(1, sizeof(Element));
    a -> dan = dan;
    a -> mesec = mesec;
    a -> godina = godina;
    a -> br_beba = br_beba;
    return a;
}

Element* ubaciUListu(Element *glava, Element *novi){
    if (glava == NULL){
        glava = novi;
        return novi;
    }else{
        // ubacujemo na pocetak liste
        if (novi ->br_beba > glava -> br_beba){
            novi -> sledeci = glava;
            glava = novi;
        }else{
            // trazimo mesto za element u listi
            Element *tekuci = glava;
            while (tekuci -> sledeci && tekuci -> sledeci -> br_beba > novi -> br_beba){
                tekuci = tekuci -> sledeci;
            }
            novi -> sledeci = tekuci -> sledeci;
            tekuci -> sledeci = novi;
        }
        return glava;
    }
}

Element *ucitavanje(char* fajl){
    Element* lista = NULL;
    FILE *f;
    f = fopen("C:\\projects\\Ispit Januar\\2019\\grupa1.txt", "r");
    if (f == NULL){
        printf("Fajl nije uspesno otvoren!\n");
        return NULL;
    }else{
        int dan, mesec, godina, br_beba;
        while(fscanf(f, "%d%d%d%d", &dan, &mesec, &godina, &br_beba) == 4){
            Element *novi = napraviEl(dan, mesec, godina, br_beba);

            lista = ubaciUListu(lista, novi);
        }
    }
    fclose(f);
    return lista;
}

int rodjeneIt(Element *glava, int godina){
    int ukupno = 0;
    while(glava){
        if (glava -> godina == godina){
            ukupno += glava -> br_beba;
        }
        glava = glava -> sledeci;
    }
    return ukupno;
}

int rodjeneRek(Element *glava, int godina){
    if (glava == NULL)
        return 0;
    else
        if (glava -> godina == godina){
            return glava->br_beba+(rodjeneRek(glava->sledeci, godina));
        }else{
            return rodjeneRek(glava->sledeci, godina);
        }
}

void stampajRodjene(Element* glava){
    int god;
    printf("Unesite godinu:\n");
    scanf("%d", &god);
    printf("Rodjene bebe u (%d) godini rek: %d\n", god, rodjeneRek(glava, god));
    printf("Rodjene bebe u (%d) godini it: %d\n", god, rodjeneIt(glava, god));
}


Element* sortPoMesecu(Element *glava){
    Element *glava2 = NULL;
    for (Element* tekuci = glava; tekuci; tekuci = tekuci -> sledeci){
        // ako je lista prazna dodajemo element
        if (glava2 == NULL){
            glava2 = napraviEl(tekuci->dan, tekuci->mesec, tekuci->godina, tekuci-> br_beba);
        }else{
            // ako lista nije prazna, dodajemo na pocetak uz uslove
            if (glava2 -> godina > tekuci -> godina || 
            (glava2 -> godina == tekuci -> godina && glava2 -> mesec > tekuci -> mesec)){
                Element *n = napraviEl(tekuci->dan, tekuci->mesec, tekuci->godina, tekuci->br_beba);
                n -> sledeci = glava2;
                glava2 = n;
            }else if(glava2 ->godina == tekuci -> godina && glava2 -> mesec == tekuci -> mesec){
                glava2->br_beba += tekuci->br_beba;
            }
            else{
                Element* t = glava2;
                while(t->sledeci && (t->sledeci->godina < tekuci -> godina ||
                (t->sledeci->godina == tekuci -> godina && t->sledeci->mesec < tekuci -> mesec))){
                    t = t->sledeci;
                }

                if (t->sledeci && t->sledeci->godina == tekuci->godina && t->sledeci->mesec == tekuci->mesec){
                    t->sledeci->br_beba += tekuci->br_beba;
                }else{
                    Element* novi = napraviEl(tekuci->dan, tekuci->mesec, tekuci->godina, tekuci->br_beba);
                    novi->sledeci = t->sledeci;
                    t->sledeci = novi;
                }
            }
        }
    }
    
    for (Element* temp = glava2; temp;){
        printf("%2d.%4d. - %2d\n", temp->mesec, temp->godina, temp->br_beba);
        glava2 = temp;
        temp = temp -> sledeci;
        free(glava2);
    }
}

void obrisiListu(Element* lista) {
    while(lista) {
        printf("%2d.%2d.%4d. - %2d\n", lista->dan, lista->mesec, lista->godina, lista->br_beba);
        Element* temp = lista;
        lista = lista->sledeci;
        free(temp);
    }
}

int main (){
    Element *glava = NULL;
    char fajl[20];
    int opcija;


    while(1){
        meni();
        scanf("%d", &opcija);
        switch(opcija){
            case 1:
                printf("Unesite naziv datoteke:\n");
                scanf("%s", fajl);
                glava = ucitavanje(fajl);
                break;            
            case 2:
                stampajRodjene(glava);
                break;
            case 3:
                sortPoMesecu(glava);
                break;
            case 4:
                obrisiListu(glava);
                return 0;
        }
        printf("\n");
    }


    return 0;
}