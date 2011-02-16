#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/04_najcesce_ponavljanje

Ulaz
7
3 8 12 12 5 8 8
Izlaz
8 3
*/

int main (){

    int n;
    printf("Enter the number of characters: ");
    scanf("%d", &n);
    printf("Enter the characters: ");
    int array[n];
    int brojac = 1, brojEl = 0, max;

    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++){
        brojac = 1;
        for (int j = i + 1; j < n; j++){
            if (array[i] == array[j]) brojac++;
        }
        if (brojac > brojEl || (brojac == brojEl && max > array[i])){
            max = array[i];
            brojEl = brojac;

        }
    }
    printf("%d %d", max, brojEl);

    return 0;
}


