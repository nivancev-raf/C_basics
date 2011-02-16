#include <stdio.h>

int brojilac(int n){
    return n*10 + (n-1);
}

double f1_rek(int i, int n, int n1, int n2){
    if (i == n)
        return n1;
    else 
        return n1 + brojilac(n2) / f1_rek(i + 1, n, n1 += i, n2 - 1);
}
// n1 += i; -> levi broj
// n2 - 1; -> za brojilac

int levo(int n){
    int sum = 0;
    for (int i = 0; i <= n; i++){
        sum += i;
    }
    return sum;
}

double f1_it(int n){
    double res = levo(n);
    int i = 2;
    double p = res - n + 1;
    n -= 1;
    while (n){
        res = p + brojilac(i) / res;
        i++;
        n--;
        p -= n;
    }
    return res;
}

int main (){
    int n = 6;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, n, n));
    printf("it:(%d) %lf\n", n, f1_it(n));
    
    return 0;
}