#include <stdio.h>


#define MAX 10
int array[MAX];

double levo(int n){
    char c = 'A';
    double c2;
    for (int i = 1; i < n; i++){
        c2 = c + i;
    }
    return c2;
}

void createarray()
{

    // 2 3 5 7 11 13
    array[0] = 2;
    int j = 1;
    int num = 3;
    while (1){
        int prost = 1;
        for (int i = 2; i < num; i++){
            if (num % i == 0){
                prost = 0;
                break;
            }
        }
            if (prost){
                array[j++] = num;
            }
            if (j == MAX) break;
        num++;
    }
}

double uzmi_prost(int n){
    return array[n];
}


double f1_rek(int i, int n, int n1, int p){
    if (i == n)
        return levo(n1);
    else 
        return i % 2 == 1 ? levo(n1) + uzmi_prost(p) / f1_rek(i + 1, n, n1 - 1, p + 1) : 
        levo(n1) - uzmi_prost(p) / f1_rek(i + 1, n, n1 - 1, p + 1);
}

double f1_it(int n){
    int i = 1;
    double res = levo(i);
    i++;
    while (n > 1){
        res = i % 2 == 0 ? levo(i) - uzmi_prost(n-2) / res : levo(i) + uzmi_prost(n-2) / res;
        i++;
        n--;
    }
    return res;
}

int main (){
    createarray();
    int n = 7;   
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, n, 0));
    printf("it:(%d) %lf\n", n, f1_it(n));
    //printf("%c", levo(n));
    return 0;
} 