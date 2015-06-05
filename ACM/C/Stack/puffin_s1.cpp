#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stack> 

void possibleAns(char *, int, int, int, char*, char*);
bool answerCheck(char* , char *, char *);


int main(){
    int num;
    char* string;
    char inputA[1024] = {0}, inputB[1024] = {0}, output[1024] = {0};
	FILE *pf;
	
	pf=fopen("in.txt","r");
	while(!feof(pf)){
                     	
		fscanf(pf,"%s",inputA);
		fscanf(pf,"%s",inputB);
    
        num = strlen(inputA);
        string = (char *) malloc((num*2+1)*sizeof(char));
        
        printf("[\n");
        possibleAns(string, (num*2), 0, 0, inputA, inputB);
        free(string);
        printf("]\n");

          //answerCheck(inputA,inputB, "iiioioiiiooiooiiiooioooo");
        
    }
	fclose(pf);

	getch();	
	return 0;     
}

void possibleAns(char *string, int total, int pos, int countI, char* inA, char *inB){
     int x;
     if (pos - countI <= countI){
        if (countI == total/2){           
           memset((string + pos),'o', (total-pos)*sizeof(char));
           *(string + total) = '\0';
           //printf("%s\n" ,string);
           //if(strcmp(string,"iiioioiiiooiooiiiooioooo\0")==0)
           //   printf("YES");   
           
           if (answerCheck(inA, inB, string)){
               for (x=0; x < strlen(string)-1 ;x++)                   
                   printf("%c ", string[x]);
               printf("%c\n", string[x]);
           }
        }
        else{
           string[pos] = 'i';
           possibleAns(string, total, pos+1, countI+1, inA, inB);
           string[pos] = 'o';
           possibleAns(string, total, pos+1, countI, inA, inB);
        }          
     }
}

bool answerCheck(char* inA, char *inB, char *in){
	std::stack<char> stack;	
	char temp[1024],countIn=0, countOut=0;	
	for(int x =0; x< strlen(in); x++){		
		if(in[x] == 'i'){			
			stack.push(inA[countIn]);				
			//printf("in = %c \n",inA[countIn]);			
			countIn++;
		}	
		else{
			temp[countOut] = stack.top();
			stack.pop();
			//printf("out = %c\n",temp[countOut]);	
			countOut++; 			
		}
	}
	temp[countOut]='\0';
	//printf("temp = %s \n",temp);
	//printf("inB = %s \n",inB);
	if(strcmp(temp,inB) == 0){
        //printf("T");                
		return true;		
    }
	else
		return false;
}
