#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/01_okrenut_niz

Primer 1
Ulaz
4
1 3 4 2

Izlaz
2 4 3 1
*/

int main () {
    int n;
    printf("unesi broj karaktera niza: ");
    scanf("%d", &n);
    int niz[n];
    printf("unesi %d karaktera: ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &niz[i]);
        //printf("uneti karakter (%d) je: %d\n", i, niz[i]);
    }
    for (int i = 0; i < n; i++){
        printf("%d ", niz[i]);
    }

    return 0;
}
