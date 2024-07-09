#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    int datum, vreme, mer1, mer2, mer3;
    struct Element *sledeci;
}Element;

void meni(){
    printf("1. učitavanje podataka:\n");
    printf("2. najveca zagadjenost:\n");
    printf("3. obrisati manja zagađenja:\n");
    printf("4. Izlaz\n");
    printf("Unesite opciju:\n");
}

Element *napravi(Element *glava, int datum, int vreme, int mer1, int mer2, int mer3){
    Element *novi = (Element*)malloc(sizeof(Element));
    novi -> datum = datum;
    novi -> vreme = vreme;
    novi -> mer1 = mer1;
    novi -> mer2 = mer2;
    novi -> mer3 = mer3;
    novi -> sledeci = NULL;
    return novi;
}

Element *sortiraj(Element *glava, Element *novi){
    if (glava == NULL){
        return novi;
    }
    // da li treba novi datum da se stavi ispred glave?
    if (glava->datum > novi->datum){
        novi->sledeci = glava;
        glava = novi;
        return novi;   
    }else{
        // trazimo mesto za novi
        Element *tekuci = glava;
        while (tekuci->sledeci && tekuci->sledeci->datum < novi->datum){
            tekuci = tekuci -> sledeci; 
        }
        if (tekuci == NULL){
            novi -> sledeci = tekuci;
        }else{
            novi->sledeci = tekuci->sledeci;
            tekuci->sledeci = novi;
        }
    }
    return glava;
}


void ispis(Element *glava){
    for(Element *temp = glava; temp;){
        printf("%d %d %d %d %d\n", temp->datum, temp->vreme, temp->mer1, temp->mer2, temp->mer3);
        temp = temp->sledeci;
    }
}

Element *ucitavanje(Element *glava){
    FILE *f;
    f = fopen("C:\\projects\\Strukture - petlja\\binarna stabla\\aqi.txt", "r");
    if (f == NULL){
        printf("Fajl nije uspesno otvoren!\n");
        return NULL;
    }
    int datum, vreme, mer1, mer2, mer3;
    while (fscanf(f, "%d%d%d%d%d", &datum, &vreme, &mer1, &mer2, &mer3) == 5){
        Element *novi;
        novi = napravi(glava, datum, vreme, mer1, mer2, mer3);
        glava = sortiraj(glava, novi);
    }
    fclose(f);
    ispis(glava);
    return glava;
}

int max(int a, int b, int c){
    if (a > b){
        if (a > c){
            return a;
        }else{
            return c;
        }
    }else{
        if (b > c) return b;
        else return c;
    }
    
}

int maxZagadjenostRek(Element *glava, int najveci){
    if (glava == NULL){
        return najveci;
    }else{
        if (max(glava->mer1, glava->mer2, glava->mer3) > najveci){
            najveci = max(glava->mer1, glava->mer2, glava->mer3);
            }
        return maxZagadjenostRek(glava->sledeci, najveci);
    }

}

Element* maxZagadjenostIt(Element *glava){
    Element *tekuci = glava;    
    int array[200] = {0};
    int k = 0;
    while (glava != NULL){
        array[k++] = max(glava->mer1, glava->mer2, glava->mer3);
        glava = glava->sledeci;
    }
    int temp;
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k - i - 1; j++){
            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    printf("max zagadjenost it: %d\n", array[k-1]);
    printf("max zagadjenost rek: %d\n", maxZagadjenostRek(tekuci, 0));
    return glava;
}

int average(int a, int b, int c){
    return (a+b+c)/3;
}

Element *manjaZagadjenja(Element *glava, int broj){
    Element *temp = glava;
    while (glava != NULL){
        temp = glava;
        if ((glava->mer1 + glava->mer2 + glava->mer3)/3 < broj){
            free(temp);    
        }
        printf("%d %d %d %d %d\n", glava->datum, glava->vreme, glava->mer1, glava->mer2, glava->mer3);
        glava = glava -> sledeci;
    }
    
    return glava;
}


void brisi(Element *glava){
    Element *temp = glava;
    printf("Brisanje liste.. EXIT...\n");
    while (glava != NULL){
        temp = glava;
        free(temp);
        glava = glava -> sledeci;
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
                glava = ucitavanje(glava);
                break;
            case 2:
                glava = maxZagadjenostIt(glava);
                break;
            case 3:
                glava = manjaZagadjenja(glava, 412);
                break;
 
        }
 

    }
 
    return 0;
}