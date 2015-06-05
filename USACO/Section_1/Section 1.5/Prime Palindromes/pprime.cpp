/*
ID: unequal1
LANG: C++
PROG: pprime
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 31623

long pow(int , int );
void swap(int* ,int* );
void swapl(long* ,long* );
void qsort(long* , int , int );
long palindromes_generator(long , int  );
bool check_prime_palindromes(long , long *, int );

int main() {
    FILE *fin  = fopen ("pprime.in", "r");
    FILE *fout = fopen ("pprime.out", "w");
    
    bool flag;
    
    long prime_list[MAX/2];
    long prime_palindromes_list[MAX/2];
    int num=0, pplist_count=0;
    
    long A,B,temp,counter=0,start_len,upper_bound;    
    int len_A=0,len_B=0;
    
	fscanf(fin,"%ld %ld", &A, &B);	   
    
    prime_list[num] = 2;    
    num++;    
    
	for(int x =3; x<MAX; x+=2){				//create a prime list
    	flag = false;
    	for(int y=0; y<num; y++){
			if(x%prime_list[y] == 0){
				flag = true;
				break;	
			}			
		}
		if(!flag){
			prime_list[num] = x;
			num ++;
		}							
	}
	
	temp = B;                              //count A's and B's number of digits 
	while(temp !=0){
        temp /= 10;
        len_B++;        
    }    
   	temp = A;	
    while(temp !=0){
        temp /= 10;
        len_A++;        
    }
   
    upper_bound = pow(len_B/2+len_B%2,10);                //generate all the palindromes
    for(long x = pow(len_A/2,10); x < upper_bound; x++){
        temp = palindromes_generator(x,0);
        if(temp >= A && temp <=B)
            if(check_prime_palindromes(temp,prime_list,num)){
                prime_palindromes_list[pplist_count] = temp;
                pplist_count++;
            }
        temp = palindromes_generator(x,1);
        if(temp >= A && temp <=B)
            if(check_prime_palindromes(temp,prime_list,num)){
                prime_palindromes_list[pplist_count] = temp;
                pplist_count++;
            }       
    }    
	
    qsort(prime_palindromes_list,0,pplist_count-1);	       //sort all the prime palindromes

	for(int x =0;x<pplist_count;x++)
    	fprintf(fout,"%ld\n",prime_palindromes_list[x]);
	
	fclose(fin);fclose(fout);
    return 0;
}

bool check_prime_palindromes(long number, long *prime_list, int prime_list_num){
    for(int x=0;x<prime_list_num;x++){
        if(number%prime_list[x] == 0 && number != prime_list[x]){
            return false;            
        }            
    }
    return true;
}


long palindromes_generator(long num, int odd ){
    int palindromes[10],temp=0,count=0;
    
    while(num != 0){
        palindromes[count] = num%10;
        num /= 10; count++; 
    }
    for(int x =0; x < count/2; x++)
        swap(&palindromes[x],&palindromes[count-x-1]);    
    
    if(odd == 1)                
        for(int x =0; x < count - 1; x++)
            palindromes[2*(count-1)-x] = palindromes[x];    
    else
        for(int x =0; x < count; x++)
            palindromes[2*count-x-1] = palindromes[x];

    for(int x=0;x<count*2-odd;x++)
        temp += palindromes[x]*pow(x,10);
    
    return temp;           
}

void swap(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swapl(long* a,long* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void qsort(long* data, int left, int right){		
	int i = left, j = right -1;
	
	if (left >= right) 
		return;
	
	while(1){
		while(i<right){
			if(data[i] > data[right])
				break;
			i++;
		}
		while(j>=left){
			if(data[j] < data[right])
				break;
			j--;
		}
		if(i>j)
			break;
		
		swapl(&data[i], &data[j]);	
	}
	
	swapl(&data[i],&data[right]);
	qsort(data,left,i-1);
	qsort(data,i+1,right);	
}

long pow(int x, int y){
    long result = 1;
    for(int z=0;z<x;z++)
        result *= y;   
    return result; 
}
