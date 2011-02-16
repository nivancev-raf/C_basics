#include <stdio.h>

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


double f1_rek(int i, int n, int n1){
    if (i == n)
        return fib(i);
    else 
        return i % 2 == 0 ? fib(i) - (n1*3) / f1_rek(i + 1, n, n1 - 1) :
        fib(i) + (n1*3) / f1_rek(i + 1, n, n1 - 1);
}

double f1_it(int n){
    double res = fib(n);
    int i = n - 1;
    int n1;
    if (n % 2 == 0) n1 = n;
    else n1 = n - 1;
    while (n > 1){
        res = i % 2 == 0 ? fib(i) - n1 / res : fib(i) + n1 / res; 
        i--;
        n1 += 3;
        n--;
    }

    return res;
}


int main (){
    int n = 6;
    printf("rek: (%d) %lf\n", n, f1_rek(1, n, n));    
    printf("it: (%d) %lf\n", n, f1_it(n));    
    //printf("%d", fib(2));

    return 0;
}