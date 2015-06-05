/*
ID: unequal1
LANG: C++
PROG: hamming
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 64

int N_list[MAX_N];

bool hamming_distance(int cur_num, int N_printed, int D ){	
	int result;
	int dist;
	
	for(int z=0; z<N_printed;z++){
		result = N_list[z]^cur_num;
		dist = 0;
		while(result !=0){
			if(result%2 == 1)
				dist++;
			result /= 2;
		}
		if(dist < D)
			return false;		
	}
	return true;	
}


int main() {
    FILE *fin  = fopen ("hamming.in", "r");
    FILE *fout = fopen ("hamming.out", "w");
    
	int N, B, D;
	int N_printed = 1, last_num = 0, cur_num=1, max_num = 1;	
	
	fscanf(fin,"%d %d %d\n", &N, &B, &D);
	
	for(int x=0;x<B;x++)
		max_num *= 2;
	max_num -= 1;	
	
	fprintf(fout, "%d ", 0);
	while(N_printed < N){
		if(hamming_distance(cur_num, N_printed, D)){			
			if(N_printed %10 == 9 || N_printed+1 == N )
				fprintf(fout, "%d\n", cur_num);
			else
				fprintf(fout, "%d ", cur_num);
			N_list[N_printed] = cur_num;
			N_printed++;
		}
		cur_num++;		
		if(cur_num > max_num)	
			cur_num = 0;
	}
	
	fclose(fin);fclose(fout);
    return 0;
}

