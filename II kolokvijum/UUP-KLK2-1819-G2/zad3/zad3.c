#include <stdio.h>
#include <string.h>
#define MAX 1000
/*
Primer: Danas je "pravi" dan "za" sneg
Ispis: "Danas je ai dan a sneg"
??????????????????????
*/

int main (){
    char s[MAX];
    gets(s);
    char* token;
    char delim[] = "\"";
    token = strtok(s, delim);
    char* arr[10];
    int j = 0;
    while(token != NULL){
        //arr[j++] = token;
        char* c = token;
        while(*c){
            if (*c != ' '){
                printf("%s\n", token);
            }
            c++;
        }
        token = strtok(NULL, delim);
    }
    /*
    for (int i = 0; i < j; i++){
        if (arr[i] == '"') printf("1");
    }
    */
    return 0;
}