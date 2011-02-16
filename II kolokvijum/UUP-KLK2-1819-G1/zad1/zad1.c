#include <stdio.h>

#define MaxPrimeNum 10
int primeNumbers[MaxPrimeNum];
  

int levo(int n){
    char c = 'A';
    char c2;
    for (int i = 1; i < n; i++){
        c2 = c + i;
    }
    return c2;
}

void createArrayOfPrimeNumbers()
{
    int i = 0;
    primeNumbers[i++] = 2;
    int num = 3;
    while(1)
    {
        int prime = 1;
        for (int j = 2; j < num; j++)
        {
            if(num % j == 0){
                prime = 0;
                break;
            }
        }
        if(prime){
            primeNumbers[i++] = num;
            if(i == MaxPrimeNum){
                break;
            }
        }
        num++;
    }

}

int getPrimeNumber(int index)
{
    // return prime number from grobal 'primerNumbers' array
    return primeNumbers[index]; 
}


double f1_rek(int i, int n, int n1, int p){
    if (i == n)
        return levo(n1);
    else 
        return i % 2 == 1 ? levo(n1) + getPrimeNumber(p) / f1_rek(i + 1, n, n1 - 1, p + 1) : 
        levo(n1) - getPrimeNumber(p) / f1_rek(i + 1, n, n1 - 1, p + 1);
}


int main (){
    createArrayOfPrimeNumbers();
    int n = 7;
    printf("rek:(%d) %lf\n", n, f1_rek(1, n, n, 0));
    return 0;
}