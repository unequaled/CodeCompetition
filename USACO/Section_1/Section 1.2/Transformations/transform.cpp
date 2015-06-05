/*
ID: unequal1
LANG: C++
PROG: transform
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** rotate90(char** , int );
char** rotate180(char** , int );
char** rotate270(char** , int );
char** reflection(char** , int );
char** combination(char** , int );
char** noChange(char** , int );
bool equal(char**,char**,int);

int main() {
    FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");
    
    int num,mark=0;
    char **matrix,**compare;
    bool flag =false;
    
    int x,y;
    
    fscanf(fin, "%d\n", &num);
    matrix = (char**) malloc(sizeof(char *)*num);       
    for(x=0; x <num; x++){
        matrix[x] = (char*) malloc(sizeof(char)*num); 
        for(y =0; y <num-1 ; y++ ){
             fscanf(fin, "%c", &matrix[x][y]);             
        }
        fscanf(fin, "%c\n", &matrix[x][y]);                  
    }
    
    compare = (char**) malloc(sizeof(char *)*num);  
    for(x=0; x <num; x++){
        compare[x] = (char*) malloc(sizeof(char)*num); 
        for(y =0; y <num-1 ; y++ ){
             fscanf(fin, "%c", &compare[x][y]);
        }
        fscanf(fin, "%c\n", &compare[x][y]); 
    }
    
    if(equal(rotate90(matrix,num),compare,num)){
        mark =1; 
        flag = true;       
    }
    else if(equal(rotate180(matrix,num),compare,num)){
        mark =2;
        flag = true;           
    }
    else if(equal(rotate270(matrix,num),compare,num)){
        mark =3; 
        flag = true;          
    }
    else if(equal(reflection(matrix,num),compare,num)){
        mark =4;
        flag = true;           
    }    
    else if(!equal(matrix,compare,num)){
        char** temp = reflection(matrix,num);
        if(equal(rotate90(temp,num),compare,num) || equal(rotate180(temp,num),compare,num) || equal(rotate270(temp,num),compare,num)){
            mark =5;
            flag = true;    
        }
    }
    else if(equal(matrix,compare,num)){
        mark =6;
        flag = true;    
    }
            
    if(flag)
        fprintf(fout, "%d\n", mark);
    else
        fprintf(fout, "7\n");
    
    //for(x=0;x<num;x++){
//        for(y=0;y<num-1;y++)
//            fprintf(fout, "%c", reflection(matrix,num)[x][y]);
//        fprintf(fout, "%c\n", reflection(matrix,num)[x][y]);
//    }
    
    free(matrix);free(compare);
    fclose(fin);fclose(fout);
    return 0;
}

char** rotate90(char** matrix, int num){
    char** temp;
    int x,y,z;
    
    temp = (char**) malloc(sizeof(char *)*num);    
    for(x=0; x <num; x++)
        temp[x] = (char*) malloc(sizeof(char)*num); 
        
    for(x=0;x<num;x++)
        for(y=0,z=num-1;y<num;y++,z--)
            temp[x][y] = matrix[z][x];
    return temp;
}

char** rotate180(char** matrix, int num){
    char** temp;
    int x,y,z1,z2;
    
    temp = (char**) malloc(sizeof(char *)*num);    
    for(x=0; x <num; x++)
        temp[x] = (char*) malloc(sizeof(char)*num); 
        
    for(x=0,z1=num-1;x<num;x++,z1--)
        for(y=0,z2=num-1;y<num;y++,z2--)
            temp[x][y] = matrix[z1][z2];
    return temp;
}

char** rotate270(char** matrix, int num){
    char** temp;
    int x,y,z;
    
    temp = (char**) malloc(sizeof(char *)*num);    
    for(x=0; x <num; x++)
        temp[x] = (char*) malloc(sizeof(char)*num); 
    
    for(x=0,z=num-1;x<num;x++,z--)
        for(y=0;y<num;y++)
            temp[x][y] = matrix[y][z];
    return temp;
}

char** reflection(char** matrix, int num){
    char** temp;
    int x,y,z;
    
    temp = (char**) malloc(sizeof(char *)*num);    
    for(x=0; x <num; x++)
        temp[x] = (char*) malloc(sizeof(char)*num); 
        
    for(x=0;x<num;x++)
        for(y=0,z=num-1;y<num;y++,z--)
            temp[x][y] = matrix[x][z];
    return temp;
}

char** noChange(char** matrix, int num){
    return matrix;
}

bool equal(char** matrixA,char** matrixB, int num){
    int x,y;
    for(x=0;x<num;x++)
        for(y=0;y<num;y++)
            if(matrixA[x][y] != matrixB[x][y])
                return false;    
    return true;
}
