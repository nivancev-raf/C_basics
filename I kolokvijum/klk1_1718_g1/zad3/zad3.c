
#include <stdio.h>
/*
n = 6; 
ABcdEF
BbCDeF
cCCDEf
dDDDEf
EeEEeF
FFffFF
*/

/*
int main (){

    int n = 6;
    char c = 'A';
    int startp, endp;
    if (n % 2 == 0){
        endp = n / 2;
        startp = endp - 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (j == startp){
                if (j <= i){
                printf("%c", c + 32);
                }else{
                printf("%c", 'a' + j);
                }
            }
            else if (j == endp){
                if (j <= i){
                    printf("%c", c + 32);
                }else{
                    printf("%c", 'a' + j);
                    }
                }
                else{
                if (j <= i){
                printf("%c", c);
                }else{
                printf("%c", 'A' + j);
                }
            }
        }
        
        if (i < n / 2){
        endp++;
        startp--;
        }else if(i == n / 2){
            startp = 1;
            endp = n - 2;
        }
        else{
        --endp;
        ++startp;
        }
        
        c++;
        printf("\n");
    }

    return 0;
}
*/

/*
n = 6; 
ABcdEF
BbCDeF
cCCDEf
dDDDEf
EeEEeF
FFffFF
*/
char maloSlovo(char c){
    if (c >= 'A' && c <= 'Z') 
    return c += 32;
}

int main () {
    int n = 6;
    char c = 'A';
    int start, end;
    end = (n-1)/2;
    start = end + 1;
    for (int i = 0; i < n; i++){
        if (i < n / 2){
        start--;
        end++;
        }else if(i == n / 2){
            start = -1;
            end = n;
            start++;
            end--;
        }
        else{
        start++;
        end--;
    }
        for(int j = 0; j < n; j++){
            if (j <= i){
                 if((j!=start && j==end) || (j==start && j!=end)){
                    printf("%c", maloSlovo(c + i));
                    continue;
                }
                printf("%c", c + i);
            }else{
                if((j!=start && j==end) || (j==start && j!=end)){
                    printf("%c", maloSlovo(c + j));
                    continue;
                }
                printf("%c", c + j);
            }
        }
        /*
    if (i < n / 2){
        start--;
        end++;
    }else{
        start++;
        end--;
    }
    */
    printf("\n");
    }



    return 0;
}
