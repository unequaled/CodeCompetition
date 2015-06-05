/*
ID: unequal1
LANG: C++
PROG: wormhole
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(long* ,long* );
void qsort(long* ,long* , int , int );
long power(int );
long n(int );

int main() {
    FILE *fin  = fopen ("wormhole.in", "r");
    FILE *fout = fopen ("wormhole.out", "w");
    
    int x,y;
    int total,com;
    
    int num,count;
    long pointx[12], pointy[12], list[12], temp;
    
    fscanf(fin,"%d\n",&num);
    for(x=0;x<num;x++){
       fscanf(fin,"%ld %ld\n", &pointx[x],&pointy[x]);
	   list[x] = 0;
    }
    
	qsort(pointy,pointx,0,num-1);
	
	for(x=1, count=1, temp=pointy[0], y=0 ;x<num;x++){
        if(temp == pointy[x]){            
            count++;
        }
        else{
            list[y] = count;
            count = 1;
            temp = pointy[x];
            y++;
        }   
    }	   
	list[y] = count;  y++;	
	
    
	fprintf(fout,"%ld\n", total);
	fclose(fin);fclose(fout);
    return 0;
}
long power(int n){
    long total=1;
    int x;
    for(x=0;x<n;x++)
        total *=2;
    return total;
}

long n(int n){
    int x;
    long temp = 1;
    for(x=1;x<=n;x++)
        temp *= x;
    return temp;
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
