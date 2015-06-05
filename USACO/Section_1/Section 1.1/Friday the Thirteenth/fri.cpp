/*
ID: unequal1
LANG: C++
PROG: friday
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

bool leapYear(int );
int fridayInMonth(int , int , bool , int* );

int main() {
	FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
    
    int week[7] = {0,0,0,0,0,0,0};
    int x, y, num, index = 1;
    long days;
    
    fscanf (fin, "%d\n", &num);
    for(x=0;x<num;x++){
    	for(y=1;y<13;y++)
    		index = fridayInMonth(y, index, leapYear(1900+x), week);
	}   
	for(x=0; x<6; x++)
		fprintf (fout, "%d ", week[x]);
	fprintf (fout, "%d\n", week[x]);
		
	fclose(fin);fclose(fout);
    return 0;
}

bool leapYear(int year){
	if(year%400 == 0 || (year%4 == 0 && year%100 !=0))
		return true;
	else
		return false;	
}

int fridayInMonth(int month, int index, bool leap, int* week){
	if (month == 1 ||month == 3 ||month == 5 ||month == 7 ||month == 8 ||month == 10 ||month == 12){
		week[(index+13)%7] += 1;
		return (index+31)%7;
	}
	else if(month == 4 ||month == 6 ||month == 9 ||month == 11){
		week[(index+13)%7] += 1;
		return (index+30)%7;
	}
	else if(leap){
		week[(index+13)%7] += 1;
		return (index+29)%7;
	}
	else{
		week[(index+13)%7] += 1;
		return (index+28)%7;
	}
}
