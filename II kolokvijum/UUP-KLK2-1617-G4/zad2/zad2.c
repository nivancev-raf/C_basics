#include <stdio.h>

/*

2 3 5 2 1 
3 5 1 2 1 
1 2 2 5 3 
7 3 2 5 4 
1 3 3 1 5 

3 7 5 6 2
5 4 7 2 2
2 3 7 5 5
3 9 8 6 5
3 4 4 8 1
*/

int main (){
    int a = 5;
    int mat[a][a];
    int mat2[a][a];
    // popunjavamo matricu 1
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    // popunjavamo matricu 2 sa nulama
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            mat2[i][j] = 0;
        }
    }

    // pravimo novu matricu
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            if (j == 0) mat2[i][j] = mat[i][j+1];
            else if (j == a-1) mat2[i][j] = mat[i][j-1];
            else mat2[i][j] = mat[i][j-1] + mat[i][j+1];
        }
    }

    printf("\n");
    
    // printamo matricu
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }


    return 0;
}