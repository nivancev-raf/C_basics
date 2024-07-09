#include <stdio.h>
#include <math.h>


int fib(int n){
    int prev1 = 1, prev2 = 1, fib = 0;
    if (n == 1 || n == 2) return 1;
    for (int i = 2; i < n; i++){
        fib = prev1 + prev2;
        prev1 = prev2;
        prev2 = fib;
    }
    return fib;
} 

int broj(int n){
    return pow(n,2);
} 

double f1_rek(int i, int n, int n1, int p){
    if (i == n)
        return n1;
    else 
        return sqrt(broj(n1) + fib(p) * f1_rek(i+1, n, n1 - 1, p + 1));
}

double f1_it(int n){
    int i = 1;
    double res = sqrt(broj(i));
    i++;
    while (n > 1){
        res = sqrt(broj(i) + fib(n) * res);
        i++;
        n--;
    }
    return res;
}

int main (){
    int n = 6;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, n, 2));
    printf("it:(%d) %lf\n", n, f1_it(n));
    //printf("%d", fib(n));
    return 0;
}