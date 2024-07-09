#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/05_spiralna_matrica

Spiralna matrica:
Ulaz
3 3
Izlaz
1 2 3
8 9 4
7 6 5
*/

int main () {
    int a = 3, b = 3;
    //scanf("%d%d", &a, &b);
    int mat[a][b];
    // ucita
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            mat[i][j] = -1;           
        }
    }
    int x[] = {1, 0, -1 ,0};
    int y[] = {0, 1, 0, -1};
/*
x = 1; y = 0; -> krece se desno         
x = 0; y = 1; -> krece se dole
x = -1; y = 0; -> krece se levo
x = 0; y = -1; -> krece se gore
    ///  j 0 1 2 
    /// i
    /// 0  1 2 3 
    /// 1  8 9 4 
    /// 2  7 6 5 
u sustini menjanje y-a menja redove a menjanje x-a menja kolone
*/
    int i = 0, j = -1, num = 1;
    // j = -1 jer mat[0][0] = 1; da smo stavili da j = 0, prvi element matrice bi bio 2;
    int dir = 0; /// 0 - desno, 1 - dole, 2 - levo, 3 - gore
    while (num <= a*b){
        int i2 = i + y[dir]; // sluzi za redove
        int j2 = j + x[dir]; // sluzi za kolone
        // pravimo "zidove", ogranicavamo matricu
        if(i2 >= 0 && i2 < a && j2 >= 0 && j2 < b && mat[i2][j2] == -1){
            mat[i2][j2] = num++;
            i = i2; // priprema za sledeci element 
            j = j2; // priprema za sledeci element 
        }else{
            dir++; // dir povecavamo kada menjamo pravac kretanja
            dir %= 4; // ogranicava da dir bude [0,1,2, ili 3];
        }
    }

    // ispis matrice
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            printf("%d", mat[i][j]);           
        }
        printf("\n");
    }
    

    return 0;
}