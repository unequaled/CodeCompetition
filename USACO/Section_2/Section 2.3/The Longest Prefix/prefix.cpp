/*
ID: unequal1
LANG: C++
PROG: prefix
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int num_list, long_length;
long seq_len;
char list_primitives[200][11];
bool seq_check[200001];

// my idea is to compare the end string of seq with the same length of the current primitives.
// If I get a hit, I will set the seq_check to true in this period of the array.
// After check all the seq, checking the seq_check and break at the first false.
// The number is the longest prefix number.

void check_prefix(char *seq, long len){
	int primitives_len=0;
	for(int x=0;x<num_list;x++){
		primitives_len = strlen(list_primitives[x]);
		if(primitives_len -1 <= len){
			if(strncmp(list_primitives[x], seq+len-primitives_len+1,primitives_len) ==0)
				for(int y=0;y<primitives_len;y++)
					seq_check[len-y]=true;
		}	
	}
}

int main() {	
    FILE *fin  = fopen ("prefix.in", "r");
    FILE *fout = fopen ("prefix.out", "w");
    
    char input[80];
    char seq[200001];
       
    num_list = 0;
    long_length = 0;
    while(1){    	 
    	fscanf(fin,"%s",input);
    	if(strcmp(input,".")==0)
    		break;
    	strcpy(list_primitives[num_list],input);
    	num_list++;
	}
	while(1){		
    	fscanf(fin,"%s",input);
    	if(feof(fin)){
    		seq[seq_len] = '\0';
			break;    
		}
    	for(int x =0;x<strlen(input);x++){
			seq[seq_len] = input[x];
			seq_len++;
		}     	
	}

	for(int x=0; x<seq_len;x++){
		check_prefix(seq,x);
	}
		
//    for(int x=0;x<num_list;x++)
//    	fprintf(fout,"%s ",list_primitives[x]);
//    fprintf(fout,"\n%s\n",seq);

    for(int x=0;x<=seq_len;x++)
    	if(!seq_check[x]){
    		long_length = x;
    		break;
    	}
	fprintf(fout,"%ld\n",long_length);    

	
	fclose(fin);fclose(fout);
    return 0;
}

