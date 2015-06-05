/*
ID: unequal1
LANG: C++
PROG: beads
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Breads{
    char colar;
    struct Breads *next, *before;
};

int main() {
    FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");
    
    int num, count, maxBreads =0 ,x, y;    
    struct Breads *index, *head, *beforeBread, *temp;
    char tempBread;
    
    fscanf (fin, "%d\n", &num);
    for (x = 0; x < num; x++){
        if(x==0){
            head =(struct Breads *) malloc(sizeof(struct Breads));
            fscanf (fin, "%c", &(head -> colar));
            beforeBread = head;           
            index = head;
        }
        else{
            index -> next =(struct Breads *) malloc(sizeof(struct Breads));
            index = index -> next;
            fscanf (fin, "%c", &(index -> colar));            
            index -> before = beforeBread;
            beforeBread = index;                        
        }
    }
    
    index -> next = head;
    head -> before = beforeBread;
    
    //index = head;
//    for(x=0; x<num*2; x++){
//        fprintf (fout, "%c", index-> colar);
//        index = index -> next;
//    }
//    
//    fprintf (fout, "\n");
//    
//    index = head -> before;
//    for(x=0; x<num*2; x++){
//        fprintf (fout, "%c", index-> colar);
//        index = index -> before;
//    }
      
    for(x=0; x<num; x++){
        index = head; 
        for(y=0; y<x ;y++)
            index = index -> next;
        
        temp = index;    
        count = 0;
        
        tempBread = temp -> colar;
        while(tempBread == 'w' || tempBread ==temp -> colar || temp -> colar =='w' ){
            if(tempBread == 'w' && tempBread != temp -> colar)
                tempBread = temp -> colar;
            if (count == num)
                break;
            count++;
            temp = temp -> next;            
        }
        
        x += count-1;
        
        temp = index -> before;
        tempBread = temp -> colar;
         while(tempBread == 'w' || tempBread ==temp -> colar || temp -> colar =='w'){
            if(tempBread == 'w' && tempBread != temp -> colar)
                tempBread = temp -> colar;
            if (count == num)
                break;
            count++;
            temp = temp -> before;            
        }
        
        if(count > maxBreads){
            maxBreads=count;         
        }       
        
    }
    fprintf (fout, "%d\n", maxBreads);
    fclose(fin);fclose(fout);
    return 0;
}
