/*
ID: unequal1
LANG: C++
PROG: ariprog
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 225001

void swap(int* ,int* );
void qsort(int* , int , int );

int main() {
    FILE *fin  = fopen ("ariprog.in", "r");
    FILE *fout = fopen ("ariprog.out", "w");
    
    int length,upper_bound;
    
    int x,y,z,count,len, ans[20], ans_len;
    bool flag = false;
    bool number[MAX];
    
    fscanf(fin, "%d\n%d\n", &length, &upper_bound);
    
    for(x =0; x < MAX; x++)
        number[x] = false;
    
    for(x =0; x <= upper_bound; x++){
        for(y =0; y <= upper_bound; y++){            
           number[x*x+y*y] = true;                   
        }            
    }     
   
    count = upper_bound*upper_bound*2;
       
//    for(x =0; x <= count; x++){
//        if(number[x])
//            fprintf(fout, "%d \t", x);
//    }   
                                                    // Here are some error causing the array overflow. Need to check
    for(x =1; x <= count/(length-1); x++){          // count the interval from 1 to the possible max number
        ans_len=0;
        for(y=0;y<x;y++){                           // offset of the initial number
            len = 0;            
            for(z=0;z<=count/x;z++){                // find the platform larger than given length
                if(number[y+z*x] == true){
                    len++;
                    if(len>=length){
                        ans[ans_len] = y+(z-length+1)*x;
                        ans_len++;
                        //fprintf(fout, "%d %d\n",y+(z-length+1)*x, x);
                        flag = true;
                    }
                }
                else
                    len=0;
            }
        }
        if(ans_len > 0){
            qsort(ans,0,ans_len-1);
            for(z=0;z<ans_len;z++)
                fprintf(fout, "%d %d\n",ans[z], x);
        }
    }

    if(!flag)
        fprintf(fout, "NONE\n");
//    for(x =0; x < count; x++)
//        fprintf(fout, "%u \t", number[x]);
    
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

