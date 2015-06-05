/*
ID: unequal1
LANG: C++
PROG: agrinet
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 101
#define DEBUG 0

long maps[MAX_NODE][MAX_NODE];
bool visit[MAX_NODE];

long find_all_fiber(int nodes){
	int cost = 1e9,pos;
	long total=0;
	visit[0] = true;
	
	for(int k=0;k<nodes;k++){		
			cost = 1e9;				
			for(int y=1;y<nodes;y++){
				if(cost > maps[0][y] && k!=y && !visit[y]){
					cost = maps[0][y];
					pos = y;
				}						
			}
		
			visit[pos] = true;
			for(int y=1;y<nodes;y++){
				if(maps[pos][y] < maps[0][y] && maps[pos][y] != 0 && !visit[y] )
					maps[0][y] = maps[pos][y];			
			}
			if(DEBUG){
				printf("Round %d \n",k);
				for(int x=0;x<nodes;x++)
					printf("%d ",maps[0][x]);
				printf("\n");
			}			
	}
	for(int x=1;x<nodes;x++)
		total += maps[0][x];
	return total;
}

int main() {
    FILE *fin  = fopen ("agrinet.in", "r");
    FILE *fout = fopen ("agrinet.out", "w");
    
    int nodes,cost,pos;
    long total =0;
    bool visit[MAX_NODE];
    
    fscanf(fin,"%d\n",&nodes);
    for(int x=0;x<nodes;x++)
    	for(int y=0;y<nodes;y++)
    		fscanf(fin,"%d", &maps[x][y]);
	
	fprintf(fout, "%ld\n", find_all_fiber(nodes));
	
	if(DEBUG){
		printf("maps!!\n");
		for(int x=0;x<nodes;x++){
			for(int y=0;y<nodes;y++){
				printf("%d ",maps[x][y]);
			}
			printf("\n"); 
		}
	}


	fclose(fin);fclose(fout);
    return 0;
}

