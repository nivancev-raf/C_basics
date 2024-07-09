#include <stdio.h>
#include <string.h>
// ??????????????????????????????????
/*
(7p) Napisati program koji učitava string sastavljen od reči razdvojenih spejsom. Reči su
napisane malim slovima abecede. Program treba da proveri i ispiše za svaku reč koja
sadrži ista slova najmanju razdaljinu između istih slova (broje se slova koja se nalaze
između istih slova). Ispisuje se reč i razdaljina.
Primer: mamaa kjloijk abc hjkjk
Ispis: mamaa - 0
kjloijk - 3
hjkjk - 1
*/


int main (){
    char s[] = "mamaa kjloijk abc hjkjk";
    char *token;
    char p, t;
    token = strtok(s, " ");
    while (token != NULL){
        char *c = token;
        char *c1 = token;
        int n = strlen(token);
            for (int i = n; i > 0; i--){
                c += (i - 1);
                t = *c;
                for (int j = n - 1; j > 0; j--){
                    c1 += (j - 1);
                    p = *c1;
                    if (p == t){
                        printf("1");
                        n--;
                        break;
                    }
                }
            }

        token = strtok(s, " ");
    }

    return 0;
}