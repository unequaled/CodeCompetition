/*
ID: unequal1
LANG: C++
PROG: cowtour
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

#define DEBUG 1
#define MAX 151

// reference Floyd-Warshall Algorithm: http://www.csie.ntnu.edu.tw/~u91029/Reachability.html

int  pos_list[MAX][2];
double  path_matrix[MAX][MAX];
double  dist_matrix[MAX][MAX];

FILE *fin  = fopen ("cowtour.in", "r");
FILE *fout = fopen ("cowtour.out", "w");


struct Record{
	double cost;
	int pos[2];
	struct Record *next;
};

double distance(int x, int y){
	return sqrt((pos_list[x][0]-pos_list[y][0])*(pos_list[x][0]-pos_list[y][0])+
				(pos_list[x][1]-pos_list[y][1])*(pos_list[x][1]-pos_list[y][1]));
}

void find_shortest_path(int num){	
	double temp_dist,rec_temp_dist = 1e9;
	int node;
	
	for(int k=0;k<num;k++)
		for(int x=0;x<num;x++)
			for(int y=0;y<num;y++){
				if(path_matrix[x][y] > path_matrix[x][k]+path_matrix[k][y]){
					path_matrix[x][y] = path_matrix[x][k]+path_matrix[k][y];
				}					
			}
}

double find_way(int num){
	struct Record *head_record = 0,*index, *before, *temp;
	double diameter,min_diameter=1e9, min_input_cost;
	double dp[MAX][MAX];
	
	for(int x=0;x<num;x++){
		for(int y=x+1;y<num;y++){
			if(path_matrix[x][y] == 1e9){
				temp = (struct Record *) malloc(sizeof(struct Record));
				(*temp).cost = dist_matrix[x][y];
				(*temp).pos[0] = x; (*temp).pos[1] = y;
				
				index = head_record;
				before = index;
				while(index != 0){
					if( (*index).cost < dist_matrix[x][y] ){
						before = index;
						index = index -> next;
					}
					else
						break;						
				}
				if(index != head_record)
					before -> next = temp;
				else{
					head_record = temp;					
				}
				temp -> next = index;
			}
		}
	}
	
	index = head_record;
	min_input_cost = (*index).cost;
	while(index != 0 && min_input_cost == (*index).cost){
		for(int x=0;x<num;x++)
			for(int y=0;y<num;y++){				
				dp[x][y] = path_matrix[x][y];						
			}
		
		// add the path distance directly
		diameter = 0;
		for(int x=0;x<num;x++)
			for(int y=x+1;y<num;y++){
				if(dp[x][y] == 1e9){
					dp[x][y] = MIN(dp[x][(*index).pos[0]],dp[x][(*index).pos[1]])+(*index).cost+MIN(dp[(*index).pos[0]][y],dp[(*index).pos[1]][y]);					
				}
				if(dp[x][y] > diameter)
					diameter = dp[x][y];
			}

		if(min_diameter > diameter)
			min_diameter = diameter;
		index = index -> next;		
	}
	
	if(DEBUG)
		fprintf(fout,"%lf\n",min_diameter);
	return min_diameter;
}

int main() {
    
    int num;
    int diameter_pos[2];
	double diameter = 0;
    char matrix[MAX][MAX];
    
    fscanf(fin, "%d\n", &num);
    for(int x=0;x<num;x++){
		fscanf(fin, "%d %d\n", &pos_list[x][0], &pos_list[x][1]);
	}
	
	for(int x=0;x<num;x++){
		fscanf(fin, "%s\n",matrix[x]);
	}
	
	for(int x=0;x<num;x++){
		for(int y=x+1;y<num;y++){
			path_matrix[x][y] = 1e9;
			path_matrix[y][x] = 1e9;
			if(matrix[x][y] == '1')	{	
				path_matrix[x][y] = distance(x,y);
				path_matrix[y][x] = path_matrix[x][y];
			}
			dist_matrix[x][y] = distance(x,y);
			dist_matrix[y][x] = distance(x,y);
			if(diameter<dist_matrix[x][y])	{
				diameter_pos[0] = x;
				diameter_pos[1] = y;
			}					
		}
	}

	find_shortest_path(num);
	diameter = find_way(num);
	if(diameter == 1e9)
		diameter = 1;

	fprintf(fout,"%lf\n",diameter);
			
	if(DEBUG){
		fprintf(fout,"PATH\n");
		for(int x=0;x<num;x++){
			for(int y=0;y<num;y++)
				fprintf(fout,"%0.2lf\t",path_matrix[x][y]);
			fprintf(fout,"\n");
		}
		
		fprintf(fout,"dist\n");					
		for(int x=0;x<num;x++){
			for(int y=0;y<num;y++)
				fprintf(fout,"%0.2f\t",dist_matrix[x][y]);				
			fprintf(fout,"\n");
		}
	}	


	
	fclose(fin);fclose(fout);
    return 0;
}

