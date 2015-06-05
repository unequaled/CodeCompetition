#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stack> 

void possibleAns(char *, int , char *, int , char *, int, std::stack<char>);
void possibleAns(char *, int, int, int, char*, char*);
bool answerCheck(char* , char *, char *);


int main(){
    int num;
    char* string;
    char inputA[1024] = {0}, inputB[1024] = {0}, output[1024] = {0};
    std::stack<char> stack;
	FILE *pf;
	
	pf=fopen("in.txt","r");
	while(!feof(pf)){
                     	
		fscanf(pf,"%s",inputA);
		fscanf(pf,"%s",inputB);
    
        num = strlen(inputA);
        string = (char *) malloc((num*2+1)*sizeof(char));
        
        printf("[\n");
        possibleAns(string, 0, inputA, 0, inputB, 0, stack);
        free(string);
        printf("]\n");         
        
    }
	fclose(pf);

	//getch();	
	return 0;     
}

void possibleAns(char *outstr, int counrOut, char *inA, int posA, char *inB, int posB, std::stack<char> mystack){
	if(posB == strlen(inB)){
		int x;
		for(x =0;x<strlen(inB)*2 -1;x++)
			printf("%c ",outstr[x]);
		printf("%c\n",outstr[x]);
	}
	else if(posA != strlen(inA)){	
		while((mystack.size() == 0 || mystack.top() != inB[posB]) && posA != strlen(inA)){
			mystack.push(inA[posA]);
			outstr[counrOut]='i';
			posA++; counrOut++;		
		}
		
		if(posA != strlen(inA)){
            outstr[counrOut]='i'; 
            mystack.push(inA[posA]);          
			possibleAns(outstr, counrOut +1, inA,  posA +1 ,  inB,  posB, mystack);
			mystack.pop(); 
        }
		if(mystack.top() == inB[posB]){
			outstr[counrOut]='o'; mystack.pop(); 	
			possibleAns(outstr, counrOut + 1, inA,  posA,  inB,  posB+1, mystack);
		}
	}
	else if(posA == strlen(inA) && mystack.top() == inB[posB] && posB != strlen(inB)){
        outstr[counrOut]='o'; mystack.pop(); 	
		possibleAns(outstr, counrOut + 1, inA,  posA,  inB,  posB+1, mystack);		
    }	
}

