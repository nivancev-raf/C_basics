#include <stdio.h>
#include <math.h>

int broj(int i, int n, int s){
    return pow(n*2 - i, s); 
}
// s + 1
// if (s == n/2 + 1) s = 1;
double f1_rek(int i, int n, int i2, int s){
    if (i == n)
        return i + broj(i, n, s);
    else
        if (s == n/2 + 1) s = 1;
        return i % 2 == 1 ? broj(i, n, s) + i2 / f1_rek(i + 1, n, i2 + 1, s + 1)
        : i2 + broj(i, n, s) / f1_rek(i + 1, n, i2 + 1, s + 1);
}

int levo_it(int p, int n1, int s){
    return pow(n1 + p, s);
}

double f1_it(int n){
    int i = n - 1;
    int copy = n;
    int s = n / 2;
    int p = 0;
    double res = copy + levo_it(p, n, s);
    p++;
    s--;
    while (n > 1){
        res = i % 2 == 1 ? levo_it(p, copy, s) + i / res :  i + levo_it(p, copy, s) / res;
        p++;
        s--;
        if (s == 0) s = copy / 2;
        i--;
        n--;
    }
    return res;
}

int main (){
    int n = 6;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, 1, 1)); 
    printf("it:(%d) %lf\n", n, f1_it(n)); 
    return 0;
}