#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/03_sortirane_kolone

Ulaz
4 2

1 4
7 8
4 4
9 8
14784498
Izlaz
1 4
4 4
7 8
9 8
*/
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main (){
    printf("\n");
    int a = 4, b = 2;
    int mat[a][b];
    for(int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for (int kolona = 0; kolona < b; kolona++){     
        for(int i = 0; i < a; i++){
            for (int j = i + 1; j < b; j++){
                if (mat[i][kolona] > mat[j][kolona])
                    swap(&mat[i][kolona], &mat[j][kolona]);            }
        }
    }
    printf("\n");
    for(int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
