#include <stdio.h>

/*
1 (6p). Napisati funkciju int pom(int arg) koja vraca broj 
koji se dobije kada se iz argumenta arg
izbace sve proste cifre. Za određivanje
da li je cifra prosta napisati dodatnu funkciju int prost(int
n) koja vraca 1 ukoliko je broj n prost, ili 0 ukoliko je n
složen broj. Zatim korišcenjem funkcije pom
ispisati sve brojeve iz intervala koji unosi korisnik koji imaju 
sve proste cifre. Napomena: 0 i 1 se ne
ubrajaju u proste brojeve!
primer: 1 100
izlaz: 2 3 5 7 22 23 25 27 32 33 35 37 52 53 55 57 72 73 75 77
*/

int prost(int arg){
    if (arg == 1) return 0;
    if (arg == 2) return 1;
    for (int j = 2; j < arg; j++){
        if (arg % j == 0) return 0;
       }
    return 1;
}

int pom (int arg){
    int new_num = 0, p = 1;
    while (arg){
        int digit = arg % 10;
        arg /= 10;
            if (prost(digit) == 1){
                continue;
            }else{
                new_num += digit*p; 
                p *= 10;
            }
            
    }
    return new_num;
}


int main () {
    int n, m, res;
    scanf("%d%d", &n, &m);
    for (int i = n; i <= m; i++){
        res = pom(i);
        if (res == 0) printf("%d ", i);
    }
    
    return 0;
}


/*
printf("%d", pom(n));
    for (int i = n; i <= m; i++){
        int res = pom(i);
        if (res != 0)
        printf("%d ", pom(i));
    }
*/