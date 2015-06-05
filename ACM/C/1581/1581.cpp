//#!179646VO
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void){
	int num,x, count=0, rem = 0;
	int *array;
	
	scanf("%d",&num);
	array = (int*) malloc(num*sizeof(int));
	for (x =0; x<num; x++)
		scanf("%d",  (array+x));
	
	for (x =1, rem=array[0], count = 1; x<num; x++){
		if (array[x]!=rem){		
			if( x != num-1)
				printf("%d %d ", count,rem);
			else{
				printf("%d %d ", count,rem);
				printf("1 %d", array[x]);
			}
			rem = array[x];
			count =1;
		}	
		else{
			count++;
			if( x == num-1)
				printf("%d %d", count,rem);
		}
	}
	
	if(num == 1)
		printf("%d %d", count,rem);
	
	return 0;
}
