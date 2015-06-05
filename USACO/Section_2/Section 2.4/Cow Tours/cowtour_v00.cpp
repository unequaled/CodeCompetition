/*
ID: unequal1
LANG: C++
PROG: cowtour
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DEBUG 1
#define MAX 151

// reference the website: http://puremonkey2010.blogspot.tw/2013/05/alg-info-dijkstras-algorithm-shortest.html

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
	bool visit[MAX];
	double temp_dist;
	int node;
	
	for(int x=0;x<num;x++){
		for(int y=0;y<num;y++)
			visit[y] = false;
		
		visit[x] = true;
		for(int y=0;y<num;y++){
			temp_dist = 1e9;
			node = -1;
			for(int z=0;z<num;z++){
				if(path_matrix[x][z] != -1 && temp_dist > path_matrix[x][z] && !visit[z]){
					temp_dist = path_matrix[x][z];
					node = z;
				}					
			}
			
			if(node != -1){
				visit[node] = true;
				for(int z=0;z<num;z++){
					if(path_matrix[node][z] != -1 && (path_matrix[node][z]+path_matrix[x][node] < path_matrix[x][z] ||  path_matrix[x][z]==-1 ))
						path_matrix[x][z] = path_matrix[node][z]+path_matrix[x][node];
						path_matrix[z][x] = path_matrix[x][z];
				}
			}
		}
	}
}

double check_all_connect(int num, int connect_x, int connect_y){
	double temp_path_matrix[MAX][MAX];
	
	for(int x=0;x<num;x++)
		for(int y=0;y<num;y++)
			temp_path_matrix[x][y] = path_matrix[x][y];
	temp_path_matrix[connect_x][connect_y] = dist_matrix[connect_x][connect_y];
	temp_path_matrix[connect_y][connect_x] = dist_matrix[connect_x][connect_y];
	
	bool visit[MAX];
	double temp_dist;
	int node;
	
	for(int x=0;x<num;x++){
		for(int y=0;y<num;y++)
			visit[y] = false;
		
		visit[x] = true;
		for(int y=0;y<num;y++){
			temp_dist = 1e9;
			node = -1;
			for(int z=0;z<num;z++){
				if(temp_path_matrix[x][z] != -1 && temp_dist > temp_path_matrix[x][z] && !visit[z]){
					temp_dist = temp_path_matrix[x][z];
					node = z;
				}					
			}
			
			if(node != -1){
				visit[node] = true;
				for(int z=0;z<num;z++){
					if(temp_path_matrix[node][z] != -1 && (temp_path_matrix[node][z]+temp_path_matrix[x][node] < temp_path_matrix[x][z] ||  temp_path_matrix[x][z]==-1 ))
						temp_path_matrix[x][z] = temp_path_matrix[node][z]+temp_path_matrix[x][node];
						temp_path_matrix[z][x] = temp_path_matrix[x][z];
				}
			}
		}
	}
	
	if(DEBUG){
		fprintf(fout,"TEMP PATH\n");
		for(int x=0;x<num;x++){
			for(int y=0;y<num;y++)
				fprintf(fout,"%0.2lf\t",temp_path_matrix[x][y]);
			fprintf(fout,"\n");
		}
	}
	
	temp_dist = 0;
	for(int x=0;x<num;x++)
		for(int y=x+1;y<num;y++){
			if(temp_path_matrix[x][y]==-1)
				return -1;
			if(temp_dist < temp_path_matrix[x][y])
				temp_dist=temp_path_matrix[x][y];
		}
	
	return temp_dist;
	
}

double find_way(int num){
	struct Record *head_record = 0,*index, *before, *temp;
	double diameter,min_diameter=1e9, min_input_cost;
	
	for(int x=0;x<num;x++){
		for(int y=x+1;y<num;y++){
			if(path_matrix[x][y] == -1){
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
	
	if(DEBUG){
		index = head_record;
		while(index != 0){			
			fprintf(fout,"%0.2lf\t %d %d \n", (*index).cost,(*index).pos[0],(*index).pos[1]);
			index = index -> next;
		}
	}
	
	index = head_record;
	min_input_cost = (*index).cost;
	while(index != 0 && min_input_cost == (*index).cost){			
		diameter = check_all_connect(num,(*index).pos[0],(*index).pos[1]);
		if(diameter != -1 && min_diameter > diameter)
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
			path_matrix[x][y] = -1;
			path_matrix[y][x] = -1;
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
	fprintf(fout,"%lf\n",find_way(num));
			
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

