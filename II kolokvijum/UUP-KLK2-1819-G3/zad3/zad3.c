#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
/*
PRIMER:
ikavS nad mi je kinzarp
Svaki dan mi je praznik
*/

int main (){
    char s[] = "ikavS nad mi je kinzarp";
    char s2[MAX] = {0};
    char *token;    
    int n;
    char c;
    char delim[] = " ";
    token = strtok(s, delim);
    while (token != NULL){
        n = strlen(token);
        if (n % 2 == 1){
                for (int i = n; i > 0; i--){
                    char *t = token;
                    t += (i-1);
                    c = *t;
                    sprintf(s2, "%s%c", s2, c);
            }
            s2[strlen(s2)] = ' ';
        }else{
            strcat(s2, token);
            s2[strlen(s2)] = ' ';
        }

        token = strtok(NULL, delim);
    }
    puts(s2);



    return 0;
}