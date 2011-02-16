#include <stdio.h>
/*
2. Koristedi naredbu
while i funkciju getchar() za čitanje karaktera obraditi ulaznu sekvencu slova
tako da se izbroji broj susednih pojavljivanja slova
(broje se i mala i velika slova kao jednaka) i ispiše
na slededi način:
primer: AAababbBBCc
rezultat: 3a1b1a4b2c
*/
int bigLetter(char a){
    if (a >= 'A' && a <= 'Z'){
        return a;
    }else{
        return a - 32;
    }
}

int main () {
    char c;
    char prev = getchar ();
    int counter = 1;
    while ((c = getchar()) != '\n'){
        c = bigLetter(c);
            if (c == prev) counter++;
            else{
                printf("%d%c", counter, prev + 32);
                counter = 1;
            }
        prev = c;
    }
     printf("%d%c", counter, prev + 32);

    return 0;
}