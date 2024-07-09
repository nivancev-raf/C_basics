#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/03_dva_niza

Napisati program koji za uneti niz A, duzine N, formira nizove B i C tako da su elementi
niza B parni članovi niza A, a elementi niza C su neparni članovi niza A.
Ulaz
5
3 8 15 2 6
Izlaz
8 2 6
3 15
*/

int main () {
    int n;
    printf("Enter the number of characters in array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the numbers in array: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    for (int j = 0; j < n; j++){
        if (array[j] % 2 == 0) printf("%d ", array[j]);
        else printf("\n"); printf("%d", array[j]);
        }


    return 0;
}
