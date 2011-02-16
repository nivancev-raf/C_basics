#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/07_matrica_unutar_druge

Matrica unutar druge:
Ulaz
3 5
1 1 2 3 3
4 4 5 6 6
7 7 8 9 9
2 3
1 2 3
4 5 6
Izlaz
DA
*/

int main (){
    int a, b, c, d;
    printf("unesi dimenzije matrice 1:\n");
    scanf("%d%d", &a, &b);
    printf("unesi dimenzije matrice 2:\n");
    scanf("%d%d", &c, &d);
    int mat1[a][b];
    int mat2[c][d];
    printf("unesi elemente matrice 1:\n");
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("unesi elemente matrice 2:\n");
    for (int i = 0; i < c; i++){
        for (int j = 0; j < d; j++){
            scanf("%d", &mat2[i][j]);
        }
    }
    int flag = 0;
    // a = 3, b = 5, c = 2, d = 3;  
    // sa ove dve for petlje prolazimo kroz svaki pocetak unutrasnje matrice i dajemo flag = 1;
    for (int i1 = 0; i1 <= a - c; i1++){
        for (int j1 = 0; j1 <= b - d; j1++){
            flag = 1;
            //                 
            for (int i2 = 0; i2 < c && flag; i2++){
                for (int j2 = 0; j2 < d && flag; j2++){
                    if(mat1[i1 + i2][j1 + j2] != mat2[i2][j2])          
                    flag = 0;
                }
            }
            if(flag) {
                printf("DA\n");
                return 0;
            }
        }
    }
    // Ako nismo našli, ispisujemo NE.
    printf("NE\n");

    /*
    
    // printanje ovih matrica // 
    
    printf("\n");
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < c; i++){
        for (int j = 0; j < d; j++){
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    */




    return 0;
}