#include <stdio.h>
#include <math.h>

// https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/07_korenje_1

double f3(int n){
    if (n == 1)
        return 1;
    else
        return sqrt(n + f3(n - 1));

}

double f3_i(int n){
    int i = 1;
    double res = 0;
    while (i <= n){
        res = sqrt(i + res);
        i++;
    }
    
    return res;
}

int main () {
    int n = 5;
    printf("rek:(%d) %lf\n", n, f3(n));
    printf("it:(%d) %lf\n", n, f3_i(n));
    return 0;

}