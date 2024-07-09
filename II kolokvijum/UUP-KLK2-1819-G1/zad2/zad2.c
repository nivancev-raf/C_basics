#include <stdio.h>
#define MAX 100


int main (){
    int a = 4;
    int mat[a][a];
    // fill
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    // red
    int p = 0, np = 0, max_np = MAX, min_p = MAX;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            // za redove
            if (mat[i][j] % 2 == 1) {
                max_np = mat[i][j];
                if (mat[i][j] > max_np){
                    max_np = mat[i][j];      
                }
            }
                if (j == a - 1){
                    for (int k = 0; k < a; k++){
                        if (mat[i][k] == max_np) np++;
                    }
                }
        }
        if (max_np != 0 && np != 0) printf("red: (%d) %d %d\n", i + 1, max_np, np);
        np = 0;
    }
    
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            // za kolone
            if (mat[j][i] % 2 == 0) {
                min_p = mat[j][i];
                if (mat[j][i] < min_p){
                    min_p = mat[j][i];      
                }
            }
                if (j == a - 1){
                    for (int k = 0; k < a; k++){
                        if (mat[k][i] == min_p) p++;
                    }
                }            
        }
        if (min_p != 0 || p != 0) printf("kolona: (%d) %d %d\n", i + 1, min_p, p);
        p = 0;
        min_p = 0;
    }


    return 0;
}