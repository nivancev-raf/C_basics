#include <stdio.h>
// 1 1 2 3 5 8 13 21 
// https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/04_dec2bin

int fibonaci(int a){
    if (a == 1 || a == 2)
        return 1;
    else
        return fibonaci(a - 1) + fibonaci(a - 2);
} 

int fibonaciit(int a){
    int prev1 = 1, prev2 = 1, fib = 0;
    if (a == 1 || a == 2)
        return 1;
    while (a - 2 > 0){
        fib = prev1 + prev2;
        prev1 = prev2;
        prev2 = fib;
        a--;
    }
    return fib;
}

int main (){
    int n = 7;
    printf("it: %d\nrek: %d\n", fibonaciit(n), fibonaci(n));


    return 0;
}