#include <stdio.h>

/*

https://petlja.org/sr-Latn-RS/biblioteka/r/problemi/uvod-u-programiranje/08_kolokvijum2018_zadatak2_grupa1

Drugi kolokvijum 2018 zadatak 2 grupa 1:
Ulaz
45901
Izlaz
2 2 3 3 4
3 4 4 5 5
8 8 9 9 0
9 0 0 1 1
1 1 2 2 3
*/

int numofDecals (int a){
    int numofDegits = 0;
    while (a){
        a /= 10;
        numofDegits++;
    }
    return numofDegits;
}

/*
* This function takes a number as an argument and create 
* vector of its decimals
* Example: 45901 -> {4, 5, 9, 0, 1}
* parameters:
* int a     - input number
* int *out  - output array
*/
void createVectorOfNumber (int a, int out[]){
    int n = numofDecals(a);
    int j = n - 1;
    while (a){
        out[j--] = a % 10;
        a /= 10; 
    }
}

int digit (int a){
    return a % 10;
}

int main (){
    int n = 45901;
    //scanf("%d", &n);
    int a = numofDecals(n);
    //int nums[a];
    //createVectorOfNumber(n, nums);
    int mat[a][a];

    int array[] = {1, 2, 3, 4, 5};
    int k2 = array[2];
    int k3 = *array;
    k3 = *(array + 0);
    k3 = array[0];

    // zero-ed matrix
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            //mat[i][j] = 0;
            *(*(mat + i) + j) = 0;
        }
    }

    int d = 0;
    for (int i = a - 1; i >= 0; i--){
        //mat[i][d++] = nums[i];
        mat[i][d++] = n % 10;
        n /= 10; 
    }

    // print the matrix 
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }   


    return 0;    
}