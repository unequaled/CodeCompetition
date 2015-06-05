/*
ID: unequal1
LANG: C++
PROG: numtri
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int** triangle;
int** flag;
int num;

int find_the_max(int X, int Y){    
	if(X==num-1)
		return triangle[X][Y];
	else{
        if(flag[X][Y] == -1){           
		    flag[X][Y] = MAX(find_the_max(X+1, Y),find_the_max(X+1, Y+1)) + triangle[X][Y];
            return flag[X][Y];
        }
        else
            return flag[X][Y];       
    }    
}

int main() {
    FILE *fin  = fopen ("numtri.in", "r");
    FILE *fout = fopen ("numtri.out", "w");
	
	fscanf(fin, "%d\n", &num);
	triangle = (int **) malloc(sizeof(int*)*num);
	flag = (int**) malloc(sizeof(int*)*num);
	for(int x=0; x<num;x++){
		triangle[x] = (int *) malloc(sizeof(int)*num);
		flag[x] = (int*) malloc(sizeof(int)*num);
		for(int y=0;y<x+1;y++){
			fscanf(fin,"%d", &triangle[x][y]);
            flag[x][y] = -1;
        }
	}

	fprintf(fout,"%d\n",find_the_max(0,0));
		
	fclose(fin);fclose(fout);
    return 0;
}

