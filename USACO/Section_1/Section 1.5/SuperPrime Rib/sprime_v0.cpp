/*
ID: unequal1
LANG: C++
PROG: sprime
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31623

void prime_list_creator(int *, int *, int );
bool check_prime(long , int *, int );
long pow(int x, int y);
long super_rib_generator(long , int *, int );
void swap(int* ,int* );

int main() {
    FILE *fin  = fopen ("sprime.in", "r");
    FILE *fout = fopen ("sprime.out", "w");
    
    int digit;
    
	fscanf(fin, "%d", &digit);
	
	int prime_list[MAX/2];
	int prime_digit[6] = {0,1,2,3,5,7};
	int prime_list_num =0 ;
	long temp;
	bool flag;
	
    prime_list_creator(prime_list,&prime_list_num,MAX);
    
    for(long x = pow(digit-1,10); x < pow(digit,10) ; x++){
        temp = super_rib_generator(x,prime_digit,6);
        if(temp!= -1){
            flag = true;
            while(temp !=0){
                if(!check_prime(temp, prime_list, prime_list_num)){
                    flag = false;
                    break;
                }
                temp /= 10;                    
            }
            if(flag)
                fprintf(fout,"%ld\n",x);            
        }
    }
//    
//   for(int x =0;x<prime_list_num;x++)
//    	fprintf(fout,"%ld\n",prime_list[x]);
	
	fclose(fin);fclose(fout);
    return 0;
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

long super_rib_generator(long num, int *prime_digit, int prime_digit_num){
    int prime[10],count=0,result=0;
    
    while(num != 0){
        prime[count] = num%10;        
        if(prime[count] >= prime_digit_num && prime[count] !=0 )
            return -1;
        prime[count] = prime_digit[prime[count]];
        num /= 10; 
        count++;
    }     
    
    for(int x=0;x<count;x++)
        result += prime[x]*pow(x,10);
    
    return result; 
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
void swap(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
