#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Napisati funkciju koja od date matrice pravi novu matricu tako što svaki element
matrice zamenjuje minimumom iz kolone i vrste u kojoj se nalazi element. Napraviti testni program
koji učitava matricu od korisnika i ispisuje rezultat. Primer:

2 3 5 7 5   
3 5 9 2 8   
1 8 2 5 6   
7 3 4 5 4   
1 3 9 6 5   


1 2 2 2 2
1 2 2 2 2
1 1 1 1 1
1 3 2 2 3
1 1 1 1 1


*/

int main (){
    
    const int max_rows = 5;
    const int max_columns = 5;

    //int mat[max_rows][max_columns] = {
    int mat[5][5] = {
        {2, 3, 5, 7, 5},
        {3, 5, 9, 2, 8},   
        {1, 8, 2, 5, 6},   
        {7, 3, 4, 5, 4},   
        {1, 3, 9, 6, 5}
    };

    int out_mat[max_rows][max_columns];

    int row = 0, col = 0;
    int min;
    
    //for (;;) - same sa while(1) or while(true)
    while(1)
    {
        min = mat[row][col];

        // find min elem in columns
        for (int i = 0; i < max_columns; i++)
        {
            if(mat[row][i] < min)   
                min = mat[row][i];
        }

        // find min elem in rows
        for (int i = 0; i < max_rows; i++)
        {
            if(mat[i][col] < min)   
                min = mat[i][col];
        }

        out_mat[row][col] = min;

        if(col < max_columns){
            col++;
        }
        else{
            col = 0;
            row++;
            if(row >= max_rows){
                break;
            }
        } 
    }

    // print out_mat
    for (int i = 0; i < max_rows; i++){
        for (int j = 0; j < max_columns; j++){
            printf("%d ", out_mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

