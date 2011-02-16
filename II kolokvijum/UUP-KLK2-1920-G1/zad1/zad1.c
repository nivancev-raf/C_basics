#include <stdio.h>
#include <math.h>

double imenilac(int n){
    return pow(n,2);
}

double f1_rek(int i, int n, double n1, double n2, double b1, double b2){
    if (i == n)
        return i % 2 == 0 ? sqrt(n2 / imenilac(b2)) : sqrt(n1 / imenilac(b1));
    else
        return i % 2 == 1 ? sqrt(n1 / imenilac(b1) + f1_rek(i+1, n, n1+0.5, n2-0.5, b1-0.5, b2+0.5)) : 
        sqrt(n2 / imenilac(b2) + f1_rek(i+1, n, n1+0.5, n2-0.5, b1-0.5, b2+0.5));  
}

// n1 krece od 1, povecava se za 0.5 (1,  ,2,   3, )
// ako je i paran n2 koji krece od n+0.5 i smanjuje se za 0.5 ( 6,   5,   4,  )
// b1 krece od 6 i smanjuje se za 0.5
// zavrsiti


double f1_it(int n){
    double res = 0;
    int i = 1;
    double b1 = n - 2;
    double b2 = n / 2 + 0.5;
    double im2 = n - 2 + 0.5;
    double im1 = n / 2;
    int copy = n;
    while(n){
        if (copy % 2 == 0){
            res = sqrt((i % 2 == 1 ? b1 / imenilac(im1) + res : b2 / imenilac(im2) + res));
        }
        im2 += 0.5;
        b1 += 0.5;
        b2 -= 0.5;
        im1 -= 0.5;
        i++;
        n--;
    }
    return res;
}

int main (){
    int n = 6;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, 1, n + 0.5, n, 0.5));
    printf("it:(%d) %lf\n", n, f1_it(n));


    return 0;
}