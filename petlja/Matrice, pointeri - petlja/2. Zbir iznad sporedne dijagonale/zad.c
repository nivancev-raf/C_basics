#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/02_zbir_iznad_sporedne_dijagonale

Napisati program koji računa i ispisuje zbir 
brojeva iznad sporedne dijagonale date kvadratne matrice.
Ulaz
3
1 4 3
9 7 3
1 2 5
Izlaz
14
*/

int main (){
    int a, b, sum = 0;
    scanf("%d", &a);
    b = a;
    int mat[a][b];
    
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            if(j + i < a - 1) sum += mat[i][j];
        }
    }
    printf("%d", sum);
    return 0;
}