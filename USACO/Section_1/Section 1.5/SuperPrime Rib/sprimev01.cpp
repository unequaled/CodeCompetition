/*
ID: unequal1
LANG: C++
PROG: sprime
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 31623
#define MAX_PRIME_NUM 100000

void prime_list_creator(bool *, long, int*, int* );
long pow(int , int);
bool check_prime(long , int *, int );

int main() {
    FILE *fin  = fopen ("sprime.in", "r");
    FILE *fout = fopen ("sprime.out", "w");
    
    int digit;
    
	fscanf(fin, "%d", &digit);
		
	bool all_prime_list[MAX_PRIME_NUM];
	int prime_list[MAX/2];
	int prime_list_num=0;

	long temp,start, end;
	bool flag;
	
	
    prime_list_creator(all_prime_list,MAX_PRIME_NUM, prime_list, &prime_list_num);
    
    start = pow(digit-1,10)+1; end = pow(digit,10);
    for(long x = start; x < end ; x+=2){        
        flag = true;
        temp = x;
        while(temp !=0){
        	if (temp < MAX_PRIME_NUM){
	            if(!all_prime_list[temp]){
	                flag = false;
	                break;
	            }
			}
			else{
				if(!check_prime(temp,prime_list,prime_list_num)){
	                flag = false;
	                break;
	            }			
			}
            temp /= 10;                    
        }
        if(flag)
            fprintf(fout,"%ld\n",x);        
    }
//    
//   for(int x =0;x<prime_list_num;x++)
//    	fprintf(fout,"%ld\n",prime_list[x]);
	
	fclose(fin);fclose(fout);
    return 0;
}

void prime_list_creator(bool* all_prime_list, long upper_bound, int* prime_list, int* prime_list_num){
    bool not_prime;    
    
    prime_list[*prime_list_num] = 2;    
    (*prime_list_num)++;    
    
    all_prime_list[0] = false;all_prime_list[1] = false;all_prime_list[2] = true;
    
	for(int x =3; x<upper_bound; x+=2){				//create a prime list
    	not_prime = false;
    	for(int y=0; y<(*prime_list_num) && y < sqrt(x); y++){
			if(x%prime_list[y] == 0){
				not_prime = true;
				break;	
			}			
		}
		if(!not_prime){
			prime_list[(*prime_list_num)] = x;
			(*prime_list_num)++;
			all_prime_list[x] = true;
		}
		else
			all_prime_list[x] = false;
	}
}

bool check_prime(long number, int *prime_list, int prime_list_num){
    for(int x=0;x<prime_list_num;x++){
        if(number == 1)
            return false;
        if(number%prime_list[x] == 0 && number != prime_list[x]){
            return false;            
        }
        if(prime_list[x] > number)       
            break; 
    }
    return true;
}


long pow(int x, int y){
    long result = 1;
    for(int z=0;z<x;z++)
        result *= y;   
    return result; 
}

