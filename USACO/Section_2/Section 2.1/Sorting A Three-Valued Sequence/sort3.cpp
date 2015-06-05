/*
ID: unequal1
LANG: C++
PROG: sort3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) ( x < y ? x : y )

int main() {
    FILE *fin  = fopen ("sort3.in", "r");
    FILE *fout = fopen ("sort3.out", "w");
    
    int input_list[1000];
    int num_count_length[4][4];
    int num_data,iteration = 0, total =0, diff = 0;
    
    fscanf(fin,"%d\n",&num_data);
    
    for(int x=0;x<4;x++)
    	for(int y=0;y<4;y++)
    		num_count_length[x][y] = 0;
    		
    // count the total numbers of 1,2,3
    for(int x=0;x<num_data;x++){
		fscanf(fin,"%d\n",&input_list[x]);
		num_count_length[input_list[x]][0]++;
	}
	
	// count the numbers of other numbers in its field
	for(int x=1;x<4;x++){
		int y = iteration;
		iteration += num_count_length[x][0];		
		for(;y<iteration;y++){			
			if(input_list[y] != x){
				num_count_length[x][input_list[y]]++;
			}
			
		}
	}	

	for(int x=1;x<4;x++){
		for(int y=1;y<4;y++)
			total += num_count_length[x][y];
	}
		
	diff = MIN(num_count_length[1][2],num_count_length[2][1]) + MIN(num_count_length[1][3],num_count_length[3][1]) + MIN(num_count_length[2][3],num_count_length[3][2]);
	total = total - (diff + (total - 2*diff)/3);
	
	
//	for(int x=1;x<4;x++)
//    	printf("In %d field %d %d %d %d\n", x,num_count_length[x][0],num_count_length[x][1],num_count_length[x][2],num_count_length[x][3]);
    fprintf(fout,"%d\n",total)	;
    
	
	fclose(fin);fclose(fout);
    return 0;
}

