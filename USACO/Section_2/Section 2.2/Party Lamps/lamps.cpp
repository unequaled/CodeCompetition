/*
ID: unequal1
LANG: C++
PROG: lamps
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 101

//this problem is not really solve while the press num is odd.
// if the press num is odd, the output sequence may be worng

bool final_lamp_on[MAX_N];
bool final_lamp_off[MAX_N];
bool flag;

bool check_ans(bool *ans,int num){
	for(int x=1;x<=num;x++){
		if(final_lamp_on[x] && !ans[x])
			return false;
		if(final_lamp_off[x] && ans[x])
			return false;			
	}
	flag = true;
	return true;
}

void lamp_xor(bool* temp,bool* in_1,bool* in_2, int num){
	for(int x=1;x<=num;x++)
		temp[x]=in_1[x]^in_2[x];
}

void file_print(FILE *fout, bool* temp, int num){
	for(int x =1;x<=num;x++){
		if(temp[x])
			fprintf(fout,"1");
		else
			fprintf(fout,"0");
	}
	fprintf(fout,"\n");
}

int main() {
    FILE *fin  = fopen ("lamps.in", "r");
    FILE *fout = fopen ("lamps.out", "w");
    
    int num_lamp,num_press,temp=0; 

	bool light_button_0[MAX_N];
	bool light_button_1[MAX_N];
	bool light_button_2[MAX_N];
	bool light_button_3[MAX_N];
	bool light_button_4[MAX_N];
	bool temp_light[MAX_N];
   
    fscanf(fin,"%d\n",&num_lamp);
    fscanf(fin,"%d\n",&num_press);
	while(temp != -1){
		fscanf(fin,"%d",&temp);
		if(temp != -1)
			final_lamp_on[temp] = true;
	}
	temp = 0;
	while(temp != -1){
		fscanf(fin,"%d",&temp);
		if(temp != -1)
			final_lamp_off[temp] = true;
	}

	for(int x =1;x<=num_lamp;x++){
		light_button_0[x] = false;
		light_button_1[x] = true;
		light_button_2[x] = false;
		light_button_3[x] = false;
		light_button_4[x] = false;
		if(x%2 == 1)
			light_button_2[x]= true;
		else
			light_button_3[x]= true;
		if(x%3==1)
			light_button_4[x]= true;
	}	
	
	if(num_press%2 == 0){
		if (num_press==0){
			if(check_ans(light_button_1,num_lamp))
				file_print(fout, light_button_1, num_lamp);	
		}
		else{
			// press 2 3
			if(check_ans(light_button_0,num_lamp))		
				file_print(fout, light_button_0, num_lamp);	
			
			// press 3 4
			lamp_xor(temp_light,light_button_4,light_button_2,num_lamp);
			if(check_ans(temp_light,num_lamp))
				file_print(fout, temp_light, num_lamp);	
				
			//press 1 2
			if(check_ans(light_button_3,num_lamp))
				file_print(fout, light_button_3, num_lamp);	
			
			if(num_press > 3){
			//press 1 2 3 4
			lamp_xor(temp_light,light_button_4,light_button_1,num_lamp);
			if(check_ans(temp_light,num_lamp))
				file_print(fout, temp_light, num_lamp);				
		  	}
			
			// press 1 4	
			if(check_ans(light_button_4,num_lamp))		
				file_print(fout, light_button_4, num_lamp);	
			
			//press 1 3
			if(check_ans(light_button_2,num_lamp))
				file_print(fout, light_button_2, num_lamp);		

			// press 2 4			
			lamp_xor(temp_light,light_button_4,light_button_3,num_lamp);
			if(check_ans(temp_light,num_lamp))
				file_print(fout, temp_light, num_lamp);				

				
			// press 1 1
			if(check_ans(light_button_1,num_lamp))
				file_print(fout, light_button_1, num_lamp);	
		}
	}
	else{
		
		if(check_ans(light_button_0,num_lamp))
			file_print(fout, light_button_0, num_lamp);	
		if(check_ans(light_button_2,num_lamp))
			file_print(fout, light_button_2, num_lamp);		
		if(check_ans(light_button_3,num_lamp))
			file_print(fout, light_button_3, num_lamp);	
		
		//press 4	
		lamp_xor(temp_light,light_button_4,light_button_1,num_lamp);
			if(check_ans(temp_light,num_lamp))
				file_print(fout, temp_light, num_lamp);			
				
		if(num_press!=1){
			if(check_ans(light_button_4,num_lamp))
				file_print(fout, light_button_4, num_lamp);
				
			lamp_xor(temp_light,light_button_4,light_button_2,num_lamp);
			if(check_ans(temp_light,num_lamp))
				file_print(fout, temp_light, num_lamp);
			lamp_xor(temp_light,light_button_4,light_button_3,num_lamp);
			if(check_ans(temp_light,num_lamp))
				file_print(fout, temp_light, num_lamp);
				
		}
	}
	
	if(!flag)
		fprintf(fout,"IMPOSSIBLE\n");
	
	fclose(fin);fclose(fout);
    return 0;
}

