/*
ID: unequal1
LANG: C++
PROG: money
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAP 10001
#define MAX_UNIT 26

unsigned long long ways[MAX_CAP];
int unit[MAX_UNIT];

int main() {
    FILE *fin  = fopen ("money.in", "r");
    FILE *fout = fopen ("money.out", "w");
    
    int num_unit,space;
    
    fscanf(fin,"%d %d\n",&num_unit,&space);
    for(int x=1;x<=num_unit;x++)
        fscanf(fin,"%d",&unit[x]);
	
    ways[0] = 1;
	for(int x=1;x<=num_unit;x++){
	    for(int y=unit[x];y<=space;y++){
            ways[y] += ways[y-unit[x]];                
        }
    }
    
//    for(int y=1;y<=space;y++){
//        fprintf(fout,"%I64u\n",ways[y]);
//    }
    
    
    fprintf(fout,"%llu\n",ways[space]);
	
	fclose(fin);fclose(fout);
    return 0;
}

