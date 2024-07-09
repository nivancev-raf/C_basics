#include <stdio.h>
#include <math.h>
/*
Napisati funkciju pom(int arg) koja vrada najmanju razliku između susednih cifara argumenta
(pretpostavimo da argument uvek ima bar dve cifre). Zatim ispisati sve brojeve iz intervala
koji unosi korisnik a kojima je najmanja razlika između cifara veca od 5.
*/
int pom (int arg) {
    int digit1 = 0, digit2 = 0;
    int min = 10;
    while (arg > 9){
        digit1 = arg % 10;
        arg /= 10;
        digit2 = arg % 10;
        if (abs (digit1 - digit2) <= min){
            min = abs (digit1 - digit2);
        }
    }
    return min;
}

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = n; i <= m; i++){
        if (pom(i) > 5){
            printf("%d ", i);
        }
    }
    return 0;
}