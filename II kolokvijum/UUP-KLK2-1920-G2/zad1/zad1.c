#include <stdio.h>

// veoma malo fali da bude 100% tacno

double faktorijel(double n){
    double sum = 1;
    for (int i = n; i > 0; i--){
        sum *= i;
    }
    return sum;
}

double f1_rek(int i, int n, double l1, double l2, double b1, double b2){
    if (i == n)
        return i % 2 == 0 ? l2 + faktorijel(b2) : l1 + faktorijel(b1);
    else
        return i % 2 == 1 ? l1 + faktorijel(b1) / f1_rek(i + 1, n, l1 + 0.5, l2 - 0.5, b1 - 0.5, b2 + 0.5) : 
        l2 + faktorijel(b2) / f1_rek(i + 1, n, l1 + 0.5, l2 - 0.5, b1 - 0.5, b2 + 0.5);

}

double f1_it(int n){
    int l1, l2, b1, b2;
    if (n % 2 == 0)
    {
        l1 = n / 2; // l1 - 0.5
        b1 = n - 2; // b2 + 0.5
        l2 = n - 2; // l2 + 1
        b2 = n / 2; // b2 - 0.5
    }
    else
    {
        l1 = n / 2; 
        b1 = n - 2; 
        l2 = n - 2; 
        b2 = n / 2;
    }
    double res = l2 + faktorijel(b2);
    if (n % 2 == 0) {
        l2++;
        b2--;
        }
    
    while (n > 1){
        
        if (n % 2 == 0){
            res = l1 + faktorijel(b1) / res;
            l1--;
            b1++;
        }
        else
        {
            res = l2 + faktorijel(b2) / res;
            b2--;
            l2++;
        }

        n--;
    }
    return res;
}

int main (){
    int n = 7;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, 1, n + 0.5, n, 0.5));
    printf("it:(%d) %lf\n", n, f1_it(n));
    //printf("%lf", faktorijel(n));

    return 0;
}
/*
#include <stdio.h>

double faktorijel(int n){
    if (n == 1) return 1;
    return n * faktorijel(n-1);
}

double levo(int i, int n){
    if (i == 1) return 1;
    if (i % 2 == 1)
        return n / i; 
}

double f1_rek(int i, int n){
    if (i == n)
        return n;
    else
        return 

}

int main (){
    int n = 6;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n));
    //printf("%d", faktorijel(n));

    return 0;
}
*/