#include <stdio.h>

/*
ucitana:
5 3 7 
3 5 1 
2 1 3

nova:
10 6 12
10 12 6
9 8 8

b[0,0] = a[0,0] + max (a[1,1] , a[1,2] , a[2,1] , a[2,2]) = 5 + 5 = 10
b[1,1] = a[1,1] + max (a[0,0] , a[0,2] , a[2,0] , a[2,2]) = 5 + 7 = 12
*/



int main (){
    int n = 3;
    int mat[n][n];
    int mat2[n][n];
    //scanf mat
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    //zero mat2
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            mat2[i][j] = 0;
        }
    }
    int max = 0;
    int p = 0, t = 0;
    // fill mat2
    for (int p = 0; p < n; p++){
        for (int t = 0; t < n; t++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (!(i == p || j == t)){
                        if (mat[i][j] > max) max = mat[i][j];
                    }
                }
            }
        mat2[p][t] = mat[p][t] + max;
        max = 0;
        }
    }
    
    printf("\n");
    //print mat2
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", mat2[i][j]);
        }
    printf("\n");
    }

    return 0;
}