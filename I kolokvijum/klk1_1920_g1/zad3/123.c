#include <stdio.h>

/**
UUP-KLK1-1920-G1-Z3
3. (7p) Nacrtati sledeću figuru za unetu visinu n (n>2):
 n=3       n=5          n=6             n=7
  %         %            %%              %
 ***       ***          ****            ***
@***@     @***@        @****@          @***@
  |      *******      ********        *******
        %*******%    %********%      %*******%
            |       ************    ***********
            |            ||        @***********@
                         ||              |
                         ||              |
                                         |
*/

int main() {
    int n;
    scanf("%d", &n);

    /// Imamo n redova.
    for(int i = 1; i <= n; i++) {
        /// I lako se izračuna da imamo n-i spejsova pre piramide.
        for(int j = 1; j <= n-i; j++)
            putchar(' ');

        /// U odnosu na parnost broja n, u prvom redu imam 1 ili 2 karaktera.
        int k;
        if (n % 2 == 1)
            k = 2 * i - 1;
        else
            k = 2 * i;
        /// j predstavlja broj kolona a u svakom redu ima k kolona.
        for(int j = 1; j <= k; j++) {
            /// Ako je prva ili poslednja kolona ispisivaćemo @, *, ili % u odnosu na deljivost reda.
            if (j == 1 || j == k)
                putchar((i % 4 == 1) ? '%' : ((i % 4 == 3) ? '@' : '*'));
            /// A inače svakako ispisujemo zvezdicu.
            else putchar('*');
        }
        putchar('\n');
    }

    /// Na kraju samo ispišemo spejsove i uspravne linije.
    for(int i = 1; i <= n/2; i++) {
        for(int j = 1; j < n; j++)
            putchar(' ');
        for (int j = 1; j <= 2-n%2; j++)
            putchar('|');
        putchar('\n');
    }
    return 0;
}