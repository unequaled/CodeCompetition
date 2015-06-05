/*
ID: unequal1
LANG: C++
PROG: nocows
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 101

// the reference website is http://zeffsalgo.blogspot.tw/2013/12/usaco-training-problem-cow-pedigrees.html
// I stuck at this problem because the solutions required with the fixed height K.
// The main idea is to reduce nodes to half of the input size and find all the possible solution in K layer minus the solution in K-1

unsigned long long ways[MAX_N][MAX_N];

int main() {
    FILE *fin  = fopen ("nocows.in", "r");
    FILE *fout = fopen ("nocows.out", "w");
    
	int N,K;
	
	fscanf(fin,"%d %d\n", &N, &K);
	
	if(N%2 == 0)
		fprintf(fout,"0\n");
	else{
		N=N/2;
		// This set the x layer without 0 node has one possible solution which is root. (actually there is a nodes because the solution reduce the orignal nodes to N/2)
		for(int x=0;x<K;x++)	
			ways[x][0] = 1;
			
		ways[1][1] = 1;
		for(int x=2;x<K;x++)
			for(int y=1;y<=N;y++)
				for(int z=0;z<y;z++){
					ways[x][y] += ways[x-1][z]*ways[x-1][y-z-1];
					ways[x][y] %= 9901;
				}
		
//		for(int x=0;x<K;x++){
//			for(int y=0;y<=N;y++)
//				printf("%llu ",ways[x][y]);
//			printf("\n");
//		}

		// The solutions with fixed height K is find the solutions <=K -  solutions <= K-1.
		// Because the solution reduce the number of the nodes to the half, so the layer K become K-1.
		long output = ways[K-1][N]-ways[K-2][N];
		if (output < 0)
			output += 9901;
		printf("%llu %llu\n", ways[K-1][N],ways[K-2][N]);
		
		fprintf(fout,"%ld\n",output);
	}
	
	fclose(fin);fclose(fout);
    return 0;
}

