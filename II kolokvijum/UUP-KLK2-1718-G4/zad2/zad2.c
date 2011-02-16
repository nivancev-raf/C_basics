#include <stdio.h>
#include <math.h>

/*
4 3 3 3 4
6 5 4 5 6
0 0 9 0 0
1 0 9 0 1
1 0 0 0 1
*/

int numofDecals(int a){
    int nod;
    while (a){
        a /= 10;
        nod++;
    }
    return nod;
}

int okrenitu_br(int n, int nod){
    int new_n = 0, p = 1, cifra;
    while (n){
        cifra = n % 10;
        n /= 10;
        new_n += cifra * pow(10, nod);
        nod--;
        }
    return new_n;
}

int main (){
    int n = 45901;
    int a = numofDecals(n);
    int mat[a][a];
    // zero matrix
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            mat[i][j] = 0;
        }
    }
    int p = okrenitu_br(n, a - 1);
    int p2 = p;
    int p3 = p;
    int start = 0, end = 0;
    // fill the diagonal
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            // glavna dijagonala
            if (i == j){
                mat[i][j] = p % 10;
                p /= 10;
                start = j;
            }
            // sporedna dijagonala
            if (i + j == a - 1){
                mat[i][j] = p2 % 10;
                p2 /= 10;
                end = j;
            }
           
            if (start < end){
                for (int k = start + 1; k < end; k++){
                    mat[i][k] = mat[i][j] - 1;
                }
                end = 0;
            }
            /*
            if (start > end){
                for (int k = end + 2; k < start; k++){
                    mat[i][k] = mat[i][j] - 1;
                    if (mat[i][k] < 0) mat[i][k] = 9;
                }
                end = 0;
            }
            //i != 0 && i != a - 1
            if (i == 1){
                // 10954 / 10 = 1095 % 10 = 5 + 1 = 6
                // 10754 / 10 = 1075 % 10 = 5 + 1 = 6
                if (mat[i][j] == 0){
                    mat[i][j] = 6;
                }
            }
            
            if (i <= a/2 && start && ){
                mat[i][j] = mat[i][start] + 1; 
            }
            if (i <= a/2 && j > end && end != 0){
                mat[i][j] = mat[i][end] + 1; 
            }
            */
        }
    }


    // print matrix
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

/*
            if (start < end){
                for (int k = start + 1; k < end; k++){
                    mat[i][k] = mat[i][j] - 1;
                }
                end = 0;
            }
            if (start > end){
                for (int k = end + 2; k < start; k++){
                    mat[i][k] = mat[i][j] - 1;
                    if (mat[i][k] < 0) mat[i][k] = 9;
                }
                end = 0;
            }



            if (i <= a/2 && j < start){
                mat[i][j] = mat[i][start] + 1; 
            }
            if (i <= a/2 && j > end && end != 0){
                mat[i][j] = mat[i][end] + 1; 
            }
*/