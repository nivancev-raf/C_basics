#include <stdio.h>

/*
2 (7p). Koristeci naredbu while i funkciju getchar() za 
čitanje karaktera iz ulazne sekvence karaktera
koja se sastoji od slova i cifara, izračunati zbir svih brojeva koji sadrže cifru 2 ili 5.
primer: ab123de3000f4g567hh rezultat: 690
(objašnjenje: brojevi koji sadrže cifru 2 ili 5 su 123 i 567, u zbiru su 690)
*/

int main (){

    int n = 0, sum = 0;
    int flag = 0;
    char c;
    while ((c = getchar()) != '\n'){
        if (c >= '0' && c <= '9'){
            int digit = c - '0';
            n = n * 10 + digit;
            if (digit == 2 || digit == 5) flag = 1;
            continue;
        }
        if (flag == 1){
            sum += n;
            n = 0;
            flag = 0;
        }
        n = 0;
    }
    printf("%d", sum);

    return 0;
}