#include <stdio.h>
#include <string.h>

/**
2. (13p) Napisati program koji od dva data stringa P i S pravi treći tako što sve
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

int main() {
    char p[] = "(dfhhj)fg(adbjbdnc)agh(haj)gh(akjh)";
    char s[] = "dhj";
    int u_zagradi = 0;
    int start, end;
    int p_index[100] = {0};
    for (int pi = 0; p[pi]; pi++){
        if (u_zagradi){
            if (p[pi] == ')'){
                u_zagradi = 0;
            }else{
                for (int si = 0; s[si]; si++){
                    if (s[si] == p[pi]){
                        p_index[pi] = si + 1;
                        break;
                    }
                }
            }
        }else{
            if(p[pi] == '('){
                u_zagradi = 1;
            }
        }
    }


    return 0;
}