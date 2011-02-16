/*
Napisati program koji od dva data stringa P i S pravi treći tako što sve
podstringove stringa P koji se nalaze u zagradi prepisuje u treći string samo ako sadrže
bar dva karaktera koja se nalaze u S i svi karakteri u zagradi koji se nalaze i u S su
pojavljuju u istom redosledu kao karakteri u strigu S. String S sadrži sve različite
karaktere. Podstring u zagradi može da sadrži i karaktere kojih nema u S ili da se
karakteri ponavljaju, bitno je da redosled za sve karaktere bude isti kao u S. Ostali
karakteri, izvan zagrada i u zagradi za koje ne važi pravilo ne pripisuju se u rezultujući
string.
Primer
Unos: P: (dfhhj)fg(adbjbdnc)agh(haj)gh(akjh) S: dhj
Ispis: dfhhj haj

*/

#include <stdio.h>
#include <string.h>

int main()
{
    char *p = "(dfhhj)fg(adbjbdnc)agh(haj)gh(akjh)";
    char *ref = "dhj";
    char rez[100];
    int  s = 0, e = 0, t = 0;
    for (int i = 0; i < strlen(p); i++)
    {
        if(p[i] == '(')
            s = i + 1;
        if(p[i] == ')')
            e = i;
        
        if(s != 0 && e != 0){
            int numOccurence = 0;
            int subStringInd = s;
            int subStringIsValid = 0;
            for (int k = 0; k < strlen(ref); k++){
                int j;
                for (j = subStringInd; j < e; j++){
                    if(p[j] == ref[k]){
                        numOccurence++;
                        subStringInd = j;
                        break;
                    }
                }
                
                if(numOccurence > 0 && j == e ){
                    // sub-string is not a candidate
                    break;
                }
                else if(numOccurence == 2){
                    subStringIsValid = 1;
                    break;
                }
            }

            // copy valid sub-string to rez array
            if(subStringIsValid){
                for (int j = s; j < e; j++){
                    rez[t++] = p[j];
                }
                rez[t++] = ' ';
            }

            s = e = 0;
        }
    }

    rez[t] = 0;

    // print rez
    printf("%s", rez);
}