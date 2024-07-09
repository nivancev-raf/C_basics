#include <stdio.h>

/*
Primer:
1 3 1 1 1 1 
2 1 3 1 9 1
1 4 7 1 2 1
2 8 7 1 1 1
2 3 4 5 1 2
Ispis: (1,0) dim 4x4
(0,3) dim 3x3
*/

int mat[100][100];

int proveriPravougaonik(int indexi, int indexj, int k){
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            if (i == 0 || i == k - 1 || j == 0 || j == k - 1) sum1 += mat[indexi+i][indexj+j];
            else sum2 += mat[indexi+i][indexj+j];
        }
    }
    if (sum1 == sum2) return 1;
    else return 0;
}

int main (){
    int n = 6;
    int m = 5;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int rezindexi = 0, rezindexj = 0, rezVisina = 0, rezSirina = 0;
    // da probamo da nadjemo dim 3x3
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 3; k < n; k++){
                if (proveriPravougaonik(i, j, k)){
                    rezindexi = i;
                    rezindexj = j;
                    rezSirina = k;
                    rezVisina = k;
                    printf("(%d,%d) dim %dX%d\n", rezindexi, rezindexj, rezSirina, rezVisina);
                }
            }
        }
    }
    
    return 0;
}