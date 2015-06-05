#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void stackAns(char* , char *,char *);

int N;
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


int main(void) { 
	char inputA[STACK_MAX] = {0}, inputB[STACK_MAX] = {0}, output[STACK_MAX*2] = {0};
	scanf("%s\n%s",inputA, inputB);	
	stackAns(inputA,inputB,output);
} 

void stackAns(char* inA, char *inB,char *out){
	int len = strlen(inA),i;
	for(i =0; i<len; i++)
		out[i]='i';		
	for(; i< len*2 ; i++)
		out[i]='o';
	
	printf("%s\n",out);
}


