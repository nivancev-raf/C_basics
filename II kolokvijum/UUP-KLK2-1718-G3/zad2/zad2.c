#include <stdio.h>
#include <math.h>

/*
1 9 8 4 4   
2 0 8 5 5   
2 1 9 6 5   
2 0 8 5 5   
1 9 8 4 4
*/

int numofDecals(int a){
    int nod = 0;
    while (a){
        a /= 10;
        nod++;
    }
    return nod;
}

int main (){
    int n = 45901;
    int copy = n;
    int a = numofDecals(n);
    int mat[a][a];
    //zero mat
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            mat[i][j] = 0;
        }
    }
    int p = 0, t = 0;
    // fill matrix
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            // glavna dijagonala
            if (i == j){
                mat[i][j] = n % 10;
                n /= 10;
            }
        }
    }
    
    n = copy;
    //popunjavamo sporednu dijagonalu
    for (int i = a - 1; i >= 0; i--){
        for (int j = 0; j < a; j++){
            if (i + j == a - 1){
                mat[i][j] = n % 10;
                n /= 10;
            }
        }
    }
    int red = 0;
    int start = 0, end = a - 1;
    //popunjavamo slobodna polja po kolonama izmedju brojeva
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            if (i < 2){
                if (j > start && j < end){
                    mat[j][i] = mat[i][start] + 1;
                }else{
                    if (j != start && j != end){
                        mat[j][i] = mat[i][start] - 1;
                        if (mat[j][i] < 0) mat[j][i] = 9;
                    }
                }   
            }else{
                if (j > start && j < end){
                    mat[j][i] = mat[i][end] + 1;
                }else{
                    if (j != start && j != end){
                        mat[j][i] = mat[i][end] - 1;
                        if (mat[j][i] < 0) mat[j][i] = 9;
                    }
                }   
            }
        }
            printf("i:(%d) start: %d end: %d\n", i, start, end);
            if (i < 2){
                start++;
                end--;
            }else{
                start--;
                end++;
            }
    } 




    //print matrix
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}