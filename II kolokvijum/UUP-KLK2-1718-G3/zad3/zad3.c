#include <stdio.h>
#include <string.h>
#define MAX 1000
/*
Primer: abba-affg-ccc-fgh
Rezultat: ab-afg-c-fgh
*/

int main (){
    char s[MAX] = "abba-affg-ccc-fgh";
    char s2[MAX] = {0};
    char *token;
    token = strtok(s, "-");
    while (token != NULL){
        char *c = token;
            while (*c){
                char *p = strchr(token, *c);
                if (p == c)
                    c++;
                else 
                    strcpy(c, c + 1);
            }
        strcat(s2, token);
        s2[strlen(s2)] = '-';
        token = strtok(NULL, "-");
    }
    s2[strlen(s2) - 1] = ' ';
    puts(s2);
    return 0;
}