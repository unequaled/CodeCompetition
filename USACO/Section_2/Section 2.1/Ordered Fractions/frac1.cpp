/*
ID: unequal1
LANG: C++
PROG: frac1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Frac_list {
    int up_num,down_num;
    struct Frac_list *next;
};

int check_gcd(int smaller_num,int larger_num){
	int temp = 1;
	
	while(temp !=0){
		temp = larger_num % smaller_num;
		larger_num = smaller_num;
		smaller_num = temp;
	}
	
	return larger_num;
}

int main() {
    FILE *fin  = fopen ("frac1.in", "r");
    FILE *fout = fopen ("frac1.out", "w");
    
    int num; 
    float frac_new_node, frac_cur_node;   
    struct Frac_list *head, *index, *insert_node, *pre_node;
    
    fscanf(fin,"%d\n",&num);    
    
    head = (struct Frac_list *) malloc(sizeof(struct Frac_list));
    (*head).up_num = 0; (*head).down_num = 1;  
    
    index = (struct Frac_list *) malloc(sizeof(struct Frac_list));
    (*index).up_num = 1; (*index).down_num = 1; (*index).next = 0;
    (*head).next = index;
    
    
    for(int x=1;x<=num;x++)
        for(int y=x+1;y<=num;y++){
            frac_new_node =float(x)/y;
            insert_node = (struct Frac_list *) malloc(sizeof(struct Frac_list));
            (*insert_node).up_num = x;(*insert_node).down_num = y;
            
            index = head;
            pre_node = head;
            while(1){
                frac_cur_node = float ((*index).up_num) / (*index).down_num;
                if(frac_cur_node < frac_new_node){
                    pre_node = index;
                    index = (*index).next;
                }
                else if(check_gcd(x,y) != 1){
                    free(insert_node);
                    break;
                }
                else{
                    (*pre_node).next = insert_node;
                    (*insert_node).next = index;
                    break;
                }
            }
        }
        
    index = head;
    while(index != 0){
        fprintf(fout,"%d/%d\n", (*index).up_num,(*index).down_num);   
        index = (*index).next;
    }
	
	fclose(fin);fclose(fout);
    return 0;
}

