#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Napisati funkciju pom(int arg) koja vraca najvecu razliku između susednih cifara argumenta
(pretpostavimo da argument uvek ima bar dve cifre). Zatim ispisati sve brojeve iz intervala koji unosi
korisnik a kojima je najveca razlika između cifara manja od 3.
*/

int pom (int arg){
    int digit1, digit2;
    int max = -1;
    while (arg > 9){
        digit1 = arg % 10;
        arg /= 10;
        digit2 = arg % 10;
            if (abs(digit1 - digit2) >= max)
                max = abs(digit1 - digit2);
    }
    return max;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = n; i <= m; i++){
        if (pom(i) < 3){
            printf("%d ", i);
        }
    }
    return 0;
}
