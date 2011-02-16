#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/02_sortirati

Ulaz
5
5 1 2 8 3
Izlaz
1 2 3 5 8
*/

int main () {
    int n, temp;
    printf("Enter the number of characters in array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the numbers in array: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
        //printf("number in array (%d) is %d\n", i, array[i]);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    printf("Sorted array of (%d) characters is:\n", n);
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }


    return 0;
}
