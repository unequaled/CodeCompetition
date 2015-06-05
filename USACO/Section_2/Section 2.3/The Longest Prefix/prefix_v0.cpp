/*
ID: unequal1
LANG: C++
PROG: prefix
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_list, long_length;
int seq_len;
char list_primitives[200][11];

void find_prefix(char* string, int pos){
	int len;
	for(int x=0;x<num_list;x++){
		if(long_length == seq_len)
			break;
		len = strlen(list_primitives[x]);
		if(strncmp(string,list_primitives[x], len) == 0)
			find_prefix(string+len,pos+len);
		
	}
	if(pos > long_length)
		long_length = pos;
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

	find_prefix(seq,0);
	fprintf(fout,"%d\n",long_length);
		
//    for(int x=0;x<num_list;x++)
//    	fprintf(fout,"%s ",list_primitives[x]);
//    fprintf(fout,"\n%s\n",seq);
	
	fclose(fin);fclose(fout);
    return 0;
}
