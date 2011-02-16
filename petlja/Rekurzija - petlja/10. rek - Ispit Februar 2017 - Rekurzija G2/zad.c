
#include <stdio.h>
#include <math.h>

// https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/10_ispit_feb17_2

// 1 1 2 3 5 8 13 21 - fibonacijev niz
// pitanje:
// fib1 je napisana iterativno a fib obicna je napisana rekurzivno, 
// obe f-je rade ali je drugacije resenje;

int fib1(int a){
    int prev1 = 1, prev2 = 1, fib1 = 0;
    if (a == 1 || a == 0) return 1;
    for (int i = 2; i < a; i++){
        fib1 = prev1 + prev2;
        prev1 = prev2;
        prev2 = fib1;
    }
    return fib1;
}

int fib(int n){
        if (n==1 || n==2)
            return 1;
        return fib(n-1)+fib(n-2);
    }

double f1(int i, int n, int d){
    if (i == n)
        return sqrt(fib(i));
    else 
        return sqrt((fib(i) / (i % 2 == 0 ? 1 : pow(2, d))) + f1(i + 1, n, d - 1));
}
int imenilac (int i, int n){
    return pow(2, n - i + 1);
}
/*
double f1_it(int n){
    double res = 0;
    int i = n - 1;
    while (n){
        res = sqrt(fib(n) + fib(n - 1) / imenilac(i, n)+ res);
        i--;
        n--;
    }
    return res;
}
*/

int main (){

    int n = 6;
    //printf("%d", fib(n));
    printf("rek:(%d) %lf\n", n, f1(1, n, n));
    printf("it:(%d) %lf\n", n, f1_it(n));
    return 0;
}
