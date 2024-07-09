#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/05_suma_podniza

Napisati program koji iz datog niza A, dužine N, ponalazi
podniz uzastopnih elemenata niza A sa najvećom sumom elemenata. Ispisati sumu tog podniza.

Ulaz
5
1 -5 3 12 -1
Izlaz
15
*/


int suma(int x, int y, int* array){
    int zbir = 0;
    for (int i = x; i <= y; i++){
        zbir += array[i];
    }
    return zbir;
}

int main (){
    int n;
    printf("Enter the number of characters: ");
    scanf("%d", &n);
    printf("Enter the characters in array: ");
    int array[n], max;
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (i == 0 && j == 1 || suma (i, j, array) > max)
                max = suma (i, j, array);
        }
    }
    printf("%d", max);
    return 0;
}
