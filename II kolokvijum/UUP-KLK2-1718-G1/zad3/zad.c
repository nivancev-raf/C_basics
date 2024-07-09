#include <stdio.h>
#include <string.h>
#define MAX 1000

/*
Primer: prvi drugi prvi treci drugi
Rezultat: prvi drugi treci
*/

int main (){
    char s[MAX] = "prvi drugi prvi treci drugi";
    char s2[MAX];
    char *token;
    token = strtok(s, " ");
    while (token != NULL){
        if (strstr(s2, token) == NULL && strstr(token + strlen(token) + 1, token) == NULL){
            strcat(s2, token);
            s2[strlen(s2)] = ' ';
        }
        token = strtok(NULL, " ");
    }
    puts(s2);

    return 0;
}