#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
primer : 5 ENG 5 4 5 - znači da je učenik sa rednim brojem 5 dobio ocene 5, 4 i 5 iz matematike
*/

typedef struct Element{
    int redni_br;
    char predmet[3];
    int ocene[5];
    int brOcena;
    struct Element *sledeci;
}Element;

void meni(){
    printf("1. Ucitavanje podataka:\n");
    printf("2. Broj ocena na predmetu:\n");
    printf("3. Dodavanje ocene za učenika na predmetu:\n");
    printf("4. Izlaz\n");
}


Element *napravi(int redni_br, char predmet[], int ocene[], int brOcena){
    Element *novi = (Element*)malloc(sizeof(Element));
    novi -> redni_br = redni_br;
    strcpy(novi->predmet, predmet);
    for (int i = 0; i < brOcena; i++){
        novi->ocene[i] = ocene[i];
    }
    novi -> brOcena = brOcena;
    novi -> sledeci = NULL;
    return novi;
}

int uporedi(Element *glava, Element *novi){
    if (glava -> redni_br > novi->redni_br){
        return 1;
    }
    else if (glava -> redni_br < novi->redni_br){
        return -1;
    }
    else {
        strcmp(glava->predmet, novi->predmet);
    }
}

Element *ubaciSortirano(Element *glava, Element *novi){
    if (glava == NULL){
        return novi;
    }
    if (uporedi(glava, novi) > 0){
        novi -> sledeci = glava;
        glava = novi;
        return glava;
    }
    
    Element *temp = glava;
    while (temp->sledeci && uporedi(temp->sledeci, novi) < 0){
        temp = temp->sledeci;
    }
    if (temp->sledeci == NULL){
       temp->sledeci = novi; 
    }else{
        novi -> sledeci = temp -> sledeci;
        temp -> sledeci = novi;
    }
    return glava;
}

// 5 ENG 5 4 5
void ispisi(Element *glava){
    for (Element *tekuci = glava; tekuci;){
        printf("%d %s ", tekuci->redni_br, tekuci->predmet);
        for (int i = 0; i < tekuci->brOcena; i++){
            printf("%d ", tekuci->ocene[i]);
        }
        tekuci = tekuci -> sledeci;
        printf("\n");
    }
}

Element *ucitavanje(char* fajl){
    Element *glava = NULL;
    FILE *f;
    f = fopen("C:\\projects\\Ispit Januar\\2021\\ocene1.txt", "r");
    if (f == NULL){
        printf("Fajl nije uspesno otvoren!\n");
        return NULL;
    }

    char linija[256];
    while (fgets(linija, sizeof(linija), f)){
        char *token;
        token = strtok(linija, " ");
        int redni_br, count = 0;
        char predmet[3];
        int ocene[5];
        int brOcena = 0;
        while(token != NULL){
            if (count == 0){
                redni_br = atoi(token);
            }            
            else if (count == 1){
                strcpy(predmet, token);
            }
            else{
                ocene[brOcena++] = atoi(token);
            }
            count++;
            token = strtok(NULL, " ");
        }
        Element *n = napravi(redni_br, predmet, ocene, brOcena);
        glava = ubaciSortirano(glava, n);
    }
    ispisi(glava);
    fclose(f);
    return glava;
}

int brojOcenaIt(Element *glava, char predmet[3], int ocena1, int ocena2){
    int count = 0;
    while (glava != NULL){
        if (strcmp(glava->predmet, predmet) == 0){
            for (int i = 0; i < glava->brOcena; i++){
                if (glava -> ocene[i] >= ocena1 && glava -> ocene[i] <= ocena2) count++;
            }
        }
        glava = glava->sledeci;
    }
    return count;
}


int brojOcenaRek(Element *glava, char predmet[], int ocena1, int ocena2){
    int count = 0;
    if (glava == NULL)
        return 0;
    else 
        if (strcmp(glava->predmet, predmet) == 0){
            for (int i = 0; i < glava->brOcena; i++){
                if (glava -> ocene[i] >= ocena1 && glava -> ocene[i] <= ocena2) count++;
            }
        }
    return count+brojOcenaRek(glava->sledeci, predmet, ocena1, ocena2);
}

void pomocnabrojOcena(Element *glava){
    char predmet[3]; 
    int ocena1; 
    int ocena2;
    printf("Unesi predmet: (mora da bude isti kao sa liste -> npr: 'LIK'): ");
    scanf("%s", predmet);
    printf("Raspon ocena -> Unesi ocenu1: ");
    scanf("%d", &ocena1);
    printf("Unesi ocenu2: ");
    scanf("%d", &ocena2);
    printf("brojOcenaIt: %d\n", brojOcenaIt(glava, predmet, ocena1, ocena2));
    printf("brojOcenaRek: %d\n", brojOcenaRek(glava, predmet, ocena1, ocena2));
}

void dodavanjeOcene(Element *glava){
    Element *temp = glava;
    char predmet[3]; 
    printf("Unesi predmet: (mora da bude isti kao sa liste -> npr: 'LIK'):\n");
    scanf("%s", predmet);
    int rb, ocena;
    printf("Unesi redni br ucenika:\n");
    scanf("%d", &rb);
    printf("Unesi ocenu ucenika:\n");
    scanf("%d", &ocena);
    int flag = 0;
    while (glava != NULL){
        if (strcmp(glava->predmet, predmet) == 0 && glava->redni_br == rb){
            if (glava->brOcena < 5){
                glava->ocene[glava->brOcena++] = ocena;
                flag = 1;
                break;
            }else{
                printf("Ucenik ima 5 ocena, nema mesta za novu!\n");
                flag = 0;
                break;
            }
        }
        glava = glava -> sledeci;
    }
    if (flag){
        while (temp != NULL){
            printf("%d %s ", temp->redni_br, temp->predmet);
            for (int i = 0; i < temp->brOcena; i++){
                printf("%d ", temp->ocene[i]);
            }
            printf("\n");
            temp = temp->sledeci;
        }
    }
}

void brisi(Element *glava){
    printf("Brisanje liste... Izlaz...\n");
    while (glava != NULL){
        Element* temp = glava;
        glava = glava -> sledeci;
        free(temp);   
    }
}

int main (){
    Element *glava = NULL;
    int opcija;
    char fajl[20];

    
    while (1){
        meni();
        scanf("%d", &opcija);
        switch(opcija){
            case 1:
                glava = ucitavanje(fajl);
                break;
            case 2:
                pomocnabrojOcena(glava);
                break;
            case 3:
                dodavanjeOcene(glava);
                break;
            case 4:
                brisi(glava);
                return 0;
        }
    }

    return 0;
}