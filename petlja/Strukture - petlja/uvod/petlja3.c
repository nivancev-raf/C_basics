#include <stdio.h>
#include <string.h>


typedef struct {
    char ime[50];
    char prezime[50];
    int brojPoena;
}Student;

int main()
{
    Student *student_pok;
    Student s1;
    strcpy(s1.ime, "Petar");
    strcpy(s1.prezime, "Peric");
    s1.brojPoena = 30;
    student_pok = &s1;
    printf("%s %s %d", student_pok->ime, student_pok->prezime, student_pok->brojPoena);
    return 0;
}

