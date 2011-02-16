#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("C:\\projects\\Strukture - petlja\\uvod\\mojFajl.txt", "w");  // relativna putanja do fajla
    if(fp!=NULL){                     
        printf("Fajl je uspesno otvoren.\n");
        fputc('a', fp);
    }else{
        printf("Greska.\n");
    }
    if(fclose(fp)!=EOF){
        printf("Fajl je uspesno zatvoren.\n");
        exit(EXIT_SUCCESS);
    }else
        exit(EXIT_FAILURE);
}
