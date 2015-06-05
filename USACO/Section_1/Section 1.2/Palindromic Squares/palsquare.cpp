/*
ID: unequal1
LANG: C++
PROG: palsquare
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindromic(char* );
void inttostring(unsigned , char*, int);
void reverse(char*);

int main() {
    FILE *fin  = fopen ("palsquare.in", "r");
    FILE *fout = fopen ("palsquare.out", "w");
    
    unsigned int base;
    char temp[100],num[100];
    int x;
    
    fscanf(fin, "%d\n", &base);
    
    for(x=1;x<301;x++){
    	inttostring(x*x, temp, base);
    	if(isPalindromic(temp)){    		
			inttostring(x, num, base);
			reverse(num);
			fprintf (fout, "%s %s\n", num, temp);			
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

void reverse(char* string){
	int x,y;
	char temp;
	
	if(strlen(string) > 1){		
		for(x=0, y=strlen(string)-1; x<strlen(string)/2; x++,y--){
			temp = string[x];
			string[x] =string[y];
			string[y] = temp;				
		}
	}
}

void inttostring(unsigned num, char* temp, int base){
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
