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

int levo(int i, int n){
    char c = 'a';
    n /= 2;
    i--;
    char c2;
    for (int j = 0; j < n; j++){
        c2 = c + j;
    }
    return c2 - i;
}

double f1_rek(int i, int n, int i2){
    if (i == n)
        return levo(i2, n);
    else 
        if(n % 2 == 0){
            i2 %= (n/2);
            return i % 2 == 1 ? levo(i2, n) + fib(i2) / f1_rek(i+1, n, i2 + 1): levo(i2, n) - fib(i2) / f1_rek(i+1, n, i2 + 1); 
        }
        else
        {
            i2 %= (n/2) + 1;
            return i % 2 == 1 ? levo(i2, n) - fib(i2) / f1_rek(i+1, n, i2 + 1): levo(i2, n) + fib(i2) / f1_rek(i+1, n, i2 + 1); 
        }
}

int levo_it(int n){
    char c = 'a';
    char c2;
    for (int j = 0; j < n; j++){
        c2 = c + j;
    }
    return c2;
}
double f1_it(int n){
    int i = 1;
    int copy = n;
    double res = levo_it(i);
    i++;
    while (n > 1){
        res = i % 2 == 0 ? levo_it(i) + fib(n-1) / res : levo_it(i) - fib(n-1) / res;
        i++;
        i = i % (copy/2 + 1);
        if (i == 0) i = 1;
        n--;
    }
    return res;
}

int main (){
    int n = 7;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, 1));
    printf("it:(%d) %lf\n", n, f1_it(n));
    //printf("%d", fib(n));
    //printf("%c", levo(1, n));
    //printf("%c", levo_it(3));

    return 0;
}