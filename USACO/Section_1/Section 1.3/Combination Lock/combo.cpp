/*
ID: unequal1
LANG: C++
PROG: combo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int common(int *, int *, int );

int main() {
    FILE *fin  = fopen ("combo.in", "r");
    FILE *fout = fopen ("combo.out", "w");
    
	int num;
	int farmer[3],master[3];
	int total;
	
	fscanf(fin, "%d\n", &num);
	fscanf(fin, "%d %d %d\n", &farmer[0],&farmer[1],&farmer[2]);
	fscanf(fin, "%d %d %d\n", &master[0],&master[1],&master[2]);
	
	if(num == 1)
		total = 1;
	else if(num == 2)
		total = 8;
	else if(num == 3)
		total = 27;
	else if(num == 4)
		total = 64;
	else if(num == 5)
		total = 125;
	else if(num > 5)
		total = 250 - common(farmer, master, num);
	
	fprintf(fout,"%d\n", total);
	
	fclose(fin);fclose(fout);
    return 0;
}

int common(int *farmer, int *master, int num){
	int w,x;
	int total,range = 2;
	int createCom[3],count[3];
	bool line[3][101];
		
	for(x=0;x<101;x++){
		line[0][x] = false;
		line[1][x] = false;
		line[2][x] = false;
	}
	for(x=0;x<3;x++){
		count[x] = 0;
	}
	
	for(x = -range; x <=range; x++){
		for(w=0;w<3;w++)
			createCom[w] = farmer[w] + x;		
		
		for(w=0;w<3;w++){
			if(createCom[w] < 1)
				createCom[w] += num;
			else if(createCom[w] > num) 
				createCom[w] -= num;
		}
		
		for(w=0;w<3;w++)				
			line[w][createCom[w]] = true;				
	}
	
	for(x = -range; x <=range; x++){
		for(w=0;w<3;w++)
			createCom[w] = master[w]  + x;		
		
		for(w=0;w<3;w++){
			if(createCom[w] < 1)
				createCom[w] += num;
			else if(createCom[w] > num) 
				createCom[w] -= num;
		}
		
		for(w=0;w<3;w++){
			if(line[w][createCom[w]])
				count[w]++;
		}		
	}
	
	for(w=0,total=1;w<3;w++)
		total *= count[w];
	
	return total;
}


