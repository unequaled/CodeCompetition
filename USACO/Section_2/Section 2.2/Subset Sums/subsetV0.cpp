/*
ID: unequal1
LANG: C++
PROG: subset
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 40

int count,total;
int list[MAX_N],list_accum[MAX_N];

void find_ans(int list_pos, int pipe_num, int num){
	if(pipe_num == total/2){
		count++;
		return;
	}		
	
	if(list_accum[list_pos-1] - pipe_num > total/2)
		return;	
	
	if(pipe_num+list[list_pos] <= total/2){
		find_ans(list_pos+1,pipe_num+list[list_pos],num);		
		find_ans(list_pos+1,pipe_num,num);
	}	
}

int main() {
    FILE *fin  = fopen ("subset.in", "r");
    FILE *fout = fopen ("subset.out", "w");
    
    int num;   
    
    fscanf(fin,"%d\n",&num);
   	
	for(int x=0;x<num;x++){
		list[x] = x+1;		
		total += list[x];
		list_accum[x] = total;		
	}
		
	find_ans(1,1,num);    
	
	fprintf(fout,"%d\n",count);
	printf("%d\n",count);
	
	fclose(fin);fclose(fout);
    return 0;
}
