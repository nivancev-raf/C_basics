#include <stdio.h>
#include <math.h>

/*
(6p) Napisati funkciju int sumaSimetricnih(int n) koja proverava da li za zadati broj n važi
da mu je suma svim simetričnih cifara (prve i poslednje, druge i pretposlednje,...)
jednaka broju cifara.
Na primer, za sledeće brojeve važi traženi uslov: 1, 11, 132, 3221, 2132
Ispisati sve brojeve iz intervala koje unosi korisnik takve da važi da im je zbir simetričnih
cifara jednak broju cifara, na primer za interval 10 i 350 treba ispisati:
11, 20, 132, 231, 330
*/

int numofDegits(int a){
    int numDec = 0;
    while (a){
        a /= 10;
        numDec++;
    }
    return numDec;
}

int sumaSimetricnih(int n){
    int digit1 = 0, digit2 = 0;
    int copy = n;
    int copy2 = n;
    if (numofDegits(copy2) == 2){
        digit1 = copy2 % 10;
        copy2 /= 10;
        digit2 = copy2;
        if (digit2 + digit1 == numofDegits(n)) return copy;
        else return 0;
    }
        while(n){
            digit1 = n % 10;
            n /= 10;
            digit2 = n / pow (10, numofDegits(n) - 1);
            n = n % 10;
            if (digit1 + digit2 == numofDegits(copy)) continue;
            else  return 0;
        }
    
    return copy;
}

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = n; i <= m; i++){
    if (sumaSimetricnih(i))
    printf("%d ", sumaSimetricnih(i));
    }
    return 0;
}