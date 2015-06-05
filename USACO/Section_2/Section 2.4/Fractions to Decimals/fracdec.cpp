/*
ID: unequal1
LANG: C++
PROG: fracdec
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100001
#define DEBUG 0

int hit_rem[MAX_LEN];
int hit_count,hit_last;

void find_hit(long num, long den){
	int temp =  num%den;
	int count=0;
	if(temp != 0){
		while(hit_rem[temp]==0){
			count++;
			hit_rem[temp] = count;
			temp = temp*10%den;			
		}
		hit_count=hit_rem[temp];
		hit_last = count;
	}
}

int main() {
    FILE *fin  = fopen ("fracdec.in", "r");
    FILE *fout = fopen ("fracdec.out", "w");
    long numerator,denominator;        
    int pos=0, temp;
    
	fscanf(fin, "%ld %ld\n", &numerator,&denominator);
    find_hit(numerator,denominator);
    
    temp=numerator/denominator;
    fprintf(fout,"%d",temp);
    if(temp==0)
    	pos++;
    else
	    while(temp !=0){
			pos++;
			temp /=10;		
		}
	fprintf(fout,".");
    pos++;
    if(hit_count==0)
    	fprintf(fout,"0\n");
    else{
		temp = numerator%denominator;
		for(int x=0;x<hit_count-1;x++){
			if(pos==75){
				fprintf(fout,"%d\n", temp*10/denominator);
				pos=0;
			}
			else{
				fprintf(fout,"%d", temp*10/denominator);
				pos++;
			}
			temp = temp*10%denominator;
		}
		if(temp == 0){
			fprintf(fout,"\n");
		}
		else{
			fprintf(fout,"(");
			pos++;
			for(int x=hit_count;x<=hit_last;x++){
				if(pos==75){
					fprintf(fout,"%d\n", temp*10/denominator);
					pos=0;
				}
				else{
					fprintf(fout,"%d", temp*10/denominator);
					pos++;
				}
				temp = temp*10%denominator;
			}
			fprintf(fout,")\n");
		}
	}

	//fprintf(fout,"\n");
	
	fclose(fin);fclose(fout);
    return 0;
}


