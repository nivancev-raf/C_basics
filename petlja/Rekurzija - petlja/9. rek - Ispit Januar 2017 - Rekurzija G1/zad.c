#include <stdio.h>

// https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/09_ispit_jan17_1

int broj_levo(int i)
{
    int sum = 1,j;
    for (j = 1 ; j < i ; j++)
        sum += j;
    return sum;
}

double rek(int n, int i){
    if (i == n)
        return broj_levo(i);
    else 
        return broj_levo(i) + (2*n-i+1) / rek(n, i + 1);

}

double it (int n){
    int i = n - 1;
    double res = broj_levo(n);
    while (i >= 1){
        res = broj_levo(i) + (2*n-i+1)/res;
        i--;
    }
    return res;
}

int main () {
    int n = 6;
    printf("rek:(%d) %lf\n", n, rek(n, 1));
    printf("it:(%d) %lf\n", n, it(n));
    return 0;
}
