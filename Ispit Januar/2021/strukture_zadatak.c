#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    typedef struct Racun{
    char banka[20];
    char osoba[20];
    int novac;
    char grad[20];
    struct Racun* sledeci;
    }Racun;

    Racun* napravi(char banka[20], char osoba[20], int novac, char grad[20]){
        Racun* novi = (Racun*)malloc(sizeof(Racun));
        strcpy(novi->banka, banka);
        strcpy(novi->osoba, osoba);
        novi->novac = novac;
        strcpy(novi->grad, grad);
        novi->sledeci = NULL;
        return novi;
    }

    Racun* dodaj(Racun* glava, Racun* novi){
        if(glava==NULL){
            return novi;
        }  if(strcmp(glava->banka, novi->banka)>=0){
            novi->sledeci = glava;
            glava = novi;
            return novi;
        }
        Racun* tmp = glava;
            while(tmp->sledeci!=NULL){
                if(strcmp(glava->banka, tmp->sledeci->banka)>=0){
                    tmp->sledeci  = novi;
                    novi->sledeci = tmp->sledeci;
                    return glava;
                }
                tmp = tmp->sledeci;
            }
            tmp->sledeci = novi;
            novi->sledeci = NULL;
            return glava;
    }

    /*
    void ispis(Racun* glava){
        Racun* tmp = glava;
        while(tmp!=NULL){

            glava = glava->sledeci;
        }
    }
    */
    void ispis(Racun *glava){
    for (Racun *tmp = glava; tmp;){
        printf("%s %s %d %s\n", tmp->banka, tmp->osoba, tmp->novac, tmp->grad);
    //printf("\n");
    tmp = tmp->sledeci;
    }
}


    Racun* ucitaj(char* file){
        //FILE* fp = fopen(file, "r");
        FILE *fp;
        fp = fopen("C:\\projects\\C\\Ispit Januar\\2021\\racuni.txt", "r");
        char input[256];
        Racun* glava = NULL;
            if(fp==NULL){
                printf("File nije ucitan.\n");
            }

        while(fgets(input, sizeof(input), fp)){
            char* token = strtok(input,",");
            char grad[20], osoba[20], banka[20];
            int novac,krug = 0;

                while(token!=NULL){
                    if(krug==0){
                        strcpy(banka, token);
                    } else if(krug==1){
                        strcpy(osoba, token);
                    } else if(krug==2){
                        novac = atoi(token);
                    } else {
                        strcpy(grad, token);
                    }
                    krug++;
                    token = strtok(NULL,",");
                }

            Racun* novi = napravi(banka, osoba, novac, grad);
            glava = dodaj(glava, novi);
        }
        fclose(fp);
        return glava;
    }

 

int main(){


        Racun *glava = NULL;
        glava = ucitaj("racuni.txt");
        ispis(glava);

    return 0;
}


