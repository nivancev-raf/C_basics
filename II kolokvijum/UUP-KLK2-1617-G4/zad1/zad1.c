#include <stdio.h>


double f1_rek(int i, int n, int n1){
    if (i == n)
        return i;
    else 
        return i % 2 == 1 ? i + (n1*2) / f1_rek(i + 1, n, n1 - 1) : i - (n1*2) / f1_rek(i + 1, n, n1 - 1);
}

double f1_it(int n){
    double res = n;
    int i = n - 1;
    double n1 = 4;
    while (n > 1){
        res = i % 2 == 1 ? i + n1 / res : i - n1 / res;
        i--;
        n1 += 2;
        n--;
    }
    return res;
}

int main () {
    int n = 6;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, n));
    printf("it:(%d) %lf\n", n, f1_it(n));

    return 0;
}