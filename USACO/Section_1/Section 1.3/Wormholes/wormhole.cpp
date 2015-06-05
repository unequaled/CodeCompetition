/*
ID: unequal1
LANG: C++
PROG: wormhole
*/

// Solved by watching the vedio https://www.youtube.com/watch?v=KR4iY-EfEs4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 12

long pointx[MAX_N+1], pointy[MAX_N+1], pair[MAX_N+1], next_to_point[MAX_N+1];
int num,total;

bool trap(){
    int start;
    for(int x=1; x <= num; x++){
        start = x;
        for(int y = 1; y <= num; y++){
            //printf ("%d round: start at %d now at %d\n",y,x,start);
            start = pair[next_to_point[start]];
        }
        if(start!=0)
            return true;    
    }
    return false;
}

void check_route(){
    int x;
    
    for(x=1; x<= num; x++)
        if(pair[x] == 0){            
            break;
        }
            
    if(x > num){                    // Complete all the possible combinateion.    
//        for(int x=1; x <= num; x++)
//            printf("%d -> %d ", x, pair[x]);            
//        printf("\n");

        if(trap()){            
            total++; 
//            printf("total = %d\n", total);         
        }
    }
    
    for(int y=x+1; y<=num; y++){    // This for loop will keep i and change y for different pairs.
        if(pair[y] == 0){
            pair[x] = y;
            pair[y] = x;
            check_route();
            pair[x] = 0;
            pair[y] = 0;            
        }   
    }
}

int main() {
    FILE *fin  = fopen ("wormhole.in", "r");
    FILE *fout = fopen ("wormhole.out", "w");
    
    fscanf(fin,"%d\n",&num);
    for(int x=1;x<=num;x++){
       fscanf(fin,"%ld %ld\n", &pointx[x],&pointy[x]);	   
    } 
    
    for(int x=1; x<=num; x++)   // Setup the next_to_point array by checking +x direction.
        for(int y=1; y<=num; y++)
            if(pointy[x] == pointy[y] && pointx[y] - pointx[x] > 0)
                if(pointx[next_to_point[x]] - pointx[x] > pointx[y] - pointx[x] || next_to_point[x] == 0 )
                    next_to_point[x] = y;
                    
//    for(int x=1; x <= num; x++)
//        printf("%d ", next_to_point[x]);            
//    printf("\n");
     
    check_route();
	fprintf(fout,"%d\n", total);
	fclose(fin);fclose(fout);
    return 0;
}
