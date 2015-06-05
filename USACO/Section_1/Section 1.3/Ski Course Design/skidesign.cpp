/*
ID: unequal1
LANG: C++
PROG: skidesign
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define RANGE 17

int main() {
    FILE *fin  = fopen ("skidesign.in", "r");
    FILE *fout = fopen ("skidesign.out", "w");
    
    int num, max= -1, min = 65535;
    int hill[MAX_N];
    double cost,record = -1;
    
    fscanf(fin, "%d\n", &num);
    
    for(int x=0; x<num; x++){
        fscanf(fin, "%d\n", &hill[x]); 
        if(hill[x] > max)
            max = hill[x];
        if(hill[x] < min)
            min = hill[x];
    }
    
    for(int x=min ; x<= max-RANGE; x++){
        cost = 0;
        for(int y=0 ; y<num; y++){
            if(hill[y] < x){
                cost += (x - hill[y])*(x - hill[y]);
            }
            if(hill[y] > x + RANGE){
                cost += (hill[y] - (x + RANGE))*(hill[y] - (x + RANGE));
            }                
        }
        //fprintf(fout, "%.0f\n", cost);
        if(record == -1 || cost < record)
            record = cost;
    }
	
	fprintf(fout, "%.0f\n", record);
	fclose(fin);fclose(fout);
    return 0;
}

