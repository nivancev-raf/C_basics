#include <stdio.h>
#include <stdlib.h>

int main(){

    int n = 4;
    int mat[100][100];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int niz[n*n];
    int index = 0;

    for(int j = 0; j<n; j++){
        if(j%2 == 0){
            for(int i = 0; i<n; i++)niz[index++] = mat[i][j];
        }else{
            for(int i = n-1; i>=0; i--)niz[index++] = mat[i][j];
        }
    }

    int brpon = 1, max = 0;

    for(int i = 0; i< n*n; i++){
        if(niz[i] == niz[i+1])brpon++;
            if(brpon>max){
                max = brpon;
                }
    }
        
    printf("broj ponavljanja: %d", max);


    return 0;
}
