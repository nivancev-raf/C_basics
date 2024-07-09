#include <stdio.h>

int main () {
    int n = 5;
    int prvi = 1, drugi = 1, zbir = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1){
                printf("%d\t", prvi);
                zbir = prvi + drugi;
                prvi = drugi;
                drugi = zbir;
            }else {
                printf("0\t");
            }
        }
        printf("\n");
    }

    return 0;
}