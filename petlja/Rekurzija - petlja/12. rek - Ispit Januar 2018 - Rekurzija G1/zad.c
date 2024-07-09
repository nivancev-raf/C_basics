#include <stdio.h>

// https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/13_ispitJan18PrviZadatakGrupa1

int fibonaci(int n){
    int prev1 = 1, prev2 = 1, fib = 0;
    if (n == 0 || n == 1) return 1;
    for (int i = 1; i < n; i++){
        fib = prev1 + prev2;
        prev1 = prev2;
        prev2 = fib;
    }
    return fib;
}


double brojilac_rek (int i, int n, int p){
    return 2*n*p - 2*i*p;
}

double f1_rek(int i, int n, int p){
    if (i == n - 1)
        return fibonaci(i);
    else    
        return fibonaci(i) + brojilac_rek(i, n, p) / f1_rek(i + 1, n, p *= 10);
}

double brojilac_it (int i, int n, int p){
    return 2*n*p - 2*i*p;
}

double napravi_p(int i, int p){
    while (i){
        p*= 10;
        i--;
    }
    return p;
}

double f1_it(int n, int m){
    double res = fibonaci(n-1);
    int i = 2;
    int copy = n;
    while (n > 1){
        res = fibonaci(copy-i) + (brojilac_it(m, copy, napravi_p(m,1)) / res);
        i++;
        m--;
        n--;
    }
    return res;
}


int main (){
    int n = 6;
    //printf("rek:(%d) %lf\n", n, f1_rek(0, n, 1));
    printf("it:(%d) %lf\n", n, f1_it(n, n - 2));
    return 0;
}