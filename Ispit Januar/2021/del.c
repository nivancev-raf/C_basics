#include <stdio.h>
#define MAX 100

/**
1. (12p) Napisati program koji u datoj pravougaonoj matrici pronalazi sve zamišljene
jednakokrake pravougaone trouglove sa pravim uglom dole levo kao na slici (polovina
kvadratne matrice ispod glavne dijagonale uključujući i dijagonalu) koje čine elementi
takvi da je barem polovina elemenata parno. Ispisati indekse vrste i kolone temena
pravog ugla i dužinu kateta za sve pronađene trouglove.
Primer:
5 6
1 3 1 4 3 1
2 1 3 4 9 7
1 4 7 1 2 1
2 7 7 1 1 1
2 3 4 5 1 2

Ispis:
(4,0) - 2
(4,0) - 3
(4,0) - 4
(3,0) - 3
(1,3) - 2
*/
int mat[MAX][MAX];

int proveri(int ikraj, int jpocetak, int dim){
    int ukupno = 0, parno = 0;
    for (int i = 0; i < dim; i++){
        for (int j = 0; j <= i; j++){
            ukupno++;
            if(mat[ikraj-dim+1+i][jpocetak+j] % 2 == 0) parno++;
        }
    }
    if (parno * 2 >= ukupno) return 1;
    else return 0;
}

int main (){
    int m = 5, n = 6;
    int dim;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int dim = m;
    if (n < dim) dim = n;

    while (dim >= 2){
        for (int i = dim-1; i < m; i++){
            for (int j = 0; j <= n - dim; j++){
                if (proveri(i, j, dim)){
                    printf("(%d, %d) - %d\n", i, j, dim);
                }
            }
        }
        dim--;
    }
    return 0;
}