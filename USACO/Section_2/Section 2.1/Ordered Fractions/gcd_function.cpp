/*
ID: unequal1
LANG: C++
PROG: check_gcd
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int check_gcd(int smaller_num,int larger_num){
	int temp = 1;
	
	while(temp !=0){
		temp = larger_num % smaller_num;
		larger_num = smaller_num;
		smaller_num = temp;
	}
	
	return larger_num;
}

int main(){
	printf("%d", check_gcd(703,407));
	
}
