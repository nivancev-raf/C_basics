#include <stdio.h>
#include <math.h>

/*
1. (6 poena) Napisati dve funkcije koje izračunavaju sledeći koren, jedna iterativno a druga
rekurzivno za dato n. U primeru je n=6;
*/

double f3_rek(int i){
    if (i == 1)
        return sqrt(i % 2 == 0 ? 1 : 2);
    else 
        return sqrt(((i % 2 == 0 ? 1 : 2) / (i*1.0)) + f3_rek(i - 1));
}


double f3_it(int n){
    double res = 0;
    int i = 1;
    while (i <= n){
        res = sqrt((i % 2 == 0 ? 1 : 2) / (i*1.0) + res);
        i++;
    }
    return res;
}

int main (){
    int n = 6;
    printf("rek:(%d) = %lf\n", n, f3_rek(n));
    printf("it:(%d) = %lf\n", n, f3_it(n));

    return 0;
}
