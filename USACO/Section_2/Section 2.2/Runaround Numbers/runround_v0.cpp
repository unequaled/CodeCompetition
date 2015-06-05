/*
ID: unequal1
LANG: C++
PROG: runround
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGIT 10


bool check_round(int* round_num_digit, int num_digit){
	bool check_digit[MAX_DIGIT]; 
	int index=0;
	
	for(int x=0;x<num_digit;x++)
		check_digit[x]=false;
	
	for(int x=0;x<num_digit;x++){
		if(check_digit[index]) 					
			return false;
		check_digit[index] = true;
		index = (round_num_digit[index] + index)%num_digit;
	}
	
	if(index == 0){	
		for(int x=0;x<num_digit;x++)
			if(!check_digit[x])
				return false;
		return true;
	}
	else
		return false;
}

void num_to_digit(unsigned long input, int*round_num_digit, int* num_digit){
	int temp[MAX_DIGIT];
	*num_digit = 0;
	
	while(input!=0){
		temp[*num_digit] = input%10;
		input = input/10;
		(*num_digit)++;
	}
	
	for(int x=0;x<(*num_digit);x++){
		round_num_digit[(*num_digit)-1-x] = temp[x];
	}
}

int main() {
    FILE *fin  = fopen ("runround.in", "r");
    FILE *fout = fopen ("runround.out", "w");

	int round_num_digit[MAX_DIGIT];
	int num_digit;
	unsigned long input;   
	
	fscanf(fin,"%ld\n", &input);
	
	num_to_digit(input,round_num_digit,&num_digit);
	
	if(check_round(round_num_digit,num_digit))
		printf("True");
	else
		printf("False");
	
//	for(int x=0;x<num_digit;x++)
//		fprintf(fout,"%d",round_num_digit[x]);
	
	fclose(fin);fclose(fout);
    return 0;
}

