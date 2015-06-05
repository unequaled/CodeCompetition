//#!179646VO

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void){
    int i,j,num,temp,tmpNum;
    int *intArr;
    
    
    scanf("%d", &num);
    tmpNum = num;
    
    intArr = (int *) malloc(num*2*sizeof(int));
    for (i=0; i <num; i++)
        scanf("%d %d", &intArr[i*2],&intArr[i*2+1]);
    
    //printf("%d %d", intArr[0],intArr[1]);

        
    for (i=0; i < num-1; i++){
        for(j=0; j < tmpNum -1; j++){
            if(intArr[j*2+1] < intArr[(j+1)*2+1]){
                temp = intArr[j*2];
                intArr[j*2] = intArr[(j+1)*2];
                intArr[(j+1)*2] =temp;
                temp = intArr[j*2+1];
                intArr[j*2+1] = intArr[(j+1)*2+1];
                intArr[(j+1)*2+1] =temp;
            }             
        }
        tmpNum--;   
    }
    
    //printf("\n");
    for (i=0; i <num; i++)
        printf("%d %d\n", intArr[i*2],intArr[i*2+1]);
    
    //getch();
    free(intArr);
    return 0;
}
