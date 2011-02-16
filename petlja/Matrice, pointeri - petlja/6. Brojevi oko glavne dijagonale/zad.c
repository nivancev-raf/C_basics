#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/06_brojevi_oko_glavne_dijagonale

Brojevi oko glavne dijagonale:
Napisati program koji ispisuje 1 iznad glavne
dijagonale, 3 ispod glavne dijagonale i 2 na glavnoj dijagonali kvadratne matrice.
Ulaz
5
Izlaz
2 1 1 1 1
3 2 1 1 1
3 3 2 1 1
3 3 3 2 1
3 3 3 3 2
*/

int main (){
    int a = 5, b = 5;
    int mat[a][b];
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            if (i == j) mat[i][j] = 2;
            if (j > i) mat[i][j] = 1;
            if (i > j) mat[i][j] = 3;
        }
    }
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }


    return 0;
}