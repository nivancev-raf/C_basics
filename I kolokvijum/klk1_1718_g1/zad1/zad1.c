#include <stdio.h>
/*
1(6p). Napisati funkciju int pom(int arg, int delilac) koja vraca broj 
koji se dobije kada se iz argumenta
arg izbace sve cifre koji nisu deljive argumentom delilac 
(delilac је u opsegu [2,9]). Zatim korišcenjem
funkcije pom ispisati sve brojeve iz intervala koji unosi korisnik 
kojima su cve cifre deljive sa 3.
*/

int pom (int arg, int delilac){
    int digit, new_num = 0, p = 1;

    while (arg){
        digit = arg % 10;
        arg /= 10;
            if (digit % delilac == 0){
                new_num += digit * p;
                p *= 10;
            }
    }
    return new_num;
}
int main () {
    int n, m; 
    scanf("%d%d", &n, &m);
    for (int i = n; i <= m; i++){
        if (pom(i, 3) >= n){
            printf("%d ", pom(i, 3));
        }
    }
    return 0;
}