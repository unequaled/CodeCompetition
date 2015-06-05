/*
ID: unequal1
LANG: C++
PROG: namenum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 16
#define MAXDICT 5000

char asciiMap(char );

struct Category{
    char num[MAX],name[MAX];    
};

int main() {
    FILE *fin  = fopen ("namenum.in", "r");
    FILE *findict  = fopen ("dict.txt", "r");
    FILE *fout = fopen ("namenum.out", "w");
    
    struct Category index[MAXDICT];
    char tempName[MAX],tempNum[MAX];
    int x, count = 0;
    bool flag;
    
            
    while(!feof(findict)){
        fscanf(findict, "%s\n", tempName);
        flag = false;
        for(x=0;x<strlen(tempName);x++){
            if(asciiMap(tempName[x]) !=0)
                tempNum[x] = asciiMap(tempName[x]);
            else{
                flag = true;
                break;
            }
        }        
        
        if(!flag){
            tempNum[x] ='\0';
            strcpy(index[count].name,tempName);
            strcpy(index[count].num,tempNum);
            count++;
        }            
    }
    
    flag = true;
    fscanf(fin, "%s\n", tempNum);
    for(x=0; x<count; x++){
        if(strcmp(index[x].num,tempNum)==0){
            fprintf(fout, "%s\n", index[x].name);
            flag = false;
        }
    }
    
    if(flag)
        fprintf(fout, "NONE\n");
    
    fclose(fin);fclose(findict);fclose(fout);
    return 0;
}

char asciiMap(char chr){
    if (chr =='A' || chr =='B' || chr =='C' )
        return '2';
    else if (chr =='D' || chr =='E' || chr =='F' )
        return '3';
    else if (chr =='G' || chr =='H' || chr =='I' )
        return '4';
    else if (chr =='J' || chr =='K' || chr =='L' )
        return '5';
    else if (chr =='M' || chr =='N' || chr =='O' )
        return '6';
    else if (chr =='P' || chr =='R' || chr =='S' )
        return '7';
    else if (chr =='T' || chr =='U' || chr =='V' )
        return '8';
    else if (chr =='W' || chr =='X' || chr =='Y' )
        return '9';  
    else
        return '0';  
}
