#include <stdio.h>
#include <string.h>
#define MAX 1000

/*
Primer: abba-afgf-ccc-fgh
Rezultat: ab-f-c
*/

int main (){
    char s[MAX] = "abba-afgf-ccc-fgh";
    char s2[MAX] = {0};
    int d = 0;
    char *token;
    token = strtok(s, "-");
    while (token != NULL){
        char *c = token;
            while (*c){
                char *p = c;
                while(*p){
                    if (*p == *c) 
                    d++;
                    char n = *p;
                    if (d == 2){
                        d = 0;
                        if (strchr(s2, n)) continue;
                        strncat(s2, &n, 1);
                    }
                    p++;
                }
            c++;
            d = 0;
            }
        s2[strlen(s2)] = '-';
        token = strtok(NULL, "-");
    }
        s2[strlen(s2) - 1] = ' ';
        s2[strlen(s2) - 2] = ' ';

    puts(s2);

    return 0;
}
