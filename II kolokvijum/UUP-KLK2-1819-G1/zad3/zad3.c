#include <stdio.h>
#include <string.h>

/*
char str[] = "prvi drugi prvi drugi treci prvi"
zadatak je naci koji se token najvise puta pojavio u zadatom stringu
izlaz: prvi 3
*/

int main()
{
	char str[] = "prvi drugi drugi drugi treci drugi";
    
    // ovde ce init_size dati pravu duzinu stringa
    //int init_size = strlen(str);
	char delim[] = " ";

    int j = 0;
    char* tokens[10];

	// strtok(str, delim) ce vratiti pointer na prvi token (u ovom slucaju "prvi"), 
    // iza njega ce u originalnom stringu ubaciti NULL i interno ce pokazivati na
    // sledeci token (u ovom slucaju "drugi") koji ce se dobiti kad krenemo da 
    //iteriramo u while petlji i pozivamo strtok(NULL, delim);
    // Zato ako posle ovog poziva dole pozovemo 
    // int init_size = strlen(str);
    // DOBICEMO DUZINU PRVOG TOKENA, A NE CELOG STRINGA KAKO SMO OCEKIVALI!!!

	char *ptr = strtok(str, delim);

    tokens[j++] = ptr;

	while(ptr != NULL)
	{
		//printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
        tokens[j++] = ptr;
	}

	int n = 0; //position of max token
    int maxNumOfRepetition = 1;
    for (int i = 0; i < j; i++)
    {
        int numOfRepetition = 1;
        for (int m = i + 1; m < j - 1; m++)
        {
            if(strcmp(tokens[i], tokens[m]) == 0)
            {
                // tokens are equal
                if(++numOfRepetition > maxNumOfRepetition)
                {
                    maxNumOfRepetition = numOfRepetition;
                    n = i;
                }
            }

        }
    }

    // print max token and num of instances
    printf("\ntoken: '%s' has %d repetition\n\n", tokens[n], maxNumOfRepetition);

	return 0;
}

