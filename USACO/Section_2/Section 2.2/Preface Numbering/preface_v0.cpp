/*
ID: unequal1
LANG: C++
PROG: preface
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *fin  = fopen ("preface.in", "r");
    FILE *fout = fopen ("preface.out", "w");
    
    int num,temp;
    int accumulate_1[5]={0,1,3,6,7};
	int accumulate_5[10]={0,0,0,0,2,3,4,5,0};        
    int romman_num[8] = {1,5,10,50,100,500,1000,10000};
    char romman_char[8] = {'0','I','V','X','L','C','D','M'};
    int output[8] = {0,0,0,0,0,0,0};
    
    fscanf(fin,"%d\n", &num);
    
    for(int x=1;x<8;x++){    	
    	if(x%2 == 1){
    		temp = (num/romman_num[x-1])%romman_num[x];
    		if(num/romman_num[x-1] == 0)
    			break;
    		if(temp == 4*romman_num[x-1])
				output[x+1] += 1;
			output[x] += accumulate_1[temp] + 7* (num/romman_num[x]);
		}   			
		else{
			temp = (num%romman_num[x])/romman_num[x-2] ; 
			if(num/romman_num[x-1] == 0)
    			break;
			if(temp == 9)
				output[x+1] += 1;
			output[x] += accumulate_5[temp] + 5*num/romman_num[x];
		}
		fprintf(fout,"%c %d\n", romman_char[x],output[x]);
	}  	
	
	fclose(fin);fclose(fout);
    return 0;
}

