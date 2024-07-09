#include <stdio.h>
/*
1. Napisati funkciju pom(int arg, int k) koja vraca broj dobijen kada se 
iz argumenta arg uklone sve
cifre manje od k (vratiti nula ako se izbace sve cifre). Sabrati brojeve koje
vraca ova funkcija za 3
broja koja korisnik unese, i za k=5.
*/
int pom (int arg, int k){
    int digit, new_num = 0;
    int copy, p = 1;
    copy = arg;
    while (arg){
        digit = arg % 10;
        arg /= 10;
        if (digit < k){
            continue;
        }else{
            new_num += digit*p;
            p*=10;
        }

    }
    return new_num;
}

int main (){
    int a, b, c, k = 5;
    int sum = 0;
    scanf("%d%d%d", &a, &b, &c);
    int a1, b1, c1;
    a1 = pom(a, k);
    b1 = pom(b, k);
    c1 = pom(c, k);
    sum = a1 + b1 + c1;
    printf("%d", sum);
    return 0;

}