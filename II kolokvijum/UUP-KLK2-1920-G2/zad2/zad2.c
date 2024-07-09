#include <stdio.h>

/*
n=3 m=5
5 3 3 3 3
5 3 1 1 1
5 3 1 9 9
5 5 5 7 9
7 7 7 7 9
*/

int main (){
    int n = 3, m = 5;
    int mat[m][m];
    //zero mat
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            mat[i][j] = 0;
        }
    }
    int x[] = {-1, 0, 1, 0};
    int y[] = {0, 1, 0, -1};
    int dir = 0; // 0 - levo, 1 - dole, 2 - desno, 3 - gore
    int i = 0, j = m - 1, num = 1;
    while(num <= m*m){
        num++;
        int i2 = i + y[dir];
        int j2 = j + x[dir];
        if (i2 >= 0 && i2 < m && j2 >= 0 && j2 < m && mat[i2][j2] == 0){
            mat[i][j] = n;
            i = i2;
            j = j2;
            continue;
        }
        n = (n + 2) % 10;
        mat[i][j] = n; // sluzi za poslednji (prvi) element
        dir = (dir + 1) % 4;
        i = i + y[dir];
        j = j + x[dir];
    }
    //print mat
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", mat[i][j]);
        }
    printf("\n");
    }
    return 0;
}