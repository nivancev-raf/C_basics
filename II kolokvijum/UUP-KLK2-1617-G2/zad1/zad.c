#include <stdio.h>
#include <math.h>

double f1_rek(int i, int n, int n1){
    if (i == n)
        return 1;
    else 
        return n1 + sqrt(i % 2 == 0 ? 2 : 1) / f1_rek(i + 1, n, n1 - 1);
}

double f1_it(int n){
    double res = 1;
    int i = 2;
    while (n > 1){
        res = i + sqrt(i % 2 == 0 ? 1 : 2) / res;
        i++;
        n--;
    }
    return res;
}

int main (){
    int n = 6;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, n));
    printf("it:(%d) %lf\n", n, f1_it(n));
    return 0; 
}