#include <stdio.h>

/*
n = 8; 
aaa^^aaa
bb^**^bb
c^****^c
^******^
^******^
c^****^c
bb^**^bb
aaa^^aaa

n = 5;
aa^aa
b^*^b
^***^
b^*^b
aa^aa
*/

int main () {
    int n;
    scanf("%d", &n);
    int cp = 'a';
    int cnp = 'a';
    int startp, endp;
    int startnp, endnp;
    if (n % 2 == 0){
        endp = n / 2;
        startp = endp - 1;
    }else{
        endnp = n / 2;
        startnp = endnp;
    }

    for (int i = 0; i < n; i++){
        // paran slucaj
        if (n % 2 == 0){
        for(int j = 0; j < n; j++){
            if (j < startp || j > endp){
                printf("%c", cp);
                }else if(startp == j){
                    printf("^");
                }else if(endp == j){
                    printf("^");
                }else{
                    printf("*");
                }
            }
            //neparan slucaj
        }else{
            for(int j = 0; j < n; j++){
            if (j < startnp || j > endnp){
                printf("%c", cnp);
                }else if(startnp == j){
                    printf("^");
                }else if(endnp == j){
                    printf("^");
                }else{
                    printf("*");
                }
            }
        }
        if (i < n / 2){
            startp--;
            endp++;
            startnp--;
            endnp++;
            cp++;
            cnp++;
        }else if(i == n / 2){
            startp = 1;
            endp = n - 2;
            cp = 'a' + (n / i);
            startnp = 1;
            endnp = n - 2;
            cnp = 'a' + (n / i - 1);
        }
        else{
            startp++;
            endp--;
            startnp++;
            endnp--;
            cp--;
            cnp--;
        }
        printf("\n");
    }


    return 0;
}