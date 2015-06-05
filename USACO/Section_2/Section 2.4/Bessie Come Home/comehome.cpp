/*
ID: unequal1
LANG: C++
PROG: comehome
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0 
#define MAX_N 53
int maps[MAX_N][MAX_N];

int atoi(char *s){
	int temp=0;
	for(int x=0;x<strlen(s);x++){
		if(*(s+x) >= '0' && *(s+x) <= '9')
			temp = temp*10 + (*(s+x)-48);
	}
	return temp;
}

void ind_shortest_path(){
	bool visit[MAX_N];
	double temp_dist;
	int node;
	int target = 25;

	for(int x=0;x<MAX_N;x++)
		visit[x] = false;
		
	visit[target] = true;
	for(int y=0;y<MAX_N;y++){
		temp_dist = 1e9;
		node = -1;
		
		for(int z=0;z<MAX_N;z++){
			if(maps[target][z] != 0 && temp_dist > maps[target][z] && !visit[z]){
				temp_dist = maps[target][z];
				node = z;
			}					
		}
		
		if(node != -1){
			visit[node] = true;
			for(int z=0;z<MAX_N;z++){
				if(maps[node][z] != 0 && (maps[node][z]+maps[target][node] < maps[target][z] ||  maps[target][z]==0 ))
					maps[target][z] = maps[node][z]+maps[target][node];
					maps[z][target] = maps[target][z];
			}
		}
	} 

}


int main() {
    FILE *fin  = fopen ("comehome.in", "r");
    FILE *fout = fopen ("comehome.out", "w");
    
    int num,i,j,cost;
    char input[10];
    
    fscanf(fin,"%d\n", &num);
    for(int x=0;x<num;x++){
    	fgets(input, 10, fin);

    	if(input[0] < 97)
			i = input[0] - 65;		
		else
			i = input[0] - 97 + 26;
		if(input[2] < 97)
			j = input[2] - 65;		
		else
			j = input[2] - 97 + 26;			
		
		cost = atoi(input+4);
		if(maps[i][j] == 0 || (maps[i][j] != 0 && cost< maps[i][j])){
			maps[i][j] = cost;
			maps[j][i] = cost;
		}
    }
	
	ind_shortest_path();
	cost = 1e9;
	for(i=0;i<25;i++){
		if(maps[25][i] != 0 && cost > maps[25][i]){
			cost = maps[25][i];
			j = i;
		}
	}
		
	fprintf(fout,"%c %d\n", j+65, cost);
	
	if(DEBUG){
		for(int x=0;x<MAX_N;x++){
			for(int y=0;y<MAX_N;y++)
				fprintf(fout,"%d\t",maps[x][y]);
			fprintf(fout,"\n");
		}
	}
	
	fclose(fin);fclose(fout);
    return 0;
}

