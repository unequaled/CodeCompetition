/*
ID: unequal1
LANG: C++
PROG: crypt1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkList(int *, int , unsigned int );

int main() {
    FILE *fin  = fopen ("crypt1.in", "r");
    FILE *fout = fopen ("crypt1.out", "w");
    
    int num, list[10];
    int x,y,count;    
	    
    fscanf(fin, "%d\n", &num);
    for(x=0;x<num;x++)
    	fscanf(fin, "%d", &list[x]);
	for(x=111,count=0;x<1000;x++)
		if(checkList(list,num,x)){
			for(y=11;y<100;y++){				
				if(x*y< 10000 && x*(y%10)< 1000 && checkList(list,num,y) && checkList(list,num,x*(y%10)) && checkList(list,num,x*(y/10)) && checkList(list,num,x*y))
					count++;
					//fprintf(fout, "%d %d %d\n", x,y, x*y);
			}	
		}
    fprintf(fout, "%d\n", count);
    fclose(fin);fclose(fout);
    return 0;
}

bool checkList(int *list, int num, unsigned int total){
	int x;
	int mod;
	bool flag;
	
	while(total != 0){
		mod = total % 10;
		total = total/10;
		flag = false;
		
		for(x=0;x<num;x++)
			if(mod == list[x])
				flag = true;
		
		if(!flag)
			return false;
	}
	return true;
}
