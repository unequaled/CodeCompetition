/*
ID: unequal1
LANG: C++
PROG: concom
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COM 101

int com_relation[MAX_COM][MAX_COM];

void debug(){
    for(int x=1;x<MAX_COM;x++)  {    
        for(int y=1;y<MAX_COM;y++)
	       printf("%d ",com_relation[x][y]);
	    printf("\n");
    }   
    printf("=====================\n"); 
}

int main() {
    FILE *fin  = fopen ("concom.in", "r");
    FILE *fout = fopen ("concom.out", "w");
    
    int num,i,j,temp;
    int sub_set[MAX_COM];
    bool check_update[MAX_COM],flag=true;
    
    fscanf(fin,"%d\n",&num);
    for(int x=0;x<num;x++){
        fscanf(fin,"%d %d %d\n",&i,&j,&temp);
        com_relation[i][j]=temp;
    }
	
//	debug();
	
	for(int x=1;x<MAX_COM;x++){
        
        for(int y=1;y<MAX_COM;y++){
            sub_set[y] = 0;
            check_update[y] = false;
        }
        
        flag = true;
        while(flag){
            flag = false;
            for(int y=1;y<MAX_COM;y++){                
                if(com_relation[x][y] >= 50 && !check_update[y]){
                    check_update[y] = true;
                    flag = true;
                    for(int z=1;z<MAX_COM;z++)
                        //com_relation[x][y] += com_relation[y][z]; 
                        sub_set[z] += com_relation[y][z]; 
                }
            }
            for(int y=1;y<MAX_COM;y++){
                com_relation[x][y] += sub_set[y];
                if(com_relation[x][y]>100)
                    com_relation[x][y] = 100;
                sub_set[y] = 0;
            }
//            debug();
        }
        
        for(int y=1;y<MAX_COM;y++){
//            fprintf(fout,"%d %d %d\n", x,y,com_relation[x][y]);
            //com_relation[x][y] += sub_set[y];
            if(com_relation[x][y] >= 50 && x!=y ){
                fprintf(fout,"%d %d\n", x,y);
            }
        }
//        debug();   
    }
	
	
	fclose(fin);fclose(fout);
    return 0;
}

