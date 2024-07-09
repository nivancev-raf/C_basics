#include <stdio.h>
/*
n = 5;
AAAAB
ABABA
BBBCB
BCBCB
CCDCC
*/

int main () {

    int n = 7;
    char c = 'A';
    int startp = 0, startnp = 0;
    int p = 1;

    for (int i = 0; i < n; i++){
        // paran red;
        if (i % 2 == 0){
        for (int j = 0; j < n; j++){
            if (n - p == j){
                printf("%c", c + p);
            }else{
            printf("%c", c + startp);
                }
            }
        p++;
        startp++;
        }
        // neparan red;
        else{
            for (int j = 0; j < n; j++){
                if (j % 2 == 0){
                    printf("%c", c + startnp);
                }else{
                    printf("%c", c + startnp + 1);
                }
            }
        startnp++;
        }
    printf("\n");
    }

    return 0;

}
