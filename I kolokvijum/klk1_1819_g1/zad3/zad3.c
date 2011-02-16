#include <stdio.h>

int main () {
    int n = 5;
    int prvi = 1, drugi = 1, zbir;
   
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == i || j + i == n - 1){
                printf("%d\t", prvi);
                zbir = prvi + drugi;
                prvi = drugi;
                drugi = zbir;
            }
            else{
                printf("%d\t", 0);
            }
        }
        printf("\n");
    }
    return 0;
}