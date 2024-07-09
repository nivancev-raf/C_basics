#include <stdio.h>
#include <math.h>

/*
1 (6p). Napisati funkciju int pom(int arg) koja vraca
broj koji se dobije kada se iz argumenta izbaci
njegova najveca cifra (ako ima više jednakih najvecih
cifara izbaciju se sve). Zatim napisati program u
kome korisnik unosi brojeve, a ispisuje se razlika unetog broja i 
broja koji se dobije kada se iz unetog
broja izbaci najveca cifra. Program se završava kada korisnik unese 0.
*/

int pom (int arg){
    int max = 0;
    int copy;
    copy = arg;
    while (arg){
        int digit = arg % 10;
        arg /= 10;
            if (abs (digit - max) >= max){
                max = digit;
            }
    }
    int new_num = 0, p = 1;
    while (copy){
        int digit = copy % 10;
        copy /= 10;
            if (digit != max){
                new_num += digit*p;
                p *= 10;
            }
    }
    return new_num;
}


int main () {
    int n;
    while (1){
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d ", n - pom(n));
    }

    return 0;
}