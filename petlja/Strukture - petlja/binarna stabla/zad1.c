#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor{
    int podatak;
    struct Cvor *levo, *desno;
}Cvor;


Cvor *dodajCvor(Cvor *koren, int podatak){
    if (koren == NULL){
        Cvor *novi = (Cvor*)malloc(sizeof(Cvor));
        novi -> podatak = podatak;
        novi -> levo = NULL;
        novi -> desno = NULL;
        return novi;
    }else{
        if (koren->podatak < podatak){
            koren -> levo = dodajCvor(koren->levo, podatak);
        }else{
            koren -> desno = dodajCvor(koren->desno, podatak);
        }
        return koren;
    }

}


int main (){
    Cvor *koren = NULL;



    return 0;
}