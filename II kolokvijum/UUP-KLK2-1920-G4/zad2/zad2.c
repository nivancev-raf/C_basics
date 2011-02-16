#include <stdio.h>

/*
Primer matrice:
3 4 1 6
2 1 3 1
3 4 5 5
2 3 4 5
elemente posmatramo u sledećem redosledu: 3 4 1 6 1 3 1 2 3 4 5 5 5 4 3 2
Ispis: duzina sekvence: 5
*/

int main (){
    int n = 4;
    int mat[n][n];
    // popunjavamo matricu
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int array[n*n];
    int index = 0;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            for (int k = 0; k < n; k++){
                array[index++] = mat[i][k];
            }
        }else{
            for (int k = n - 1; k >= 0; k--){
                array[index++] = mat[i][k];
            }
        }
    }
    int lenght = 2, max_lenght = 0;
    // minimalna duzina sekvence je 2 (1,2), ne moze ispod toga
    for (int k = 0; k <= n*n; k++){
        if (array[k] == array[k+1] + 1){
            ++lenght;
            if (lenght > max_lenght) max_lenght = lenght;    
        }
    }
    printf("Duzina sekvence: %d\n", max_lenght);

    return 0;
}