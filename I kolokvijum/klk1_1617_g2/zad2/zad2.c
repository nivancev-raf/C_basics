#include <stdio.h>
/*
Koristedi naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu karaktera
koja počinje brojem, a sastoji se od brojeva i znakova * i /, tako da se izračuna i ispiše rezultat
aritmetičkih operacija množenja i celobrojnog deljenja koje se izvršavaju redom.
primer: 25/5*10*2/25
rezultat: 4
*/

int main () {
    int n, sum = 0;
    char c, prev = '+';
    while ((c = getchar()) != '\n'){
        if (c >= '0' && c <= '9'){
            n = n * 10 + c - '0';
        }
        if (c == '/' && prev == '+'){
            sum = n;
            n = 0;
            prev = c;
        }
        else if (prev == '/' && !(c >= '0' && c <= '9')){
            sum /= n;
            n = 0;
            prev = c;
        }
        else if (prev == '*' && !(c >= '0' && c <= '9')){
            sum *= n;
            n = 0;
            prev = c;
        }
        
    }
         if (prev == '/' && !(c >= '0' && c <= '9')){
            sum /= n;
        }
         if (prev == '*' && !(c >= '0' && c <= '9')){
            sum *= n;
        }
    printf("%d", sum);
    return 0;
}