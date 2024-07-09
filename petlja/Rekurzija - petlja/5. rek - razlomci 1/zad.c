#include <stdio.h>

// https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/05_razlomci_1

double f1(int n){
    if (n == 1)
        return 1;
    else 
        return n + 1.0 / f1(n - 1);
}


double f1_i(int n){
    int i = 2;  
    float res = 1;
    while (i <= n){
        res = i + 1.0/res;
        i++;
    }        
    return res;
}



int main () {
    int n = 5;
    printf("rek:(%d) %lf\nit:(%d) %lf\n", n, f1(n), n, f1_i(n));     
    return 0;
}