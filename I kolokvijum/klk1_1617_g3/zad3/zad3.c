#include <stdio.h>
/*
n = 5;
11111
22442
33333
44664
55555
*/


int main () {
    int n = 5;
    int startnp = 2;
    for (int i = 0; i < n; i++){
        // parni redovi
        if (i % 2 == 0){
        for (int j = 0; j < n; j++){
            printf("%d", i + 1);    
            }
        startnp++;
        }else{
            for (int j = 0; j < n; j++){
                if (j >= 2 && j <= 3){
                    printf("%d", startnp + 1);
                }else{
                    printf("%d", startnp - 1);
                }
            }
            startnp++;
        }
        printf("\n");
    }
    return 0;
}