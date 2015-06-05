/*
ID: unequal1
LANG: C++
PROG: milk
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(long* ,long* );
void qsort(long* ,long* , int , int );

int main() {
    FILE *fin  = fopen ("milk.in", "r");
    FILE *fout = fopen ("milk.out", "w");
  
  	long milk, *milkUnit, total = 0;
  	long farmer, *price;
  	
  	int x;
  	  	
  	fscanf(fin, "%ld %ld\n", &milk, &farmer);
  	
  	milkUnit = (long*) malloc(sizeof(long)*farmer);
  	price = (long*) malloc(sizeof(long)*farmer);
  	
  	for(x=0;x<farmer;x++){
		fscanf(fin, "%ld %ld\n", &price[x], &milkUnit[x]); 			  
	}
  	
  	qsort(price, milkUnit, 0, farmer-1);
  	
  	for(x=0;x<farmer;x++){
  		if(milk - milkUnit[x] >=0){
  			total += milkUnit[x]*price[x];
  			milk -= milkUnit[x];
		}
		else{
			total += milk*price[x];
			break;
		}
  	}
  	
  	fprintf(fout, "%ld\n", total);
  	
  	fclose(fin);fclose(fout);
    return 0;
}

void qsort(long* data, long* data2, int left, int right){		
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
		
		swap(&data[i], &data[j]);
		swap(&data2[i], &data2[j]);
	}
	
	swap(&data[i],&data[right]);
	swap(&data2[i], &data2[right]);
	
	qsort(data, data2, left,i-1);
	qsort(data, data2, i+1,right);	
}

void swap(long* a,long* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
