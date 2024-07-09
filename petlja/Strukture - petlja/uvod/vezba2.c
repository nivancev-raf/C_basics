#include <stdio.h>

// 1. nacin kako se pise (u mainu ne moramo pisati struct, vec samo datum godiste;)
typedef struct 
{
    int godina;
    int mesec;
    int dan;
}datum;

// 2. nacin kako se pise (ali ovde onda u mainu moramo pisati struct datum godiste;)
/*
struct datum 
{
    int godina;
    int mesec;
    int dan;
};
*/

int main (){
    datum godiste;
    godiste.godina = 2002;
    godiste.mesec = 4;
    godiste.dan = 29;

    printf("%d.%d.%d\n", godiste.dan, godiste.mesec, godiste.godina);

    return 0;
}