#include <stdio.h>
#include <math.h>


double f1_rek(int i, int n, double n1, double b, double n2){
    if (i == n)
        return sqrt(i % 2 == 0 ? n2 / (b*2.00) : n1 / (b*2.00));
    else
        return sqrt(i % 2 == 1 ? n1 / (b*2.00) + f1_rek(i+1, n, n1 - 0.5, b - 1, n2 + 0.5) :
        n2 / (b*2.00) + f1_rek(i+1, n, n1 - 0.5, b - 1, n2 + 0.5));
}

double f1_it(int n){
    int copy = n;
    double res = 0;
    double i = 2;
    double b1 = n / 2;
    double b2 = n/2 + 0.5;
    if (n % 2 == 1){
        b2 = n/2 + 1;
        b1 = n / 2 + 0.5;
    }
    while(n){
        if (copy % 2 == 0){
            res = sqrt(n % 2 == 0 ? b1 / i + res : b2 / i + res);
        }else{
            res = sqrt(n % 2 == 1 ? b2 / i + res : b1 / i + res);
        }
        b1 -= 0.5;
        b2 += 0.5;
        i += 2;
        n--;
    }
    return res;
}

int main (){
    int n = 6;
    printf("rek(%d) %lf\n", n, f1_rek(1, n, n, n, 0.5));
    printf("it(%d) %lf\n", n, f1_it(n));

    return 0;
}