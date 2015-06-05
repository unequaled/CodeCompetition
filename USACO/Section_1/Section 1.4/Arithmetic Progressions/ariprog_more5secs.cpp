/*
ID: unequal1
LANG: C++
PROG: ariprog
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 65535

void swap(unsigned int* ,unsigned int* );
void qsort(unsigned int* , int , int );
int  remove_redundant(unsigned int* , int );

int main() {
    FILE *fin  = fopen ("ariprog.in", "r");
    FILE *fout = fopen ("ariprog.out", "w");
    
    int length,upper_bound, count=0;
    unsigned int number[MAX];
    
    int x,y,z,temp, diff;
    bool flag = false;
    
    fscanf(fin, "%d\n%d\n", &length, &upper_bound);
    
    for(x =0; x <= upper_bound; x++){
        for(y =0; y <= upper_bound; y++){
            number[count] = x*x+y*y;            
            count++;            
            //fprintf(fout, "%d \t", x*x+y*y);
        }
        //fprintf(fout, "\n");        
    } 
        
    count = remove_redundant(number,count);
    
    //fprintf(fout, "%d \n", number[count-1]/(length-1));
    
    for(x =1; x <= number[count-1]/(length-1); x++){
        temp = 0;
        for(y = 0; y < count; y++){
            diff=1;
            for(z = y+1 ; z < count ; z++){
                if(number[z] - number[y] > diff*x)
                    break;
                if(number[z] == number[y] + diff*x){
                    diff++;
                    if(diff == length){
                        fprintf(fout, "%u %d\n", number[y],x);
                        flag = true;
                        break;
                    }                
                }                    
            }                
        }           
    }

    if(!flag)
        fprintf(fout, "NONE\n");
//    for(x =0; x < count; x++)
//        fprintf(fout, "%u \t", number[x]);

    
	fclose(fin);fclose(fout);
    return 0;
}

int remove_redundant(unsigned int* data, int num){
    int x;
    unsigned int temp = data[0], max = data[num-1];
    
    qsort(data,0,num-1);
    
    for(x=1;x<num;x++){
        if(temp == data[x])
            data[x] = max;
        else
            temp = data[x];        
    }
    
    qsort(data,0,num-1);

    for(x=1;x<num;x++){
        if(max == data[x])
            return x+1;
    }
}

void qsort(unsigned int* data, int left, int right){		
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

void swap(unsigned int* a,unsigned int* b){
	unsigned int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
