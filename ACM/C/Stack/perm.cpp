#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
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

int N;
char inA[STACK_MAX] , inB[STACK_MAX] ; 
void perm(char*, int, void (*)(char*));
void rotate(char*, int, int);
void copy(char*, char*);
void print(char*);
bool answerCheck(char*);

int main(void) { 
	char output[STACK_MAX*2] = {0};
	int len,x;
	
    scanf("%s\n%s",inA,inB);
    
	len = strlen(inA)-1;
    for(x= 1 ; x <len*2; x+=2){
    	output[x]='i';
    	output[x+1]='o';
	}
    output[0] = 'i'; output[x] = 'o';
        
    N = strlen(inA)*2;
    perm(output, 0, print); 
    return 0; 
} 

void perm(char* num, int i, void (*take)(char*)) { 
    if(i < N) { 
        int j;
        for(j = i; j < N; j++) {
            char to[N];
            copy(num, to);
            rotate(to, i, j);
            perm(to, i + 1, take); 
        } 
    } else { take(num); }
}  

void rotate(char* num, int i, int j) {
    char tmp = num[j]; 
    int k;
    for(k = j; k > i; k--) {
        num[k] = num[k - 1]; 
    }
    num[i] = tmp;
}

void copy(char* from, char* to) {
    int i;
    for(i = 0; i < N; i++) {
        to[i] = from[i];
    }
}

void print(char* temp) {   
    printf("%s\n", temp); 
//	int len,x;      
//	if(answerCheck(temp)){	
//		len = strlen(temp);
//		for(x =0 ; x < len ; x++){
//			if(x == len-1)
//				printf("%c\n",temp[x]);		
//			else
//				printf("%c ",temp[x]);		
//		}		
//	}	
}

bool answerCheck(char *in){
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
