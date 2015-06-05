/*
ID: unequal1
LANG: C++
PROG: fracdec
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000
#define DEBUG 0

char line[MAX_LEN];
bool hit_rem[MAX_LEN];
int rec_digit[MAX_LEN];
int hit_count,hit_num_count,hit_num;

void find_hit(long num, long den){
	long temp = num/den;
	int rec_hit_time[MAX_LEN];
	int count=0;	
	char swap;
	bool flag = false;
	
	while(temp != 0){
		line[count] = temp%10 + 48;
		temp/=10; count++;		
	}
	for(int x=0;x<count/2;x++){
		swap = line[x];
		line[x] = line[count -1 -x];
		line[count -1 -x] = swap;
	}
	if(count == 0){
		line[count] = '0';
		count++;
	}	
	line[count] = '.';
	count++;
	
	temp = num%den;
	if(temp == 0){
		hit_count = 0;
		line[count] = '0';
		line[count+1] = '\0';
		count+=2;
		return;
	}
	else{
		while(!hit_rem[temp]){
			if(DEBUG)
				printf("rem:%d , output:%d\n",temp, (temp*10)/den);
			hit_rem[temp] = true;
			rec_hit_time[temp] = count;
			temp*=10;
			while(temp - den >= 0){
				rec_digit[hit_count]++;
				temp -= den;
			}
			line[count] = rec_digit[hit_count] + 48;
			count++;			
			hit_count++;						
		} 
		hit_num_count = rec_hit_time[temp];
		hit_num = temp;
		line[count] = '\0'; 
		if(hit_num == 0)		
			line[count-1] = '\0';
	}
}

int main() {
    FILE *fin  = fopen ("fracdec.in", "r");
    FILE *fout = fopen ("fracdec.out", "w");
    long numerator,denominator;    
    fscanf(fin, "%ld %ld\n", &numerator,&denominator);
    find_hit(numerator,denominator);
    if(hit_num == 0){
		for(int x=0;x<strlen(line);x++){
			if((x+1)%76 !=0)
				fprintf(fout,"%c",line[x]);
			else
				fprintf(fout,"%c\n",line[x]);
		}
	}    
    else{
    	int x,pos=1;
    	for(x=0;x<hit_num_count;x++,pos++)
    		if(pos-76 !=0)
				fprintf(fout,"%c",line[x]);
			else{
				pos = 0;
				fprintf(fout,"%c\n",line[x]);
			}
    	fprintf(fout,"(");
    	pos++;
    	for(x=hit_num_count;x<strlen(line);x++,pos++){
    		if(pos-76 !=0)
				fprintf(fout,"%c",line[x]);
			else{
				pos = 0;
				fprintf(fout,"%c\n",line[x]);
			}
		}	
		fprintf(fout,")");
	}		
	fprintf(fout,"\n");
	
	fclose(fin);fclose(fout);
    return 0;
}

