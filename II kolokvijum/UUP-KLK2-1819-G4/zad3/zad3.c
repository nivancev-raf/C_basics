#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAX 1000

/*
PRIMER:
234-567-908-171-456-432
Izlaz: Zbir 9, 234 171 432
*/

int zbircifara(int n){
    int sum = 0, cifra;
    while(n){
        cifra = n % 10;
        n /= 10;
        sum += cifra;
    }
    return sum;
}

int main (){
    char s[] = "234-567-908-171-456-432";
    char s2[MAX];
    int array2[10];
    char *token;
    int n, j = 0, p;
    int array[10];
    char delim[] = "-";
    token = strtok(s, delim);
    while (token != NULL){
        char *c = token;
        n = atoi(c);
        p = zbircifara(n);
        //printf("p: %d\n", p);
        array[j++] = p;
        j--;
        array2[j++] = n;
        token = strtok(NULL, delim);
    }
    


    int count = 0, maxCount = 0, maxElement;
    for (int i = 0; i < j; i++){
        count = 1;
        for (int k = i+1; k < j; k++){
            if (array[i] == array[k]) {
                count++;
                if (count > maxCount) maxElement = array[k];
            }
        }
    }
    int m, t;
    printf("Zbir: %d, ", maxElement);
    for (int i = 0; i < j; i++){
        t = array2[i];
        m = zbircifara(t);
        if (m == maxElement) printf("%d ", t);
    }

    return 0;
}