/*
ID: unequal1
LANG: C++
PROG: runround
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGIT 10

int digit_occupied[MAX_DIGIT];
long pow(int , int);

bool check_round(int* round_num_digit, int num_digit, bool* taken_digit){
	bool check_digit[MAX_DIGIT]; 
	int index=0, count=0;
		
	for(int x=0;x<MAX_DIGIT;x++){
		if(taken_digit[x])
			count++;
		check_digit[x]=false;
	}
	
	if(count !=num_digit)
		return false;
	
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

void num_to_digit(unsigned long input, int*round_num_digit, int* num_digit, bool* taken_digit){
	int temp[MAX_DIGIT];
	bool flag;
	*num_digit = 0;
	
	for(int x=0;x<10;x++)
		taken_digit[x]=false;
			
	while(input!=0){
		temp[*num_digit] = input%10;
		if(temp[*num_digit] == 0)
			temp[*num_digit] = 1;			
		input = input/10;
		(*num_digit)++;
	}
	
	for(int x=0;x<(*num_digit);x++){
		round_num_digit[x] = temp[(*num_digit)-1-x];
		if(taken_digit[round_num_digit[x]]){
			flag = false;
			for(int y=round_num_digit[x]+1;y<10;y++){
				if(!taken_digit[y]){
					round_num_digit[x] = y;
					taken_digit[y] = true;
					flag = true;
					break;
				}
			}
			if(!flag){
				for(int y=0;y<10;y++)
					taken_digit[y]=false;
				// increase one digit
				(*num_digit)++;				
				for(int y=0,z=1;y<(*num_digit);y++,z++){
					round_num_digit[y] = z;
					taken_digit[z] = true;
				}				
				break;				
			}
		}
		else
			taken_digit[round_num_digit[x]] = true;
	}
}

void find_next(int*round_num_digit, int* num_digit, bool* taken_digit){
	bool flag = false;
	int x,y;
	
	for(x=*num_digit-1; x>=0;x--){
		taken_digit[round_num_digit[x]] = false;
		for(y=round_num_digit[x]+1;y<10;y++){
			if(!taken_digit[y]){				
				round_num_digit[x] = y;
				taken_digit[y]=true;
				flag = true;
				break;
			}
		}
		if(flag){
			for(x=x+1;x<*num_digit;x++){
				for(y=1;y<10;y++)
					if(!taken_digit[y]){
						round_num_digit[x] = y;
						taken_digit[y]=true;
						break;
					}
			}
			break;			
		}
	}
	// if flag is still false needs to add one ditial;
	if(!flag){
		for(int y=0;y<10;y++)
			taken_digit[y]=false;
		// increase one digit
		(*num_digit)++;				
		for(int y=0,z=1;y<(*num_digit);y++,z++){
			round_num_digit[y] = z;
			taken_digit[z] = true;
		}				
	}	
}

int main() {
    FILE *fin  = fopen ("runround.in", "r");
    FILE *fout = fopen ("runround.out", "w");

	int round_num_digit[MAX_DIGIT];
	int num_digit;
	unsigned long input;  
	bool found_round=false, taken_digit[MAX_DIGIT];
	
	fscanf(fin,"%ld\n", &input);	
	
	num_to_digit(input+1,round_num_digit, &num_digit,taken_digit);	
	
	while(!check_round(round_num_digit, num_digit,taken_digit)){
		find_next(round_num_digit, &num_digit,taken_digit);			
	}
		
//	if(!found_round){
//		num_to_digit(pow(num_digit+1,10),round_num_digit, &num_digit);
//	
//	}	
	
//	if(check_round(round_num_digit,num_digit,taken_digit))
//		printf("True");
//	else{
//		printf("False");
//	}
	for(int x=0;x<num_digit-1;x++)
		fprintf(fout,"%d",round_num_digit[x]);
	fprintf(fout,"%d\n",round_num_digit[num_digit-1]);
	
	fclose(fin);fclose(fout);
    return 0;
}

long pow(int x, int y){
    long result = 1;
    for(int z=0;z<x;z++)
        result *= y;   
    return result; 
}


