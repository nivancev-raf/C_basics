#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/04_transponovana_matrica

Transponovana matrica:
Ulaz
3 6
1 2 3 4 5 6
2 3 4 5 6 7
0 9 8 7 6 5
Izlaz
1 2 0
2 3 9
3 4 8
4 5 7
5 6 6
6 7 5
*/


int main (){
    int a = 3, b = 6;
    //scanf("%d%d", &a, &b);
    int mat[a][b];
    //ucitavamo elemente matrice
    for (int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
    //ispis matrice
    for (int i = 0; i < b; i++){
        for(int j = 0; j < a; j++){
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }




    return 0;
}