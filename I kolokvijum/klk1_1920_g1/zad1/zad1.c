#include <stdio.h>
#include <math.h>

int numofDegits(int a){
    int numDec = 0;
    while (a){
        a /= 10;
        numDec++;
    }
    return numDec;
}


int armstrong(int n){
    int digit, sum = 0, copy;
    copy = n;
    while(n){
        digit = n % 10;
        n /= 10;
        sum += pow(digit, numofDegits(copy));
    }
    if (sum == copy) return 1;
    else return 0;
}

int main() {
    int n = 12;
    //scanf("%d", &n);

    int i = 0, brojac = 0;
    for (int i = 0; i < n; i++){

    }
    while (brojac < n) {
        if (armstrong(i)) {
            printf("%d ", i);
            brojac++ ;
        }
        i++ ;
    }
    return 0;
}