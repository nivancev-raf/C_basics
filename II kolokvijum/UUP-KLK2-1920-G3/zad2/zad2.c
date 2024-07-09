#include <stdio.h>

/*
Primer matrice:
3 4 1 6
1 2 9 8
5 6 6 1
2 3 1 1
elemente posmatramo u sledećem redosledu: 3 1 5 2 3 6 2 4 1 9 6 1 1 1 8 6
Ispis: broj ponavljanja:3
*/

int main (){
    int n = 4;
    int array[n*n];
    int mat[n][n];
    // scanf mat
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int x[] = {0, 1, 0, 1, 0};
    int y[] = {1, 0, -1, 0, 1};
    int dir = 0; 
    int tmp;
    /*
        dir = 0; -> dole
        dir = 1; -> desno
        dir = 2; -> gore
        dir = 3; -> desno
    */
    int i = 0, j = 0, num = 1, k = 0;
    while (num <= n*n){
        num++;
        int i2 = i + y[dir];
        int j2 = j + x[dir];
        if (j2 >= 0 && j2 < 2 && i2 >= 0 && i2 < n){
            tmp = mat[i][j];
            array[k++] = tmp;
            i = i2;
            j = j2;
        }
        else
        {
            dir = dir % 4;
            dir++;
        }
    }
    // print arr
    printf("\n");
    for (int i = 0; i < n*n; i++){
        printf("%d ", array[i]);
    }
    return 0;
}