/*
ID: unequal1
LANG: C++
PROG: milk3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

bool possible[MAX][MAX][MAX];
int max_bottle[3];
bool flag = false;

void find_all_passible(int bottle0, int bottle1, int bottle2){  
    if(possible[bottle0][bottle1][bottle2])
        return;
    else 
        possible[bottle0][bottle1][bottle2] = true;
   
    // pour milks from c to a
    if(bottle0 + bottle2 > max_bottle[0])
        find_all_passible(max_bottle[0], bottle1, bottle2+bottle0-max_bottle[0]);
    else
        find_all_passible(bottle0 + bottle2, bottle1, 0);

    // pour milks from c to b
    if(bottle1 + bottle2 > max_bottle[1])
        find_all_passible(bottle0, max_bottle[1], bottle2+bottle1-max_bottle[1]);
    else
        find_all_passible(bottle0, bottle1 + bottle2, 0);
    
    // pour milks from b to a
    if(bottle0 + bottle1 > max_bottle[0])
        find_all_passible(max_bottle[0], bottle1 + bottle0-max_bottle[0], bottle2);
    else
        find_all_passible(bottle0 + bottle1, 0 , bottle2);

    // pour milks from b to c
    if(bottle1 + bottle2 > max_bottle[2])
        find_all_passible(bottle0, bottle2 + bottle1 - max_bottle[2], max_bottle[2]);
    else
        find_all_passible(bottle0, 0, bottle1 + bottle2);
        
    // pour milks from a to b  
    if(bottle0 + bottle1 > max_bottle[1])
        find_all_passible(bottle0 + bottle1 - max_bottle[1], max_bottle[1], bottle2);
    else
        find_all_passible(0, bottle0 + bottle1, bottle2);

    // pour milks from a to c
    if(bottle0 + bottle2 > max_bottle[2])
        find_all_passible(bottle0 + bottle2 - max_bottle[2] , bottle1 , max_bottle[2]);
    else
        find_all_passible(0, bottle1, bottle0 + bottle2);    
    
    
}

int main() {
    FILE *fin  = fopen ("milk3.in", "r");
    FILE *fout = fopen ("milk3.out", "w");
    
    bool temp[MAX];
    int large = 0;
    
    for(int x=0;x<MAX;x++){
        temp[x] = false;
        for(int y=0;y<MAX;y++)
            for(int z=0;z<MAX;z++)
                possible[x][y][z] = false;
    }
    
    fscanf(fin,"%d %d %d\n",&max_bottle[0],&max_bottle[1],&max_bottle[2]);
    	
	find_all_passible(0, 0 ,max_bottle[2]);	
	
	for(int x=0; x < MAX; x++){
        for(int y=0; y < MAX; y++){
            if(possible[0][x][y]){
    	        temp[y] = true;
    	        if(y > large)
    	        	large = y;
    	    }
        }   	
    }
    
    for(int x=0; x < MAX; x++){
        if(x == large)
        	break;
		if(temp[x])
            fprintf(fout, "%d ",x);
    }
    fprintf(fout, "%d\n",large);

	
	fclose(fin);fclose(fout);
    return 0;
}

