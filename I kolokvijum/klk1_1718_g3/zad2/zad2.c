#include <stdio.h>

/*
2 (7p). Koristeci naredbu while i funkcije getchar() i putchar()
obraditi ulaznu sekvencu karaktera koja
se sastoji od cifara i zagrada tako što se izraz u
ugnježdenoj zagradi zamenjuje zbirom cifara koje se
nalaze u toj ugnježdenoj zagradi, a svi ostali karakteri se 
prepisuju. Pretpostavlja se da su zagrade
pravilno otvorene i zatvorene i da može biti samo jedan nivo ugnježdenosti.
primer: 34(78)67(56(34)56)(34(456))
rezultat: 34(78)67(56756)(3415)
*/
int zbirCifara (int a){
    int digit = 0, sum = 0;
    while(a){
        digit = a % 10;
        a /= 10;
        sum += digit;
    }
    return sum;
}

int main (){
    int n = 0, brojac = 0;
    char c, prev = ' ';
    while ((c = getchar()) != '\n'){
        if (c == '(') brojac++;
        if (brojac == 2){
            if (c >= '0' && c <= '9'){
                n = n * 10 + c - '0';
                continue;
            }
        }
        if (c == ')' && brojac == 2){
            printf("%d", zbirCifara(n));
            n = 0;
        }else if (brojac == 2 && c == '(') continue;
        else{
            putchar(c);
        }
        if (c == ')') brojac--;
        


    }

    return 0;
}
