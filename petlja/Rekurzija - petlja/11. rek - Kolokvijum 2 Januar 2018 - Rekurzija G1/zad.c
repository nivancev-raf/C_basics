#include <stdio.h>
#include <math.h>

// https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/11_drugiKolokvijum2018PrviZadatakPrvaGrupa

int brojilac(int a){
    return a*10 + 1;
}

double f1(int i, int n, int k, double br){
    
    if (i == n)
        return sqrt(i % 2 == 0 ? (1.00 / (2*n - k)) : br / (2*n - k));
    else     
        return sqrt((i % 2 == 1 ? (br / (2*n - k)) : (1.00 / (2*n - k))) + f1(i + 1, n, k + 2, br - 4.5));
}

int brojilac_it(int a, double i){
    return a*10 + 1 - 9*i;
}

double f1_it(int n){
    double res = 0, p = 0;
    int i = 1;
    int copy = n;
    while (n){
        res = sqrt((i % 2 == 1 ? (1.00) / (p + 2) : brojilac_it(copy, n/2) / (p + 2)) + res);
        p += 2;
        i++;
        n--;
    }
    return res;
}


int main (){
    int n = 6;
    int p = brojilac(n);
    printf("rek:(%d) %lf\n", n, f1(1, n, 0, p));
    printf("it:(%d) %lf\n", n, f1_it(n));
    



    return 0;
}