#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

long pow(int x, int y){
    long result = 1;
    for(int z=0;z<x;z++)
        result *= y;   
    return result; 
}

void swap(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

long palindromes_generator(long num, int odd ){
    int palindromes[10],temp=0,count=0;
    
    while(num != 0){
        palindromes[count] = num%10;
        num /= 10; count++; 
    }
    for(int x =0; x < count/2; x++)
        swap(&palindromes[x],&palindromes[count-x-1]);    
    
    if(odd == 1)                
        for(int x =0; x < count - 1; x++)
            palindromes[2*(count-1)-x] = palindromes[x];    
    else
        for(int x =0; x < count; x++)
            palindromes[2*count-x-1] = palindromes[x];

    for(int x=0;x<count*2-odd;x++)
        temp += palindromes[x]*pow(x,10);
    
    return temp;           
}

int main(){
    printf("%ld\n", palindromes_generator(123, 0));
    getch();
    return 0;
}
