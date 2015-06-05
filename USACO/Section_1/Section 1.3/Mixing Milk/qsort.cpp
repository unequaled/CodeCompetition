/*
ID: unequal1
LANG: C++
PROG: qsort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM 15
void swap(int* ,int* );
void qsort(int* , int , int );

int main() {
	int arr[NUM];
	int x;	
	
	srand((unsigned) time(NULL));
	for(x=0;x<NUM;x++){		
		arr[x] = rand()%100;			
	}
	
	qsort(arr,0,NUM-1);
	
	for(x=0;x<NUM;x++){
		printf("%d ", arr[x]);	
	}
	
}
	
void qsort(int* data, int left, int right){		
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
	}
	
	swap(&data[i],&data[right]);
	qsort(data,left,i-1);
	qsort(data,i+1,right);	
}

void swap(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
