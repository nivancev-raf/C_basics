#include <stdio.h>

/*
(7 poena). Napisati funkciju koja za uneti broj n pravi matricu kao u primeru za n=45371. Prva
vrsta matrice su cifre broja, svaka sledeća donja vrsta
umanjuje broj iz gornje vrste naizmenično za 1
i 2. Prilikom oduzimanja kada se dođe do 0, kreće se opet od 9. Implementirati odgovarajuće ispise
matrice radi testiranja.
4 5 3 7 1
3 4 2 6 0
1 2 0 4 8
0 1 9 3 7
8 9 7 1 6
*/

int numofDecals (int a){
    int numofDegits = 0;
    while (a){
        a /= 10;
        numofDegits++;
    }
    return numofDegits;
}

int main (){
    int n = 45371, copy = n;
    int a = numofDecals(n);
    int mat[a][a];
    // popuni matricu
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            mat[i][j] = 0;
        }
    }
    // popunjavamo prvi red
    for (int i = a - 1; i >= 0; i--){
        mat[0][i] = n % 10;
        n /= 10;
    }
    /*
    4 5 3 7 1
    3 4 2 6 0
    1 2 0 4 8
    0 1 9 3 7
    8 9 7 1 6
    */
   int oduzmi = 1;
    // popunjavamo ostale redove
    for (int j = 1; j < a; j++){
        for (int k = 0; k < a; k++){
            mat[j][k] = mat[j - 1][k] - oduzmi;
            if (mat[j][k] < 0){
                if (oduzmi == 2){
                    mat[j][k] = 8;
                }else{
                    mat[j][k] = 9;
                }
            }
            if (mat[j - 1][k] == 1 && oduzmi == 2){
                mat[j][k] = 9;
                
            }
        }
        if (j % 2 == 0)
            oduzmi = 1;
        else 
            oduzmi = 2;
    }
    
    // print mat
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}














/*
int cifra = 0;
    int p = 1, t = 2;
    for (int i = 0; i < a; i++){
        n = copy;
         for (int j = a - 1; j >= 0; j--){
            if (i == 0 || i % 2 == 1){
            cifra = n % 10;
            if (i != 0 && mat[i - 1][j] == 0){
                cifra = 9;
            }
            mat[i][j] = cifra - i;
            n /= 10;
            }
            else{
            cifra = n % 10;
            if (mat[i - 1][j] == 0){
                cifra = 11;
            }   
            mat[i][j] = cifra - i - 1;
            n /= 10;
            }
        }
    }
*/