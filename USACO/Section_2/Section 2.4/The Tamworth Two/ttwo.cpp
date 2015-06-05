/*
ID: unequal1
LANG: C++
PROG: ttwo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 10

char maps[MAP_SIZE+1][MAP_SIZE+1];
bool maps_walked[2][MAP_SIZE][MAP_SIZE];


int main() {
    FILE *fin  = fopen ("ttwo.in", "r");
    FILE *fout = fopen ("ttwo.out", "w");
    
    int farmer_pos[2],cow_pos[2];
    int farmer_dir=0,cow_dir=0;
    long count = 0;
    int dirction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    bool flag_farmer =false,flag_cow=false;
    
    for(int x=0;x<MAP_SIZE;x++)
        fscanf(fin,"%s\n",maps[x]);
        
    for(int x=0;x<MAP_SIZE;x++){
        for(int y=0;y<MAP_SIZE;y++){            
            
            if(maps[x][y] == 'F'){
                farmer_pos[0] = x;
                farmer_pos[1] = y;
                maps[x][y] = '.';
                maps_walked[0][x][y] = true;
            }
            if(maps[x][y] == 'C'){
                cow_pos[0] = x;
                cow_pos[1] = y;
                maps[x][y] = '.';
                maps_walked[1][x][y] = true;
            }       
//            fprintf(fout,"%c",maps[x][y]);     
        }
//        fprintf(fout,"\n");
    }
//    for(int x=0;x<MAP_SIZE;x++){
//        for(int y=0;y<MAP_SIZE;y++)
//            fprintf(fout,"%c",maps[x][y]);
//        fprintf(fout,"\n");
//    }
    
    while(!(farmer_pos[0] == cow_pos[0] && farmer_pos[1]== cow_pos[1])){
        if( farmer_pos[0]+dirction[farmer_dir][0] < MAP_SIZE &&
            farmer_pos[0]+dirction[farmer_dir][0] >= 0       &&
            farmer_pos[1]+dirction[farmer_dir][1] < MAP_SIZE &&
            farmer_pos[1]+dirction[farmer_dir][1] >= 0       &&  
            maps[farmer_pos[0]+dirction[farmer_dir][0]][farmer_pos[1]+dirction[farmer_dir][1]] != '*'){
            farmer_pos[0] += dirction[farmer_dir][0];
            farmer_pos[1] += dirction[farmer_dir][1];
            if(maps_walked[0][farmer_pos[0]][farmer_pos[1]])
                flag_farmer = true;
            else
                maps_walked[0][farmer_pos[0]][farmer_pos[1]] = true;
        }            
        else
            farmer_dir = (farmer_dir+1)%4;
        
        if( cow_pos[0]+dirction[cow_dir][0] < MAP_SIZE &&
            cow_pos[0]+dirction[cow_dir][0] >= 0       &&
            cow_pos[1]+dirction[cow_dir][1] < MAP_SIZE &&
            cow_pos[1]+dirction[cow_dir][1] >= 0       &&  
            maps[cow_pos[0]+dirction[cow_dir][0]][cow_pos[1]+dirction[cow_dir][1]] != '*'){
            cow_pos[0] += dirction[cow_dir][0];
            cow_pos[1] += dirction[cow_dir][1];
            
            if(maps_walked[1][cow_pos[0]][cow_pos[1]])
                flag_cow = true;
            else
                maps_walked[1][cow_pos[0]][cow_pos[1]] = true;
        }            
        else
            cow_dir = (cow_dir+1)%4;
        
        if(count> 4*MAP_SIZE*MAP_SIZE){
            count = 0;
            break;
        }        
        count++;        
    }
	
	fprintf(fout,"%d\n",count);
	
	fclose(fin);fclose(fout);
    return 0;
}

