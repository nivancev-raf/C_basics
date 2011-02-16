#include <stdio.h>
// zadatak uradjen ali dosta nabijen

int numofDecals(int a){
    int nod;
    while(a){
        a /= 10;
        nod++;
    }
    return nod;
}

int main (){
    int n = 9622;
    int copy = n;
    int a = numofDecals(n);
    int mat[a][a];
    // zero matrix
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            mat[i][j] = 0;
        }
    }
    // fill the matrix
    if (a % 2 == 1){    
        for (int i = 0; i < a; i++){
            for (int j = a - 1; j >= 0; j--){
                if ((i == a/2) || (i == a/2 + 1)){
                    mat[i][j] = n % 10;
                    n /= 10;
                }
                // smanjujemo ispod glavnog broja
                if (i > a/2 + 1){
                    mat[i][j] = mat[i-1][j] - 1;
                }
                
                // reset za 9
                if (mat[i][j] < 0){
                    mat[i][j] = 9;
                }
                // reset za 0
                if (mat[i][j] > 9){
                    mat[i][j] = 0;
                }
            }
            n = copy;
        }
    }else{
        for (int i = 0; i < a; i++){
            for (int j = a - 1; j >= 0; j--){
                if ((i == a/2) || (i == a/2 - 1)){
                    mat[i][j] = n % 10;
                    n /= 10;
                }
                // smanjujemo ispod glavnog broja
                if (i > a/2){
                    mat[i][j] = mat[i-1][j] - 1;
                }
            }
            n = copy;
        }
    }

    // popunjavamo elemente za polja iznad glavnog broja
    if (a % 2 == 1){
        for (int i = a/2; i >= 0; i--){
            for (int j = 0; j < a; j++){
                if (i != a/2 && i != 0){
                mat[i][j] = mat[i+1][j] + 1; 
                }
                if (i == 0){
                    mat[i][j] = mat[i+1][j]; 
                }
                // reset za 9
                if (mat[i][j] < 0){
                    mat[i][j] = 9;
                }
                // reset za 0
                if (mat[i][j] > 9){
                    mat[i][j] = 0;
                }
            }
        }
    }else{
        for (int i = 0; i < a; i++){
            mat[0][i] = mat[1][i] + 1;
            // reset za 9
                if (mat[0][i] < 0){
                    mat[0][i] = 9;
                }
                // reset za 0
                if (mat[0][i] > 9){
                    mat[0][i] = 0;
                }
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
