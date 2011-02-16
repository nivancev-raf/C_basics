#include <stdio.h>

// dosta uslova ali ne dovoljno


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
    int a = numofDecals(n);
    int mat[a][a];

    // zero matrix
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            mat[i][j] = 0;
        }
    }
    int p = 0;
    // popunjena sporedna dijagonala
    for (int i = a - 1; i >= 0; i--){
        for (int j = p; j <= p; j++){
            mat[i][j] = n % 10;
            n /= 10;
        }
        p++;
    }
    int duplikat = 0;
    // popuniti ostala polja matrice
    for (int i = 0; i < a; i++){
        for (int j = a - 1; j >= 0; j--){
            
            // ovim uslovom ne diramo dijagonalu
            if (i + j == a - 1) continue;
            // ovim uslovom dupliramo sve sa desne strane u odnosu na dijagonalu
            if (i + j > a - 1) mat[i][j] = mat[i][j-1];
            // ovim uslovom resetujemo na 0 ako stigne do 9 sa desne strane
            if (mat[i][j] == 9 && !(i + j == a - 1)){
                mat[i][j+1] = 0; 
            }
            // sa sledeca dva uslova pravimo duplkate u ostalim poljima 
            //matrice ali sa leve strane
            if (i + j < a - 1 && duplikat != 1) {
                mat[i][j] = mat[i][j+1] - 1;
                duplikat++;
                continue;
            }
            if (duplikat == 1){
                mat[i][j] = mat[i][j+1];
                duplikat = 0;
            }
            /*
            // desna strana u odnosu na dijagonalu
            if (i + j > a - 1 && duplikat != 1 && mat[i][j] == 0) {
                mat[i][j] = mat[i][j] + 1;
                duplikat++;
                continue;
            }
            if (duplikat == 1){
                mat[i][j] = mat[i][j+1];
                duplikat = 0;
            }
            */
        }
    }

    // print matrix
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
/*
// ovim uslovom resetujemo na 0 ako stigne do 9 sa desne strane
if (mat[i][j] == 9 && !(i + j == a - 1)){
    mat[i][j+1] =  
}
*/