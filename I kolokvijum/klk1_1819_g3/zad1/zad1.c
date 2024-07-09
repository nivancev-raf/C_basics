#include <stdio.h>
#include <math.h>

/*
1 (6p). Napisati funkciju int pom(int n) koja vraca kvadrat 
zbira prve i poslednje cifre broja, i
dodatnu funkciju int oskudan(int n) koja vraca 1 ukoliko je broj n 
oskudan broj, ili 0 ukoliko nije.
Broj n je oskudan ako mu je zbir svih pravih delilaca strogo manji od n.
Korišcenjem napisanih funkcija
ispisati sve oskudne brojeve iz intervala koji unosi korisnik koji su veci
od kvadrata zbira svoje prve i
poslednje cifre.
primer: 1 100
izlaz: 10 11 21 22 31 32 41 50 51 52 61 71
(objašnjenje: 10 je oskudan broj jer mu je zbir pravih delilaca 1+2+5=8<10,
a kvadrat zbira njegove prve i
poslednje cifre je (1+0)*(1+0)=1; slično i za ostale ispisane brojeve)
*/
int numofDecals(int a){
    int numDec = 0;
    while (a){
        a /= 10;
        numDec++;
    }
    return numDec;
}

int oskudan(int n){
    int sum = 0;
    for (int i = 1; i < n; i++){
        if (n % i == 0) sum += i;
    }
    //printf("sum: %d\n", sum);
    if (sum < n) return 1;
    else return 0;
}

int pom(int n){
    int cifra1, cifra2;
    
    cifra1 = n % 10;
    cifra2 = n / pow(10, numofDecals(n) - 1);
    return pow((cifra1+cifra2), 2);
}

int main (){
    int n, m;
    //printf("%d", pom(n));
    
    scanf("%d%d", &n, &m);
    for (int i = n; i <= m; i++){
        if (oskudan(i) == 1 && i > pom(i))
            printf("%d ", i);
    }    
    

    return 0;
}