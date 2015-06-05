//#!179646VO
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
double mem[45];
double flag(int);

int main(void){
	int num;
	scanf("%d",&num);	
	printf("%.0lf",flag(num));
	return 0;
}

double flag(int n){	
	int i;
	for(i=0; i<n; i++){		
		if(i==0){
			mem[i] = 2;				
		}
		else if(i==1){
			mem[i] = 2;	
		}
		else
			mem[i] = mem[i-1] + mem[i-2] ;
		//printf("%d = %lf\n",i,mem[i]);	
	}
	return mem[n-1];
}
