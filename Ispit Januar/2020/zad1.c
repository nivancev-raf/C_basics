#include <stdio.h>

/*
Primer:
n = 3, m = 2
1 1 1 0 1 0
1 0 0 0 1 1
1 1 1 1 0 1
0 1 1 1 0 0
1 1 1 1 0 0
1 1 1 0 0 0
ispis: broj podmatrica 4, (2,1) (2,2) (3,1) (3,4)
*/


/*

*/
int mat[100][100];
// za visinu prosledjujemo p, a za sirinu k
int proveriPravougaonik(int indexi, int indexj, int visina, int sirina, int element){
    for (int i = 0; i < visina; i++){
        for (int j = 0; j < sirina; j++){
            if (mat[indexi+i][indexj+j] != element) return 0;
        }
    }
    return 1;     
}

int main(){
    int n = 3; 
    int m = 2;
    int a = 6;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int rezindexi = 0, rezindexj = 0;
    int count = 0;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            int element = mat[i][j];
            // sluzi za sirinu
            int k = 1;
            while (k+j < a && mat[i][k+j] == element) {
                k++;
                if (k == m) break;
            }
            // p sluzi za visinu
            int p = 1;
            while(p+i < a && mat[p+i][j] == element) {
                p++;
                if (p == n) break;
            }
            if (p == n && k == m){
                if(proveriPravougaonik(i, j, p, k, element)){
                    rezindexi = i;
                    rezindexj = j;
                    printf("(%d,%d) ", rezindexi, rezindexj);
                    count++;
                }
            }
        }
    }    
    printf("\n");
    printf("ovakvih podmatrica je: %d\n", count);
    return 0;
}