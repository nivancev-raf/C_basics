#include <stdio.h>
#include <math.h>

// iterativno broj levo

int brojilac(int n){
    return n*10 + (n-1);
}


double f1_rek(int i, int n, int n1, double n2){
    if (i == n)
        return sqrt(brojilac(n1) / n2);
    else
        return sqrt(brojilac(n1) / n2 + f1_rek(i + 1, n, n1 - 1, n2 += i));
}

double levo(int n){
    int sum = 0, i = 0;
    while (i <= n){
        sum += i;
        i++;
    }
    return sum;
}

double f1_it(int n){
    double res = 0;
    int i = 1;
    double p = levo(n);
    while (n){
        res = sqrt(i == 1 ? ((brojilac(i) / (p)) + res) : ((brojilac(i) / (p - n)) + res));
        if (i != 1) p -= n;
        i++;
        n--;
    }
    return res;
}

int main (){
    int n = 6;
    printf("rek(%d): %lf\n", n, f1_rek(1, n, n, n));
    printf("it(%d): %lf\n", n, f1_it(n));
    //printf("%d", levo(n));
    return 0;
}