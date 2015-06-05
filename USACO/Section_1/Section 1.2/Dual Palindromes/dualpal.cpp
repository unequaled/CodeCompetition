/*
ID: unequal1
LANG: C++
PROG: dualpal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindromic(char* );
void inttostring(int , char*, int);

int main() {
    FILE *fin  = fopen ("dualpal.in", "r");
    FILE *fout = fopen ("dualpal.out", "w");
    
    char temp[100];
    int x, count = 0, countTwo;
	int numN, strict, base;
    
    fscanf(fin, "%d %d", &numN, &strict);
    
    x = strict;
    while(count < numN){
    	x++;
    	countTwo = 0;
		for (base=2;base<11;base++){
			inttostring(x, temp, base);
			if(isPalindromic(temp)){
				countTwo++;
				if(countTwo == 2){
					fprintf (fout, "%d\n",x);
					count++;
					break;
				}				
			}
		}
	
	}  
    
    fclose(fin);fclose(fout);
    return 0;
}

bool isPalindromic(char* string){
	int x,y;	
	
	if(strlen(string) == 1){
		return true;
	}
	else{
		for(x=0, y=strlen(string)-1; x<strlen(string)/2; x++,y--)
			if(string[x]!=string[y])
				return false;					
		return true;		
	}		
}

void inttostring(int num, char* temp, int base){
	int x=0, digit;	
	
	while(num !=0){
		digit = num%base;
		num /= base;
		if(digit > 9){
			temp[x] = (char) digit + 55;
		}
		else{
			temp[x] = (char) digit + 48;
		}
		x++;
	}
	temp[x] = '\0';		
}
