#include <stdio.h>
/*
n = 5;
12345
12121
23451
23232
34512
*/


int main () {

    int n = 5;
    int startp = 1, startnp = 1;

    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            for (int j = 0; j < n; j++){
                if (startp + j > n){
                    startp = 1;
                    printf("%d", startp);
                }else{
                    printf("%d", startp + j);
                }
            }
            startp++;
        }else{
            for (int j = 0; j < n; j++){
                if (j % 2 == 0){
                    printf("%d", startnp);
                }else{
                    printf("%d", startnp + 1);
                }
            }   
        startnp++;
        }
        printf("\n");
    }


    return 0;
}
