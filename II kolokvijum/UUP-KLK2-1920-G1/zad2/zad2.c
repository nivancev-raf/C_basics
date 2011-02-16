#include <stdio.h>

/*
n=3 m=5
3 3 3 3 4
7 7 7 8 4
6 1 2 8 4
6 0 9 9 4
6 5 5 5 5
*/

int main (){
    int n = 3;
    int m = 5;
    int mat[m][m];
    int x[] = {1, 0, -1, 0};
    int y[] = {0, 1, 0, -1};
    int dir = 0; // 0 - desno, 1 - dole, 2 - levo, 3 - gore
    // zero mat
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            mat[i][j] = 0;
        }
    }
    int i = 0, j = 0, num = 1;
    while (num <= m*m){
        num++;
        int i2 = i + y[dir];
        int j2 = j + x[dir];
        if (mat[i2][j2] == 0 && i2 < m && i2 >= 0 && j2 < m && j2 >= 0){
            mat[i][j] = n;
            i = i2;
            j = j2;
            continue;
        }
            n = (n + 1) % 10; // moduo 10 sluzi za reset preko 9
            mat[i][j] = n; // ovde upisujemo poslednji element u redu
            dir = (dir + 1) % 4; // menjamo dir
            i = i + y[dir]; // priprema za sledeci element
            j = j + x[dir]; // priprema za sledeci element

    }
    // print mat
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }        


    return 0;
}