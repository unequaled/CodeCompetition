/*
ID: unequal1
LANG: C++
PROG: cowtour
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DEBUG 0
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

double find_shortest_path(int num){	
	double dp[MAX][MAX];
	double temp_dist,rec_temp_dist = 1e9;
	int node;
	
	for(int k=0;k<num;k++)
		for(int x=0;x<num;x++)
			for(int y=0;y<num;y++){
				if(path_matrix[x][y] > path_matrix[x][k]+path_matrix[k][y]){
					path_matrix[x][y] = path_matrix[x][k]+path_matrix[k][y];
				}					
			}

	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++){			
			if(path_matrix[i][j] == 1e9){
				for(int x=0;x<num;x++)
					for(int y=0;y<num;y++)
						dp[x][y] = path_matrix[x][y];
				
				dp[i][j]= dist_matrix[i][j];
				dp[j][i]= dist_matrix[i][j];
			
				for(int k=0;k<num;k++)
					for(int x=0;x<num;x++)
						for(int y=0;y<num;y++){
							if(dp[x][y] > dp[x][k]+dp[k][y]){
								dp[x][y] = dp[x][k]+dp[k][y];
							}					
						}
				temp_dist = 0;
				for(int x=0;x<num;x++)
					for(int y=x+1;y<num;y++)
						if(temp_dist < dp[x][y])
							temp_dist = dp[x][y];
							
				if(rec_temp_dist > temp_dist)
					rec_temp_dist = temp_dist;							
			}
			
			if(DEBUG){
				fprintf(fout,"%rec_temp_dist = %lf\t temp_dist = %lf\n",rec_temp_dist,temp_dist);
				fprintf(fout,"dp\n");
				for(int x=0;x<num;x++){
					for(int y=0;y<num;y++)
						fprintf(fout,"%0.2lf\t",dp[x][y]);
					fprintf(fout,"\n");
				}
			}
		}

	return rec_temp_dist;
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

	fprintf(fout,"%lf\n",find_shortest_path(num));
//	fprintf(fout,"%lf\n",find_way(num));
			
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

