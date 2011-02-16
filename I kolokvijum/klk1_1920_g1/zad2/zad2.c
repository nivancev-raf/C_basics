#include <stdio.h>

/*
(7p) Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu slova tako da se proveri da li su zagrade [] i () pravilno zatvorene. Zagrade
mogu biti ugneždene jedna u drugu, s time da je dozvoljen samo jedan nivo
ugneždenosti. Ako su sve zagrade pravilno zatvorene, ispisati “ok”, inače “greska”.
Ulaz: (jedan[dva][tri][četiri]) Izlaz: ok
Ulaz: (jedan][dva) Izlaz: greska
(nbhbhjj)
*/

int main () {

    char c, zagrada1, zagrada2;
    int nivo = 0;
    while ((c = getchar()) != '\n'){
        if (c == '(' || c == '['){
            nivo++;
            if (nivo == 1) zagrada1 = c;
            if (nivo == 2) zagrada2 = c;
        }
        if (c == ')' || c == ']'){    
            if (nivo == 0 || nivo > 2 ||
            nivo == 1 && (zagrada1 == '(' && c != ')' || zagrada1 == '[' && c != ']')||
            nivo == 2 && (zagrada2 == '(' && c != ')' || zagrada2 == '[' && c != ']'))
            {
                break;
            }
        nivo--;
        }
    }

    if (nivo == 0){
        printf("ok");
    }else{
        printf("greska");
    }
    return 0;
}