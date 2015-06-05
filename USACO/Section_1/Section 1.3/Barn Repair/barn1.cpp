/*
ID: unequal1
LANG: C++
PROG: barn1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void qsort(int* , int , int);
void swap(int* ,int* );

int main() {
    FILE *fin  = fopen ("barn1.in", "r");
    FILE *fout = fopen ("barn1.out", "w");
    
    int boards,stalls,numOccupy;
    int *list, *largeSpace;    
    bool* map;
    
    int x,count;
    bool flag;
    
    fscanf(fin, "%d %d %d\n", &boards, &stalls, &numOccupy);
    list = (int*) malloc(sizeof(int)*numOccupy);
    for(x=0; x<numOccupy;x++)
    	fscanf(fin, "%d\n", &list[x]);
        
    qsort(list, 0, numOccupy-1);
    map = (bool*) malloc(sizeof(bool)*stalls);
    
    for(x=0; x<stalls;x++)
    	map[x] = false;
    
    for(x=0; x<numOccupy;x++)
    	map[list[x]] = true;	
	
	if(boards-1 == 0)
		fprintf(fout, "%d\n", list[numOccupy-1] - list[0] + 1);
	else{
		largeSpace = (int*) malloc(sizeof(int)*(boards-1));
		for(x=0; x<boards-1;x++)
			largeSpace[x] = 0;
		
		flag = true;
		count = 0;		
		for(x=list[0]; x<=list[numOccupy-1];x++){
			if(map[x]){
				if(!flag){
					flag = true;
					if(count > largeSpace[0]){
						largeSpace[0] = count;
						qsort(largeSpace, 0, boards-1-1);
					}					
					count = 0;
				}									
			}
			else{
				flag = false;
				count++;
			}
		}
		
		count = 0;
		for(x=0; x<boards-1;x++)
			count += largeSpace[x];
		fprintf(fout, "%d\n", list[numOccupy-1] - list[0] - count +1);
	}   
    
    fclose(fin);fclose(fout);
    return 0;
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
