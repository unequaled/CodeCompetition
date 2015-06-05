/*
ID: unequal1
LANG: C++
PROG: zerosum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

char insert[9];
int num;

bool check_zero_sum(){
    char list[20];
    char last_oper = '+';
    int count=0;
    int sum=0,temp=0;
    for(int x=1;x<num;x++){
        list[count] = x + 48;
        count++;
        if(insert[x]!=' '){
            list[count] = insert[x]; 
            count++;               
        }        
    }  
    list[count] = num + 48;
    count++; 
    
    for(int x=0;x<count;x++){
        if(list[x] == '+' || list[x] == '-'){
            if(last_oper == '+'){
                sum += temp;
                temp = 0;
            }
            else{
                sum -= temp;
                temp = 0;
            }
            last_oper = list[x];
        } 
        else      
            temp = temp*10 + list[x] - 48;        
    }
    if(last_oper == '+'){
        sum += temp;
        temp = 0;
    }
    else{
        sum -= temp;
        temp = 0;
    } 
    if(sum==0)
        return true;
    else
        return false;
}

void insert_oper(int pos, FILE *fout){
    char oper[3]={' ','+','-'};
    int x;
    if(pos == num){
        if(check_zero_sum()){
            for(x=1;x<num;x++)
                fprintf(fout,"%d%c",x,insert[x]);
            fprintf(fout,"%d\n",x);
        }
    }
    else{
        for(int x=0;x<3;x++){
            insert[pos] = oper[x];
            insert_oper(pos+1,fout);
        }
    }
}


int main() {
    FILE *fin  = fopen ("zerosum.in", "r");
    FILE *fout = fopen ("zerosum.out", "w");      
    fscanf(fin,"%d\n",&num);
    insert_oper(1,fout);
	
	fclose(fin);fclose(fout);
    return 0;
}

