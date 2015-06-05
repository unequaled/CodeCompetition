//#!179646VO
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void fillTheMatrix(int** matrix, int num);

int main(void){
    int num,count,i,j;
    int **matrix;
    
    scanf("%d", &num);
    
    matrix = (int **) malloc(num*sizeof(int *));
    for (i =0; i < num; i++){
        matrix[i] = (int *) malloc(num*sizeof(int));
    }
    
    fillTheMatrix(matrix,num);
    
     for (i =0; i < num; i++){
        for (j = num -1; j >= 0; j--){
            if(j == 0)
                printf("%d", matrix[i][j]);
            else
                printf("%d ", matrix[i][j]);
        }
        printf("\n");
     }
     free(matrix);
     return 0;
}

void fillTheMatrix(int** matrix, int num){
    int i = 0, j = 0, ri =0, rj = 0;
    bool flagj = 0;
    for (int count= 1; count <= num*num; count++){
        matrix[i][j] = count;
        i++;j--;
        if(j < 0 ){
             if(flagj)
                rj--;             
             else
                rj++;
             if(rj == num){
               flagj = true;
               rj--;                   
               ri++;
             }                   
             i=ri;
             j=rj;
        }    
        if (i == num){
           ri++;
           i=ri;
           j=rj;
        }
             
    }
}
