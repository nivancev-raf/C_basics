#include <stdio.h>
#include <string.h>



int main (){
    char str[] = "Nano p!andan! Anan!asu b!ana!no";    
    int flag = 0; // ukoliko je 1 treba caps slova
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == ' '){
            for (int j = 0; j <= i; j++){
                if (str[j] == '!'){
                flag = 1;
                // ovde ide drugi deo zadatka
                }
            }
            // ukoliko se flag nije promenio, znaci nema "!", znaci dizu se slova
            if (flag == 0){
                for (int k = 0; k < i; k++){
                    if (str[k] >= 'a' && str[k] <= 'z')
                        str[k] = str[k] - 32; // stavljamo veliko slovo
                }
            }
        }
        
    }    


    printf(str);

    return 0;
}