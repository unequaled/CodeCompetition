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

#define DEBUG 0
#define MAX 151

// reference Floyd-Warshall Algorithm: http://www.csie.ntnu.edu.tw/~u91029/Reachability.html

int pos_list[MAX][2];
int group_count; 
double  path_matrix[MAX][MAX];
double  dist_matrix[MAX][MAX];
double  longest_arr[MAX];
int  group_info[MAX][2];  // x = # of group, group[x][0] from point, group[x][1] to point, group[x][3] max distance in that group.
double  group_longest_arr[MAX];

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
	double temp_dist = 0;
	int node;
	
	for(int k=0;k<num;k++)
		for(int x=0;x<num;x++)
			for(int y=0;y<num;y++){
				if(path_matrix[x][y] > path_matrix[x][k]+path_matrix[k][y]){
					path_matrix[x][y] = path_matrix[x][k]+path_matrix[k][y];
				}					
			}
	// record the longest distion in that particular point.
	for(int x=0;x<num;x++){
		for(int y=0;y<num;y++){
			if(path_matrix[x][y] > longest_arr[x] && x!=y && path_matrix[x][y] != 1e9){
				longest_arr[x] = path_matrix[x][y] ;
			}					
		}
	}
	
	if(DEBUG){
		fprintf(fout,"longest_arr\n");
		for(int x=0;x<num;x++){			
			fprintf(fout,"%0.2lf\t",longest_arr[x]);		
		}
	}	
}

void find_group(int num){
	int y=0;
	
	group_count = 0;
	group_info[0][0] = 0;
	
	for(int x=0;x<num;x++){
		// assume the matrix is already grouped in adjest matrix
		if(path_matrix[y][x] == 1e9){	
			y = x;
			group_info[group_count][1] = x-1;
			group_count++;
			group_info[group_count][0] = x;			
		}
	}	
	group_info[group_count][1] = num-1;
	group_count++;
	
	for(int z=0;z<group_count;z++)
		for(int x=group_info[z][0];x<group_info[z][1];x++)
			for(int y=x+1;y<=group_info[z][1];y++){
				if(path_matrix[x][y] > group_longest_arr[z]){
					group_longest_arr[z] = path_matrix[x][y];
				}					
			}

	if(DEBUG){
		fprintf(fout,"group_count\n");
		for(int x=0;x<group_count;x++){			
			fprintf(fout,"from %d to %d %0.2lf\t",group_info[x][0],group_info[x][1],group_longest_arr[x]);		
		}
	}

}


double find_way(int num){
	double diameter,min_diameter=1e9, min_input_cost;
	double dp[MAX][MAX];
	bool flag = false;
	
	for(int i=0;i<num;i++){
		for(int j=i+1;j<num;j++){
			if(path_matrix[i][j] == 1e9){
				diameter = longest_arr[i] + dist_matrix[i][j] + longest_arr[j] ;				
				if(min_diameter > diameter)
					min_diameter = diameter;				
			}
		}
	}
	
	// Here is the tricky party. I am not sure if there are more than 2 fields.
	// The solution only have to find "ONE" connection for any two from three.

	for(int i=0;i<group_count;i++)
		min_diameter = (min_diameter > group_longest_arr[i] )? min_diameter:group_longest_arr[i];		
	
	if(DEBUG)
		fprintf(fout,"%lf\n",min_diameter);
	return min_diameter;
}

int main() {
    
    int num;
    int diameter_pos[2];
	double diameter = 0;
    char matrix[MAX][MAX];
    bool flag=false;
    
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
				flag = true;
			}
			dist_matrix[x][y] = distance(x,y);
			dist_matrix[y][x] = distance(x,y);
			if(diameter<dist_matrix[x][y])	{
				diameter_pos[0] = x;
				diameter_pos[1] = y;
			}					
		}
	}

	if(flag){
		find_shortest_path(num);
		find_group(num);
		diameter = find_way(num);
	}
	else
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

