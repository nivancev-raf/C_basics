#include <stdio.h>

/*
(7p). Napisati funkciju koja za uneti broj n pravi matricu kao u primeru za n=45371.
Poslednja vrsta su cifre broja, a svaka slededa gornja vrsta uvecava broj naizmenično za 2 i 1.
Prilikom sabiranja kada se dođe do 9, krede se opet od 0.
Implementirati odgovarajude ispise matrice radi testiranja.
*/

int numofDecals(int a){
    int numofDegits = 0;
        while(a){
            a /= 10;
            numofDegits++;
        }
    return numofDegits;
}

int main (){
    int n = 45371;
    int a = numofDecals(n);
    int mat[a][a];
    // zero mat
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            mat[i][j] = 0;
        }
    }

    // obrada matrice
    int saberi = 1;
    for (int i = a - 1; i >= 0; i--){
        for (int j = a - 1; j >= 0; j--){
            
            mat[i][j] = n % 10;
            n /= 10;
            if (i != a - 1){    
                if (saberi == 1){
                    mat[i][j] = mat[i+1][j] + saberi;
                }
                else{
                    mat[i][j] = mat[i+1][j] + saberi;
                }
            }
            if (mat[i][j] > 9){
                mat[i][j] = 0;
            }
        }
        if (i % 2 == 0) saberi = 2;
        else saberi = 1;
    }


    // print mat
        for (int i = 0; i < a; i++){
            for (int j = 0; j < a; j++){
                printf("%d", mat[i][j]);
        }
        printf("\n");
    }


    return 0;
}