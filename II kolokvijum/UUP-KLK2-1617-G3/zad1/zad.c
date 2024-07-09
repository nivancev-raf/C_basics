#include <stdio.h>
#include <math.h>

double f1_rek (int i, int n, int n1){
    if (i == n)
        return sqrt(i);
    else

        return sqrt(i * ((i == n / 2 + 1) ? n1 = n / 2 : n1) + f1_rek(i+1, n, n1 - 1));
}

double f1_it(int n){
    double res = 0;
    int i = 1, copy = n;
    while (n){
        i == copy / 2 + 1 ? i = 1 : i;  
        res = sqrt(n*i + res);
        i++;
        n--;
    }
    return res;
}

int main (){
    int n = 6;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, n/2));
    printf("it:(%d) %lf\n", n, f1_it(n));

    return 0;
}