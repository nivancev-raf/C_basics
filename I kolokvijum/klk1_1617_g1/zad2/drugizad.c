#include <stdio.h>
#include <stdlib.h>
/*
Koristedi naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu karaktera
koja počinje brojem a sastoji se od brojeva i znakova + i -, tako da se izračuna i ispiše rezultat
aritmetičkih operacija sabiranja i oduzimanja koje se izvršavaju redom.
primer: 10+13-12+25-5+100
rezultat: 131
*/

int main () {

    int n = 0, sum = 0;
    char c, prev = '+';
    while ((c = getchar()) != '\n'){
        if (c >= '0' && c <= '9'){
            int digit = c - '0';
            n = n * 10 + digit;
        }
        else if (prev == '+'){
            sum += n;
            n = 0;
            prev = c;
        }
        else{
            sum -= n;
            n = 0;
            prev = c;
        }
    }
        if (prev == '+'){
            sum += n;
        }
        else{
            sum -= n;
        }

    printf("%d", sum);

    return 0;
}
