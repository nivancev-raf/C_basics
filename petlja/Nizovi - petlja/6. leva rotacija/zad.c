#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/06_leva_rotacija

Ulaz
5 3
1 2 3 4 5
Izlaz
4 5 1 2 3
Proces 3 rotacije:
12345
23451
34512
45123
*/

int main (){
    int n;
    scanf("%d", &n);
    int left_r;
    scanf("%d", &left_r);
    int array[n], tmp;
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    /*
    for (int i = 1; i < left_r; i++){
        for (int j = i + 1; j < n; j++){
            tmp = array[0];
            array[i] = array[j];
            array[n - 1] = tmp;
        }
    }
    */

    for (left_r; left_r >= 1; left_r--){
        tmp = array[0];
        for (int i = 0; i < n - 1; i++){
            array[i] = array[i + 1];
        }
            array[n - 1] = tmp;
        }

    for (int i = 0; i < n; i++){
        printf("%d", array[i]);
    }

    return 0;
}
