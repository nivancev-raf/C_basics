#include <stdio.h>

struct Student
{
    char ime[30];
    char prezime[20];
    char smer[3];
    int brojIndexa, godinaUpisa;
};


int main (){
    struct Student studenti[10];
    printf("unesi broj studenata:\n");
    int n;
    scanf("%d", &n);
    printf("ime, prezime, smer, broj indeksa, godina upisa:\n");
    for (int i = 0; i < n; i++){
        scanf("%s%s%s%d%d", 
        studenti[i].ime, studenti[i].prezime, studenti[i].smer, 
        &studenti[i].brojIndexa, &studenti[i].godinaUpisa);
    }
    printf("Spisak studenata:\n");
    for (int i = 0; i < n; i++){
        printf("%d. %s-%d/%d\t%s\t%s", i+1, studenti[i].smer, studenti[i].brojIndexa, studenti[i].godinaUpisa,
        studenti[i].ime, studenti[i].prezime);
    }


    return 0;
}