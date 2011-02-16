#include <stdio.h>

int mat[100][100];

/*
1 1 1 0 1 0
1 0 0 0 1 1
1 1 1 1 0 1
0 1 1 1 0 1
1 1 1 1 0 1
1 1 1 0 0 1
ispis: dimenzija:3X3, gornji levi ugao: 2,1
*/

int proveriPravouganik(int indexi , int indexj, int visina, int sirina, int element){
    for (int i = 0; i < visina; i++){
        for (int j = 0; j < sirina; j++){
            if (mat[indexi + i][indexj + j] != element) return 0;
        }
    }
    return 1;
}


int main (){
    int n = 6;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int rezVisina = 0, rezSirina = 0, rezindexi = 0, rezindexj = 0;
    int dimenzijaNajveca = 1;    

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int element = mat[i][j];
            // ovo je za sirinu
            int k = 1;
            while (k + j < n && mat[i][k+j] == element) k++;
            // za visinu
            int m = 1;
            while (m + i < n && mat[m+i][j] == element) m++;

            if (m*k <= dimenzijaNajveca) continue;
            int pronadjenNajveci = 0;
            int stari_m = m;
            do{
                m = stari_m;
                if (k*m <= dimenzijaNajveca) break;
                do{
                    if (proveriPravouganik(i, j, m, k, element) && k*m > dimenzijaNajveca){
                        dimenzijaNajveca = k*m;
                        rezindexi = i;
                        rezindexj = j;
                        rezSirina = k;
                        rezVisina = m;
                        pronadjenNajveci = 1;
                        break;
                    }
                    m--;
                }while(m >= 1 && !pronadjenNajveci);
                k--;
            }while(k >= 1 && !pronadjenNajveci);
        }
    }
    printf("dimenzija:%dX%d, gornji levi ugao: %d,%d\n", rezVisina, rezSirina, rezindexi, rezindexj);
//ispis: dimenzija:3X3, gornji levi ugao: 2,1
    return 0;
}