//#!179646VO

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void){
    int i,j,num,temp;
    long *intArrA;
    int *intArrB;    
    
    scanf("%d", &num);  
    
    intArrA = (long *) malloc(num*sizeof(long));
    intArrB = (int *) malloc(num*sizeof(int));
    for (i=0; i <num; i++)
        scanf("%ld %d", &intArrA[i],&intArrB[i]);
    
    //printf("%d %d", intArr[0],intArr[1]);

        
    for (i=100; i >= 0; i--){
        for(j=0; j < num; j++){
            if(intArrB[j] == i){
                printf("%ld %d\n", intArrA[j],intArrB[j]);
            }             
        }          
    }
    
    //printf("\n");   
    
    //getch();
    free(intArrA);free(intArrB);
    return 0;
}
