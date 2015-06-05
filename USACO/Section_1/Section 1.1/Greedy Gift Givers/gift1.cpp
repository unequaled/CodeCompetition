/*
ID: unequal1
LANG: C++
PROG: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int findIndex(char**, int, char*);


int main() {
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    
    char** group;
    int* groupMoney;
    
    char tempName[15];
    int num,index,money,costgift,people,x;    
    fscanf (fin, "%d\n", &num);
    
    group = (char**) malloc(num*sizeof(char*));
    groupMoney = (int *) malloc(num*sizeof(int));
    
    for(x=0; x<num; x++){
        *(group+x) =(char*) malloc(15*sizeof(char));
        fscanf (fin, "%s\n", group[x]);
        groupMoney[x] = 0;
    }
    
    while(!feof(fin)){
        fscanf (fin, "%s\n", tempName);
        fscanf (fin, "%d %d\n", &money, &people);
        index = findIndex(group, num, tempName);
        if(people > 0){
            groupMoney[index] = groupMoney[index] - money + (money%people);
            costgift = money / people;
        }
        for(x=0;x<people; x++){
            fscanf (fin, "%s\n", tempName);
            index = findIndex(group, num, tempName);
            groupMoney[index] += costgift;
        }   
    }    
    
    for(x=0; x<num; x++)
        fprintf (fout, "%s %d\n", group[x], groupMoney[x]);    
    
    fclose(fin);fclose(fout);
    return 0;
}

int findIndex(char** group, int num, char* name){
    int x;
    for(x=0; x<num; x++){
        if(strcmp(group[x],name)==0)
            return x;            
    }
}
