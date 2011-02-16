#include <stdio.h>
#include <math.h>

/*
Primer:
Uneti dimenzije matice: 3
Uneti elemente matrice:
1 2 3
4 5 6
7 8 9
Izlaz :
4 5 4
7 8 7
4 5 4
*/

int main (){
    int a = 3;
    int mat[a][a];
    int mat2[a][a];
    printf("Uneti elemente matrice:\n");
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    //zero mat2
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            mat2[i][j] = 0;
        }
    }

    int min = 10, max = 0;
    // fill
        for (int j = 0; j < a; j++){
            for (int p = 0; p < a; p++){
                for (int k = 0; k < a; k++){
                    // desna kolona
                    if (p+1 != a){
                        if (mat[k][p+1] < min) min = mat[k][p+1];
                    }
                    // leva kolona
                    if (p-1 >= 0){
                        if (mat[k][p-1] < min) min = mat[k][p-1];
                    }
                    // gornji red
                    if (j != 0){
                        if (mat[j-1][k] > max) max = mat[j-1][k];
                    }
                    // donji red
                    if (j != a - 1){
                        if (mat[j+1][k] > max) max = mat[j+1][k];
                    }
                }
            mat2[j][p] = abs(min - max);
            min = 10;
            max = 0;
            }
        }





    printf("\n");
    printf("Izlaz:\n");
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            //printf("%d ", mat2[i][j]);
        }
    printf("\n");
    }


    return 0;
}