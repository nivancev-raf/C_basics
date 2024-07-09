#include <stdio.h>
/*
Napisati funkciju int pom(int arg, int delilac) koja vraca broj koji se 
dobije kada se iz argumenta arg izbace sve cifre deljive 
argumentom delilac (delilac је u opsegu [2,9]).

Zatim korišcenjem funkcije
pom ispisati sve brojeve iz intervala koji
unosi korisnik koji nemaju ni jednu parnu cifru.
*/


int pom (int arg, int delilac){
    if(delilac < 2 || delilac > 9){
        printf("Error: divider out of range");
        return 1;
    }

    int new_num = 0, p = 1;
    while (arg){
        int digit = arg % 10; 
        arg /= 10; 
        if (digit % delilac == 0) 
            continue;
        new_num += digit*p;
        p *= 10;
    }   
    return new_num;
}
/*
int parneCifre(int i){
    int cifra;
    int copy;
    copy = i;
    while (i){
        cifra = i % 10;
        i /= 10;
            if (cifra % 2 != 0){
                continue;
    }
    return copy;
}
*/


int main () {

    //int arg = 5573;
    //printf("arg: %d, new: %d", arg, pom(arg,2));

#if 1
    int n, m, divider;
    scanf("%d%d%d", &n, &m, &divider);

    // to check if number has even digits, divider must be 2. Check this!
    if(divider != 2 ){
        printf("Error: divider must be 2");
        return 1;
    }
    
    for (int i = n; i <= m; i++){
        int res = pom(i, divider);
        if(res == i){
            printf("i: %d, res: %d\n", i, res);    
        }
        //else{
        //    printf("skip => i: %d, res: %d\n", i, res);    
        //}

        
    }
    return 0;
#endif    
}