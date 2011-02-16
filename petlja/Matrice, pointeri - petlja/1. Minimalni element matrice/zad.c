#include <stdio.h>

/*
problem: https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/01_minimalni_element

Ulaz
3 4
5 4 6 6
9 3 7 7
8 7 8 1
Izlaz
1
*/

int main (){
    int a, b, min, br;
    printf("Unesite dimenzije matrice: ");
    scanf("%d %d", &a, &b);
    int mat[a][b];
    
    for (int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            scanf("%d", &br);
            if((i == 0 && j == 0) || br < min)
            min = br;
        }
    }
    printf("%d", min);
    
    return 0;
}