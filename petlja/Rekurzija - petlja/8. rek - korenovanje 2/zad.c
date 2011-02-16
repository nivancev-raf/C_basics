#include <stdio.h>
#include <math.h>

// https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/08_korenje_2

double f4(int i, int n){
    if (i == n)
        return sqrt(n);
    else    
        return sqrt(i + f4(i+1, n));

}

double f4_i(int n){
    int i = n;
    double res = 0;
    while (i){
        res = sqrt(i + res);
        i--;
    }
    return res;
}

int main () {
    int n = 10;
    printf("rek:(%d) %lf\n", n, f4(1, n));
    printf("it:(%d) %lf\n", n, f4_i(n));

    return 0;

}