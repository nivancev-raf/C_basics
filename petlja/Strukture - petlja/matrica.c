#include <stdio.h>

// globalna promenljiva jer je koristimo u main i u pomocnoj f-ji
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

// visina = m 
// sirina = k
int proveriPravougaonik(int indexi, int indexj, int visina, int sirina, int element){
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

    int dimenzijaNajveca = 1;
    int rezIndexVrsta = 0, rezIndexKolona = 0, rezSirina = 0, rezVisina = 0;
    // rezindex su indexi od gornjeg levog ugla
    // rezsirina i rezvisina su dimeznije najvece podmatrice
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // trazimo potencijalno najvecu dimenziju podmatrice
            int element = mat[i][j];
            // stavljamo int k = 1 i int m = 1 -> tako resetujemo stalno
            int k = 1; // krece od 1 jer se podrazumeva da se jednom sigurno pojavljuje
            while(k + j < n && mat[i][k + j] == element) k++;
            int m = 1;
            while(m + i < n && mat[m + i][j] == element) m++;
            
            // ako su k i m nula, idemo dalje (prakticno se smanjuje dim matrice za 1)
        if (k*m <= dimenzijaNajveca) continue;
            int pronadjenNajveci = 0;
            int starom = m;
            do{
                
                m = starom;
                if(k*m <= dimenzijaNajveca) break;
                do{
                    if(proveriPravougaonik(i,j,m,k,element) && k*m>dimenzijaNajveca){
                        dimenzijaNajveca = k*m;
                        rezIndexVrsta = i;
                        rezIndexKolona = j;
                        rezSirina = k;
                        rezVisina = m;
                        pronadjenNajveci = 1;
                        break;
                    }
                    // ovde smanjujemo visinu potencijalnog pravougaonika
                    // i gledamo da li je taj "novi pravougaonik" (za 1 visinu manji)
                    // mozda nas pravouganik...
                    // ako to nije slucaj sa visinom(m), onda to isto radimo sa duzinom(k)
                    // samo sto smo m izgubili, zato moramo da ga cuvamo (m = starom);
                    m--;
                }while(m>=1 && !pronadjenNajveci);
                k--;
            }while(k>=1 && !pronadjenNajveci);
        }
    }
    
    printf("dimenzija: %dX%d, indeksi %d %d\n", rezVisina, rezSirina, rezIndexVrsta, rezIndexKolona);    


    return 0;
}