#include <stdio.h>
#include <math.h>

/*
1 (6p). Napisati funkciju int pom(int n) koja vraca kvadrat proizvoda
prve i poslednje cifre broja, i
dodatnu funkciju int obilan(int n) koja vraca 1 ukoliko je broj n obilan
broj, ili 0 ukoliko nije. Broj
n je obilan ako mu je zbir svih pravih delilaca strogo veci od n.
Korišcenjem napisanih funkcija ispisati sve
obilne brojeve iz intervala koji unosi korisnik
koji su manji od kvadrata proizvoda svoje prve i poslednje
cifre.
primer: 1 100
izlaz: 18 24 36 42 48 54 56 66 72 78 84 88 96
(objašnjenje: 18 je obilan broj jer mu je zbir pravih delilaca 1+2+3+6+9=21>18, a kvadrat proizvoda
njegove prve i poslednje cifre je (1*8)*(1*8)=64; slično i za ostale ispisane brojeve)
*/
int obilan(int n){
    int sum = 0;
    for (int i = 1; i < n; i++){
        if (n % i == 0) sum += i;
    }
    if (sum > n) return 1;
    else return 0;
}
int numofDegits(int a){
    int numDec = 0;
    while(a){
        a /= 10;
        numDec++;
    }
    return numDec;
}
int pom(int arg){
    int cifra1, cifra2, digit;
    int copy = arg;
    cifra1 = arg % 10;
    cifra2 = copy / pow(10, numofDegits(arg) - 1);
    return ((cifra1 * cifra2)*(cifra1 * cifra2));
}

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = n; i <= m; i++){
        if (obilan(i) == 1 && i < pom(i)){
            printf("%d ", i);
        }
    }

    return 0;
}