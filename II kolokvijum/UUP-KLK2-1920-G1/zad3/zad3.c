#include <stdio.h>
#include <string.h>
#define MAX 100
/*
Primer: ovo je palindrom za reper
Rezultat: OVO ej mordnilap az REPER
*/

int main (){
    char s[] = "ovo je palindrom za reper";
    char s2[MAX] = {0};
    char *token;
    char c;
    int pal = 0;
    token = strtok(s, " ");
    while (token != NULL){
        int n = strlen(token);
        for (int i = n; i > 0; i--){
            char *p = token;
            p += (i-1);
            c = *p;
            if (*p == *token && i != 1){
                pal = 1;
                strupr(token);
                strcat(s2, token);
                }
            if (pal != 1){
                sprintf(s2, "%s%c", s2, c);
            }
        }
        pal = 0;
        s2[strlen(s2)] = ' ';
        token = strtok(NULL, " ");
    }
    puts(s2);
    return 0;
}