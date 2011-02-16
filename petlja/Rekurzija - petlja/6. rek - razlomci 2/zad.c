#include <stdio.h>

// https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/06_razlomci_2

double f2(int i, int n){
    if (i == n)
        return i;
    else
        return n + 1.0/f2(i, n + 1);   
}

double f2_i(int n){
    int i = n - 1;
    double res = n;
    while (i){
        res = i + 1/res;    
        i--;
    }
    return res;
}

int main () {
    int n = 5;
    printf("rek:(%d) %lf\nit:(%d) %lf\n", n, f2(n, 1), n, f2_i(n));

    return 0;
}