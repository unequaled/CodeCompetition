/*
ID: unequal1
LANG: C++
PROG: sprime
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DIGIT 9
#define MAX_SQRT 31623
#define MAX_SIZE_N_DIGIT 1000

void sprime_list_factory( int );
bool check_prime(long , int *, int );
void prime_list_creator(int* , int* , int );
long pow(int , int);

long N_sprime_list[MAX_DIGIT][MAX_SIZE_N_DIGIT];
int N_sprime_list_num[MAX_DIGIT];

int main() {
    FILE *fin  = fopen ("sprime.in", "r");
    FILE *fout = fopen ("sprime.out", "w");
    

    
    int digit;    
	fscanf(fin, "%d", &digit);
	
	sprime_list_factory(digit);

    
    for(int x =0;x<N_sprime_list_num[digit];x++)
    	fprintf(fout,"%ld\n",N_sprime_list[digit][x]);
	
	fclose(fin);fclose(fout);
    return 0;
}

void sprime_list_factory(int digit){
	long temp;
	int prime_list[MAX_SQRT/2];
	int prime_list_num =0 ;
	
	prime_list_creator(prime_list,&prime_list_num,MAX_SQRT);
	
	if(digit <= 0 )
		return;
	else{
		N_sprime_list[1][0] = 2;
		N_sprime_list[1][1] = 3;
		N_sprime_list[1][2] = 5;
		N_sprime_list[1][3] = 7;
		N_sprime_list_num[1] = 4;
	}	
	
	for(int x=2;x<=digit;x++){
		N_sprime_list_num[x] = 0;
		//sprime_generator(N_sprime_list[x],x);
		for(int z=0; z < N_sprime_list_num[x-1]; z++){
			for(int y=1; y<10;y=y+2){
				temp = N_sprime_list[x-1][z]*10 + y;
				if(check_prime(temp,prime_list,prime_list_num)){
					N_sprime_list[x][N_sprime_list_num[x]] = temp;
					N_sprime_list_num[x]++;
				}
			}			
		}
	}
}


bool check_prime(long number, int *prime_list, int prime_list_num){
    for(int x=0;x<prime_list_num;x++){
        if(number == 1)
            return false;
        if(number%prime_list[x] == 0 && number != prime_list[x]){
            return false;            
        }
        if(prime_list[x] > sqrt(number))       
            break; 
    }
    return true;
}

void prime_list_creator(int* prime_list, int* prime_list_num, int upper_bound){
    bool flag;
    
    prime_list[*prime_list_num] = 2;    
    (*prime_list_num)++;    
    
	for(int x =3; x<upper_bound; x+=2){				//create a prime list
    	flag = false;
    	for(int y=0; y<(*prime_list_num); y++){
			if(x%prime_list[y] == 0){
				flag = true;
				break;	
			}			
		}
		if(!flag){
			prime_list[(*prime_list_num)] = x;
			(*prime_list_num)++;
		}							
	}
}

long pow(int x, int y){
    long result = 1;
    for(int z=0;z<x;z++)
        result *= y;   
    return result; 
}

