#include <stdio.h>

/*
ucitana:
5 3 6  
3 5 1  
2 1 3   

nova:
1 13 -2
9 3 13
2 9 -1
*/

int main (){
    int n = 3;
    int mat[n][n];
    int mat2[n][n];
    // popuni mat1
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    // zero mat2
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            mat2[i][j] = 0;
        }
    }
    /*
    mat2[i][j] = levi(mat[i][j-1]) + desni(mat[i][j+1]) +
    gornji(mat[i-1][j]) + donji(mat[i+1][j]) - mat(mat[i][j])
    */
    // menjamo mat
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // za desno
            if (mat[i][j+1] != 0 && (j+1) < n)
                mat2[i][j] += mat[i][j + 1];
            // za levo
            if (mat[i][j-1] != 0 && (j-1) >= 0)
                mat2[i][j] += mat[i][j - 1];
            // za dole
            if (mat[i+1][j] != 0 && (i+1) < n)
                mat2[i][j] += mat[i+1][j];
            // za gore
            if (mat[i-1][j] != 0 && (i-1) >= 0){
                mat2[i][j] += mat[i-1][j];
            }
            mat2[i][j] -= mat[i][j];
        }
    }    

    printf("\n");
    // print mat2
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    return 0;
}