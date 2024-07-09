#include <stdio.h>

double rek (int n, int i){
    if (i == n)
        return i;
    else 
        return i + (i % 2 == 0 ? -1 : 1) * (2*n-i+1)/rek(n, i+1);
}

double it (int n){
    double rez = n;
    int i = n - 1;
    while (i>0){
        rez = i + (i%2 == 0 ? -1 : 1) * (2*n - (i - 1)) / rez;
        i--;
    }
    return rez;
}

int main () {
    int n = 7;
    printf("rek:(%d) = %lf\n it:(%d) = %lf\n", n, rek(n, 1), n, it(n));

    return 0;
}