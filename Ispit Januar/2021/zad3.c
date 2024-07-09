#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
a) (10p) učitavanje podataka, podaci o ocenama učitavaju se u listu sortiranu prvo po
rednom broju učenika rastuće, pa zatim za istog učenika po nazivu predmeta alfabetski
rastuće. Jedan element liste treba da sadrži sve ocene učenika na predmetu (radi bržeg
testiranja naziv fajla se može staviti direktno u programu, ne mora se učitavati). Posle
učitavanja ispisati listu na standradni izlaz.
b) (10p) broj ocena na predmetu, unosi se predmet i raspon ocena (na primer 3 5) i
potrebno je ispisati koliko ima ocena u datom rasponu na predmetu (u ovom primeru
broje se ocene 3, 4 i 5), raspon se može sastojati i od dve iste ocene tada se prebrojava
samo ta ocena. Ovu funkcionalnost implementirati na dva načina, iterativno i
rekurzivno.
c) (4p) dodavanje ocene za učenika na predmetu, unosi se redni broj učenika,
predmet i ocena, potrebno je pronaći element u listi i ako učenik nema 5 ocena na
predmetu dodati mu novu ocenu, ako već ima 5 ocena ispisati poruku. Nakon dodavanja
ponovo ispisati listu.
d) (1p) izlaz iz programa i brisanje liste
*/
// 5 ENG 5 4 5 - znači da je učenik sa rednim brojem 5 dobio ocene 5, 4 i 5 iz matematike
typedef struct Element{
    int redni_b; 
    char predmet[3]; // predmet ima 3 karaktera
    int ocene[5]; // 5 je jer je to max broj ocena
    int brOcena; // svaki student ima poseban broj ocena, potrebno za kasnije u zadatku
    struct Element* sledeci;
}Element;

void meni(){
    printf("1. ucitavanje podataka:\n");
    printf("2. broj ocena na predmetu:\n");
    printf("3. dodavanje ocene za ucenika na predmetu:\n");
    printf("4. Izlaz\n");
}

Element *napravi(int redni_b, char predmet[3], int ocene[5], int num){
    Element *b = (Element*)malloc(sizeof(Element));
    b ->redni_b = redni_b;
    strcpy(b->predmet, predmet);
    for (int i = 0; i < num; i++){
        b->ocene[i] = ocene[i];
    }
    b->brOcena = num;
    b->sledeci = NULL;
}

int uporedi(Element *glava, Element *novi){
    if (glava->redni_b > novi->redni_b){
        return 1;
    }else if(glava->redni_b < novi->redni_b){
        return -1;
    }
    else{
        strcmp(glava->predmet, novi->predmet);
    }
}

Element *ubaciUlistu(Element *glava, Element *novi){
    // sort je prvo po rednom broju od najmanjeg ka najvecem
    // za istog učenika po nazivu predmeta alfabetski rastuće
    if (glava == NULL){
        return novi;
    }
    else{
        // ako se ubacuje na pocetak;
        if (uporedi(glava, novi) > 0){
            novi->sledeci = glava;
            glava = novi;
            return novi;
        }
            Element *tekuci = glava;
            while(tekuci->sledeci && uporedi(tekuci->sledeci, novi) < 0){
                tekuci = tekuci->sledeci;
            }
            // ubacujemo na kraj
            if (tekuci->sledeci != NULL){
                novi->sledeci = tekuci->sledeci;
                tekuci->sledeci = novi;
            }
            else{
                tekuci->sledeci = novi;
            }
        return glava;
    }
}

Element* ucitavanje(char* fajl){
    FILE *f;
    Element *glava = NULL;
    f = fopen("C:\\projects\\C\\Ispit Januar\\2021\\ocene1.txt", "r");
    if (f == NULL){
        printf("Fajl nije uspesno ucitan!\n");
        return NULL;
    }
    char linija[256];
    while(fgets(linija, sizeof(linija), f)){
        char* token;
        int redni_b;
        char predmet[3];
        int ocene[5];
        int brOcena;
        int count = 0, num = 0;
        token = strtok(linija, " ");
        while (token != NULL){
            if (count == 0){
                redni_b = atoi(token);
            }
            else if(count == 1){
                strcpy(predmet, token);
            }
            else{
                ocene[num++] = atoi(token);
            }
            count++;
            token = strtok(NULL, " ");
        }
        Element *novi = napravi(redni_b, predmet, ocene, num);
        glava = ubaciUlistu(glava, novi);
    }


    fclose(f);
    return glava;
}

int brojOcenaIt(Element *glava, char predmet[3], int ocena1, int ocena2){
    int count = 0;
    while (glava != NULL){
    if (strcmp(glava -> predmet, predmet) == 0){
        for (int i = 0; i < glava->brOcena; i++){
            if (glava->ocene[i] >= ocena1 && glava->ocene[i] <= ocena2){
                count++;
                }
            }
        }
        glava = glava->sledeci;
    }
    return count;
}

int brojOcenaRek(Element *glava, char predmet[3], int ocena1, int ocena2){
    int count = 0;
    if (glava == NULL)
        return 0;
    else 
        if (strcmp(glava -> predmet, predmet) == 0){
        for (int i = 0; i < glava->brOcena; i++){
            if (glava->ocene[i] >= ocena1 && glava->ocene[i] <= ocena2){
                count++;
                }
            }
        }
        return count+brojOcenaRek(glava->sledeci, predmet, ocena1, ocena2);
}


void ispisiIt_Rek(Element *glava){
    //printf("broj ocena it: %d\n", brojOcenaIt(glava, "LIK", 3, 5));
    printf("Unesi predmet(mora bas kao sa liste, npr. 'LIK'):\n");
    char predmet[3];
    int ocena1, ocena2;
    scanf("%s", predmet);
    printf("unesi raspon ocena-> ocena1:");
    scanf("%d", &ocena1);
    printf("ocena2:");
    scanf("%d", &ocena2);
    printf("broj ocena it: %d\n", brojOcenaIt(glava, predmet, ocena1, ocena2));
    printf("broj ocena rek: %d\n", brojOcenaRek(glava, predmet, ocena1, ocena2));
}

void ispis(Element *glava){
    for (Element *temp = glava; temp;){
        printf("%d %s", temp->redni_b, temp->predmet);
        for (int i = 0; i < temp->brOcena; i++){
            printf(" %d", temp->ocene[i]);
        }
    printf("\n");
    temp = temp->sledeci;
    }
}

void dodavanjeOcene(Element *glava){
    char predmet[3];
    int ocena, rb;
    printf("Unesi predmet(mora bas kao sa liste, npr. 'LIK'): ");
    scanf("%s", predmet);
    printf("Unesi redni broj: ");
    scanf("%d", &rb);
    printf("Unesi ocenu: ");
    scanf("%d", &ocena);    
    int flag = 0;
    Element *temp = glava;
    while(glava != NULL){
        if (glava->redni_b == rb && strcmp(glava->predmet, predmet) == 0 && glava -> brOcena < 5){
            glava->ocene[glava->brOcena++] = ocena;
            break;
        }
        if (glava->redni_b == rb && strcmp(glava->predmet, predmet) == 0 && glava -> brOcena == 5){
            printf("Ucenik ima 5 ocena!\n");
            flag = 1;
            break;
        }
        glava = glava->sledeci;
    }
    
    if (flag == 0){
        while (temp != glava){
            printf("%d %s ", temp->redni_b, temp->predmet);
            for (int i = 0; i < temp->brOcena; i++){
                printf("%d ", temp->ocene[i]);
            }
            printf("\n");
            temp = temp->sledeci;
        }
        ispis(glava);
    }
}


void brisiListu(Element *glava){
    printf("Brisem listu... EXIT...\n");
    while (glava != NULL){
        Element *temp = glava;
        glava = glava ->sledeci;
        free(temp);
    }
}


int main (){
    Element *glava = NULL;
    char fajl[20];
    int opcija;
/*
    printf("Unesite naziv datoteke: ");
    scanf("%s", fajl);
    glava = ucitavanje(fajl);
    ispis(glava);
*/

    while (1){
        meni();
        scanf("%d", &opcija);
        switch(opcija){
            case 1:
                printf("Unesite naziv datoteke: ");
                scanf("%s", fajl);
                glava = ucitavanje(fajl);
                ispis(glava);
                break;
            case 2:
                ispisiIt_Rek(glava);
                break;
            case 3:
                dodavanjeOcene(glava);
                break;
            case 4:
                brisiListu(glava);
                return 0;
        }
        printf("\n");
    }

    return 0;
}