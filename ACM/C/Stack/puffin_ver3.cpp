#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void stackAns(char* , char *, char *);
bool answerCheck(char* , char *, char *);
char* change10_2(double ,char*, int );

#define STACK_MAX 1024
class Stack {
    private:
        char       data[STACK_MAX];
        int        size;

    public:
        Stack() {       // Constructor
            size = 0;
        }

        ~Stack() { }    // Destructor

        int Top() {

            if (size == 0) {
                fprintf(stderr, "Error: stack empty\n");
                return -1;
            }
            return data[size-1];
        }

        void Push(char d) {
            if (size < STACK_MAX){			
                data[size] = d;
                size++;
                //printf("data = %s, size = %d\n",data, size);
        	}
			else
                fprintf(stderr, "Error: stack full\n");
        }

        char Pop() {

            if (size == 0)
                fprintf(stderr, "Error: stack empty\n");
            else{
				char temp;
				size--;
				temp = data[size];                
                return temp;
            }
        }
        
        int Num(){
        	return size;
		}
};

int main(void){
	char inputA[1024] = {0}, inputB[1024] = {0}, output[1024] = {0};
	FILE *pf;
	pf=fopen("in.txt","r");
	while(!feof(pf)){	
		fscanf(pf,"%s",inputA);
		fscanf(pf,"%s",inputB);
		//printf("%d\n",strlen(inputA));
		//printf("%d\n",strlen(inputB));
		
		//scanf("%s\n%s",inputA,inputB);
		//if (strcmp(inputA,""))
		//	break;		
		stackAns(inputA,inputB,output);
		//printf("%s\n%s\n",inputA,inputB);
	}
	fclose(pf);
	return 0;
}

void stackAns(char* inA, char *inB, char *out){
	double possibleAnws = 1 << strlen(inA)*2, i;
	int x, len;
	char temp[2048] ;	
	//printf("%d\n",possibleAnws);
	printf("[\n");
	for (i = 0; i<possibleAnws; i++){
		change10_2(i,temp,strlen(inA)*2-1);	
			
		if (answerCheck(inA, inB, temp)){		
				
			len = strlen(temp);
			for(x =0 ; x < len ; x++){
				if(x == len-1)
					printf("%c\n",temp[x]);		
				else
					printf("%c ",temp[x]);		
			}					
		}		
  	}
  	printf("]\n");
}

char* change10_2(double i,char* s, int dig){
    char* ptr=s;
    while ((i/2)>0 || dig > 0){
        *ptr++=(fmod(i,2)==0)?'o':'i';
        i/=2;
		dig--;           
    }
    *ptr++=(fmod(i,2)==0)?'o':'i';
    *ptr='\0';
    return strrev(s);  
}

bool answerCheck(char* inA, char *inB, char *in){
	Stack stack;	
	char temp[1024],countIn=0, countOut=0;
	if(in[0]!='i' || in[strlen(in)-1]!='o')
		return false;		
	for(int x =0; x< strlen(in); x++){		
		if(in[x] == 'i'){			
			stack.Push(inA[countIn]);				
			//printf("in = %c \n",inA[countIn]);			
			countIn++;
		}	
		else{
			if(stack.Num() == 0)
				return false;
			else{			
				temp[countOut] = stack.Pop();
				//printf("out = %c\n",temp[countOut]);	
				countOut++; 
			}
		}
	}
	//printf("temp = %s \n",temp);
	//printf("inB = %s \n",inB);
	if(strcmp(temp,inB) == 0)
		return true;		
	else
		return false;
}
