#include <stdio.h>

/*
2 1 3 4 5 
6 1 9 3 1
2 1 1 1 1
2 2 2 2 6
3 1 2 4 1
ispis: dimenzija:4X2, gornji levi ugao: 1,1
*/
int mat[100][100];

int proveriPravouganik(int indexi, int indexj, int sirina, int visina){
    for (int i = 0; i < sirina; i++){
        for (int j = 0; j < visina; j++){
            if (mat[indexi + i][indexj + j] % 2 == 0) return 0;
        }
    }
    return 1;
}

int main (){
    int n = 5;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
// k sluzi za sirinu
// m sluzi za visinu pravouganioka

    int dimenzijaNajveca = 1;
    int rezSirina = 0, rezVisina = 0, rezIndexi = 0, rezIndexj = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            //if (mat[i][j] % 2 == 1){
            //    int element = mat[i][j];
            //}
            int k = 1;
            while(j + k < n && mat[i][j + k] % 2 == 1) k++;
            int m = 1;
            while(i + m < n && mat[i + m][j] % 2 == 1) m++;
        if (k*m < dimenzijaNajveca) continue;
            int najveciPronadjen = 0;
            int prethodni_m = m;
            do{
                m = prethodni_m;
                if (k*m <= dimenzijaNajveca) break;
                do{
                    if(proveriPravouganik(i, j, k, m) && k*m > dimenzijaNajveca){
                        dimenzijaNajveca = k*m;
                        rezIndexi = i;
                        rezIndexj = j;
                        rezSirina = k;
                        rezVisina = m;
                        najveciPronadjen = 1;
                        break;
                    }
                    m--;
                }while(m >= 1 && !najveciPronadjen);
                k--;
            }while(k >= 1 && !najveciPronadjen);
        }
    }
        
        
    printf("dimenzija: %dX%d, gornji levi ugao: %d,%d\n", rezSirina, rezVisina, rezIndexi, rezIndexj);


    return 0;
}