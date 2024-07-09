#include <stdio.h>

/*
n = 45901;

2 2 3 3 4
3 4 4 5 5
8 8 9 9 0
9 0 0 1 1
1 1 2 2 3
*/

int numofDecals(int a){
    int nod;
    while (a){
        a /= 10;
        nod++;
    }
    return nod;
}

int main (){
    int n = 45901;
    int n1 = n;
    int n2 = n;
    n2 /= 10;
    int a = numofDecals(n);
    int mat[a][a];
    // zero matrix
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            mat[i][j] = 0;
        }
    }
    

    // ostatak mat
    int broj;
    for (int i = a - 1; i >= 0; i--){
        for (int j = 0; j < a; j++){
            if (i + j == a - 1){
                mat[i][j] = n1 % 10;
                broj = mat[i][j];
                n1 /= 10;
            }
            // za desno od dijagonale
            if (i + j > a - 1){
                mat[i][j] = broj;
                    if (mat[i][j-1] == mat[i][j]){
                        broj++;
                    }
                    if (mat[i][j] > 9) mat[i][j] = 0;
            }
        }
    }

   /*// za i + j < a - 1
    for (int i = 0; i < a; i++){
        for (int j = a - 1; j >= 0; j--){
            if (i + j == a - 1){
                broj = mat[i][j];
            }
            // za levo od dijagonale
            if (i + j < a - 1){
                mat[i][j] = broj - 1;
                    if (mat[i][j-1] == mat[i][j]){
                        broj--;
                    }
                    if (mat[i][j] < 0) mat[i][j] = 9;
            }
        }
    }*/


    // print matrix
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}