/*
ID: unequal1
LANG: C++
PROG: maze1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

#define MAX_W 39 
#define MAX_H 101

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))


char maps[MAX_H*2+1][MAX_W*2+1];
int cost[MAX_H][MAX_W];
int maps_wid, maps_hieght;

bool check_ext(int x, int y){
    if( (x*2+2 == maps_hieght-1 && maps[x*2+2][y*2+1] == ' ') ||  // down
        (x==0 && maps[0][y*2+1] == ' ')                       ||  // up
        (y*2+2 == maps_wid-1 && maps[x*2+1][y*2+2] == ' ')    ||  // right
        (y==0 && maps[x*2+1][0] == ' ') )                         // left
        return true;
    else
        return false;
}


void set_cost(int wid,int hieght){
	int x,y;
    for(x=0;x<hieght;x++)
    	for	(y=0;y<wid;y++) {
    	   cost[x][y] = MAX_W*MAX_H*2;
    }
}

void find_way(int x, int y, int count){   
    int value;
    
    cost[x][y] = count;       
        
    if(maps[x*2+2][y*2+1] == ' ' && x*2+2 != maps_hieght-1 && count+1 < cost[x+1][y])
        find_way(x+1,y,count+1);
    if(maps[x*2][y*2+1] == ' '   && x != 0 && count+1 < cost[x-1][y])
        find_way(x-1,y,count+1);
    if(maps[x*2+1][y*2+2] == ' ' && y*2+2 != maps_wid-1 && count+1 < cost[x][y+1])
        find_way(x,y+1,count+1);
    if(maps[x*2+1][y*2] == ' '  && y!=0 && count+1 < cost[x][y-1])
        find_way(x,y-1,count+1);
}


int main() {
    FILE *fin  = fopen ("maze1.in", "r");
    FILE *fout = fopen ("maze1.out", "w");
    
    int wid, hieght, value;
    int x=0,y=0;
    
    fscanf(fin,"%d %d\n", &wid, &hieght);
    maps_wid = wid*2 +1;
    maps_hieght = hieght*2+1;
	
//	for(int x=0;x<maps_hieght;x++){
//	   fscanf(fin,"%[^\n]%",maps[x]);
//        fgets(maps[x],value,fin);
//	    fprintf(fout,"%s",maps[x]);
//    }
    
    char c;
    do {        
        c = fgetc (fin);
        if(c == ' ' || c == '+' || c == '-' || c == '|' ){
            maps[x][y] = c;
            y++; 
            if(DEBUG)
	           fprintf(fout,"%c",maps[x][y]);
            if (y==maps_wid){
                x++;
                y=0;
            if(DEBUG)
            	fprintf(fout,"\n"); 
            }
        }     
    } while (c != EOF);

	   
	for(x=0;x<maps_hieght;x++){
    	for	(y=0;y<maps_wid;y++){
            if(maps[x][y] != ' ')
	           maps[x][y] = '.';
	        else
	           maps[x][y] = ' ';
	        if(DEBUG)
	           fprintf(fout,"%c",maps[x][y]);    
        }
        if(DEBUG)
            fprintf(fout,"\n");        
    }
    set_cost(wid,hieght);
    for(x=0;x<hieght;x++){
    	for	(y=0;y<wid;y++){
            if(check_ext(x,y)){
                find_way(x,y,1);                
            }            
        }
    }
    value = 0;
    for(x=0;x<hieght;x++){
    	for	(y=0;y<wid;y++){
            value = MAX(value,cost[x][y]);
            if(DEBUG)
                fprintf(fout,"%d ",cost[x][y]);	
        }
        if(DEBUG)
            fprintf(fout,"\n");	
    }

    fprintf(fout,"%d\n",value);	
	fclose(fin);fclose(fout);
    return 0;
}

