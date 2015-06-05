/*
ID: unequal1
LANG: C++
PROG: preface
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_romman(int num,int* output){ 
	int digit[10][3] = {{0,0,0},{1,0,0},{2,0,0},{3,0,0},{1,1,0},{0,1,0},{1,1,0},{2,1,0},{3,1,0},{1,0,1}};
	int count = 0,temp;
	
	while(num !=0){		
		temp = num%10;
		for(int x=0;x<3;x++)
			output[count+x] += digit[temp][x];
		count += 2;
		num /= 10;		
	}
	
}

int main() {
    FILE *fin  = fopen ("preface.in", "r");
    FILE *fout = fopen ("preface.out", "w");
    
    int num,romman_num[7]={1,5,10,50,100,500,1000};    
    int output[7] = {0,0,0,0,0,0};
    char romman_char[7] = {'I','V','X','L','C','D','M'};
    
    fscanf(fin,"%d\n", &num);        
    
    for(int x=1;x<=num;x++)
    	generate_romman(x,output);
    
    for(int x=0;x<7;x++){     
		if(num/romman_num[x] == 0)
    		break;		
		fprintf(fout,"%c %d\n", romman_char[x],output[x]);
	}  	
	
	fclose(fin);fclose(fout);
    return 0;
}

