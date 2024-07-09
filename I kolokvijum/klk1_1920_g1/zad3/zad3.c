#include <stdio.h>

int main (){
    int n = 5;
    int startp, endp, startnp, endnp;
    char c = '%';
    if (n % 2 == 0){
        startp = n - 1;
        endp = n;
    }else{
        startnp = n - 1;
        endnp = startnp;
    }
//paran slucaj
    if (n % 2 == 0){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n * 2; j++){
                // za parne redove
                if (i % 2 == 0){
                    if (j == startp || j == endp) printf("%c", c);                
                    else if (j > startp && j < endp) printf("*");
                    else printf(" ");
                }
                // za neparne redove 
                else{
                    if (j >= startp && j <= endp) printf("*");
                    else printf(" ");
                }
            }
            // menjanje znaka (NE ZNAM KAKO DRUGACIJE)
            if (i == 0 || i == 3) c = '%';
            else c = '@';
            startp--;
            endp++;
            printf("\n");
        }
        // stablo za paran slucaj
        startp = n - 1;
        endp = n;
        for (int i = 0; i < n/2; i++){
            for (int j = 0; j < n*2; j++){
                if (j == startp || j == endp) printf("|");
                else printf(" ");
            }
            printf("\n");
        }
    
    }
    // neparan slucaj
    else{
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n*2; j++){
                // za parne redove
                if (i % 2 == 0){
                    if (j == startnp || j == endnp) printf("%c", c);
                    else if (j > startnp && j < endnp) printf("*");
                    else printf(" ");
                }
                // za neparne redove
                else{
                    if (j >= startnp && j <= endnp) printf("*");
                    else printf(" ");
                }
            }
            // menjanje znaka (NE ZNAM KAKO DRUGACIJE)
            if (i == 0 || i == 3) c = '%';
            else c = '@';
            startnp--;
            endnp++;
            printf("\n");
        }
        // stablo za nepara slucaj
        for (int i = 0; i < n/2; i++){
            for (int j = 0; j < n*2; j++){
                if (j == n - 1) printf("|");
                else printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}