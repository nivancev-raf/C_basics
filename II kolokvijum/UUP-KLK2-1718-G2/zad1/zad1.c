#include <stdio.h>

double f1_rek(int i, double i2, int n, double n2, double n3){
    if (i == n)
        return i % 2 == 0 ? i2 : n2;
    else 
        return i % 2 == 1 ? n2 + (n3*2) / f1_rek(i + 1, i2 + 0.5, n , n2 - 0.5, n3 - 1) :
        i2 + (n3*2) / f1_rek(i + 1, i2 + 0.5, n , n2 - 0.5, n3 - 1);
}


double f1_it(int n){
    double res = (n % 2 == 0 ? n/2 : n/2 + 1);
    double brojilac = 4;
    double br_plus = res + 1, br_minus = res;
    while (n > 1){
        res = (n % 2 == 0 ? br_plus + brojilac/res : br_minus + brojilac/res);
        if (n % 2 == 1) br_plus++;
        else br_minus--;
        brojilac += 2;
        n--;
    } 
    return res;
}


int main (){
    int n = 6;
    printf("rek:(%d) %lf\n", n, f1_rek(1, 0.5, n, n, n));
    printf("it:(%d) %lf\n", n, f1_it(n));

    return 0;
}