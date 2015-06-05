//#!179646VO
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void){
	char s[1000];
	int count = 0, temp =0;
	
	scanf ("%[^\n]%*c", s);
	
	while(s[temp]!='\0'){
		if(s[temp] <='z' && s[temp] >= 'a')
			count += (s[temp]-'a')%3 + 1;
		else if(s[temp] == '.')
			count += 1;
		else if(s[temp] == ',')
			count += 2;
		else if(s[temp] == '!')
			count += 3;
		else if(s[temp] == ' ')
			count += 1;	
		temp++;		
	}
	printf("%d", count);
		
	return 0;
}
