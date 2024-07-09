#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/07_palindromski_podniz

Ulaz
7
3 1 5 1 5 1 9 7 4
Izlaz
1 5 1 5 1
*/

int main (){

    int a[] = {3, 1, 5, 1, 5, 1, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int s = 0, e = n - 1;
    int h = s, t = e;
    int flag = 0;
    while (h < n - 1){
        if (a[h] == a[t]){
            if(flag == 0){
                s = h;
                e = t;
            }
            t--;
            h++;
            flag = 1;
        }
        if (h == t){
            
        }

        else{
            flag = 0;
        }
    }
    
   
   return 0;
}