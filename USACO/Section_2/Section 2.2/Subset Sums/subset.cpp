/*
ID: unequal1
LANG: C++
PROG: subset
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 40

// referance to the code on http://www.programering.com/a/MjM4czMwATY.html
// great video on youtube 	http://www.youtube.com/watch?v=EH6h7WA7sDw
// other topic 				http://people.csail.mit.edu/bdean/6.046/dp/

unsigned long solution[MAX_N][(MAX_N+1)*MAX_N/2];

int main() {
    FILE *fin  = fopen ("subset.in", "r");
    FILE *fout = fopen ("subset.out", "w");
    
    int num;   
    long capacity;
    
    fscanf(fin,"%d\n",&num);
   	
   	// This is the 0/1 Knapsack alg.
   	capacity = (num+1)*num/2;
   	
	if(capacity%2 == 1)
		fprintf(fout,"%d\n",0);
	else{
		// the half of the total volumn
		capacity = capacity/2;
		solution[1][1] = 1;
		for(int item_set = 2;item_set<=num;item_set++){ 			// item_set = 2 means there are {1,2} able to be selected.
			for(long iter_spac=1;iter_spac<=capacity;iter_spac++){	// iter_spac means while the volumn is available, how many solutions are counted.
				if(iter_spac < item_set)							// in this condition, the space is not enough. the number of solutions is equal to the last itemset
					solution[item_set][iter_spac] = solution[item_set-1][iter_spac];
				if(iter_spac == item_set)							// in this condition, the number of solutions is equal to the solution of last itemset plus the new solution, only the new item.
					solution[item_set][iter_spac] = solution[item_set-1][iter_spac]+1;
				if(iter_spac > item_set)							// in this condition, the number of solutions is equal to the solution of last itemset plus the solution of last itemset minus the space of the new item ocuupied.
					solution[item_set][iter_spac] = solution[item_set-1][iter_spac] + solution[item_set-1][iter_spac - item_set];				
			}	
		}
		fprintf(fout,"%ld\n",solution[num][capacity]/2);				// divide by two for duplicate sets.
	}	
	fclose(fin);fclose(fout);
    return 0;
}

