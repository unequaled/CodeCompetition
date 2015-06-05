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

void find_hit(int num, int den){
	int temp = num/den;
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
    unsigned int numerator,denominator;    
    char output[800][80];
    int output_x=0,output_y=0;
    
    fscanf(fin, "%d %d\n", &numerator,&denominator);
    find_hit(numerator,denominator);
    if(hit_num == 0){
		for(int x=0;x<strlen(line);x++){
			if((x+1)%76 !=0)
				fprintf(fout,"%c",line[x]);
			else
				fprintf(fout,"%c\n",line[x]);
		}
		fprintf(fout,"\n");
	}    
    else{
    	for(int x=0;x<hit_num_count;x++,output_y++){
			output[output_x][output_y] = line[x];
		}
		output[output_x][output_y] = '(';
    	output_y++;
    	for(int x=hit_num_count;x<strlen(line);x++){
    		if(output_y != 75){
				output[output_x][output_y] = line[x];
				output_y++;
			}
			else{
				output[output_x][output_y] = line[x];
				output[output_x][output_y+1] = '\0'; 
				output_x++;
				output_y=0;				
			}    		
		}
		output[output_x][output_y] = ')';
		output[output_x][output_y+1] = '\0';
		for(int x=0;x<=output_x;x++)
			fprintf(fout,"%s\n",output[x]);
	}		
	//fprintf(fout,"\n");
	
	fclose(fin);fclose(fout);
    return 0;
}


