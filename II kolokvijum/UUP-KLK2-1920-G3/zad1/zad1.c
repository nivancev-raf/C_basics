#include <stdio.h>
#include <math.h>

double st(int i, int n, int s){
    int num = n*2 - i;
    return pow(num, s);
}

double f2_rek(int i, int n, double n1, int s){
    if (i == n)
        return sqrt(n1 / st(i, n, s));
    else    
        if (s == n / 2 + 1) s = 1;
        return sqrt(i % 2 == 1 ? st(i, n, s) / n1 + f2_rek(i + 1, n, n1 - 1, s + 1) 
        : n1 / st(i, n, s) + f2_rek(i + 1, n, n1 - 1, s + 1));
}


double f1_it(int n){
    double res = 0;
    int i = 1;
    int copy = n;
    double i2 = 1;
    int n1 = n;
    int s = n / 2;
    while(n){
        res = sqrt(i % 2 == 1 ? i2 / pow(n1, s) + res : pow(n1, s) / i2 + res);
        s--;
        if (s == 0) s = copy / 2; 
        n1++;
        i++;
        i2++;
        n--;
    }
    return res;
}

int main (){
    int n = 6;
    printf("rek:(%d) %lf\n", n, f2_rek(1, n, n, 1));
    printf("it:(%d) %lf\n", n, f1_it(n));

    return 0;
}