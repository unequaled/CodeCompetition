/*
ID: unequal1
LANG: C++
PROG: holstein
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 1001
#define MAX_T 16

#define MIN(x,y) (x<y)?x:y

struct Min_req_vit {
	int types_vit[MAX_V];
};

int list_types_feeds[MAX_T][MAX_V];
bool is_feeds[MAX_T];
int cur_min_feeds;

bool is_meet_req(struct Min_req_vit list ,int num_types_vit){
	int zero = 0;
	
	for(int x=1;x <=num_types_vit;x++){
		if (list.types_vit[x] < 0)
			zero ++;	
	}
	
	if(zero == num_types_vit)
		return true;
	else
		return false;
}

int check_feed(struct Min_req_vit list, int num_types_vit, int num_types_feeds, int pos){
	int pass,take;
	if(pos > num_types_feeds){		
		return num_types_feeds;
	}
	else{
		pass = check_feed(list,num_types_vit,num_types_feeds,pos+1);
		
		for(int x=1;x <=num_types_vit;x++)
			list.types_vit[x] -= list_types_feeds[pos][x];		
		if (is_meet_req(list,num_types_vit)){
			take = 1;
			if(take >= pass)
				is_feeds[pos]=true;
			else
				is_feeds[pos]=false;
			return MIN(1,pass);
		}
		else{
			take = check_feed(list,num_types_vit,num_types_feeds,pos+1)+1;
			if(take >= pass)
				is_feeds[pos]=true;
			else
				is_feeds[pos]=false;
			return MIN(take,pass);	
		}
	}
}

int main() {
    FILE *fin  = fopen ("holstein.in", "r");
    FILE *fout = fopen ("holstein.out", "w");
    
    int num_types_vit,num_types_feeds;
    struct Min_req_vit min_req_vit;
    
    int last_true;
    
    fscanf(fin, "%d\n", &num_types_vit);    
    for(int x=1;x<=num_types_vit;x++)
    	fscanf(fin, "%d", &min_req_vit.types_vit[x]);
    
    fscanf(fin, "%d\n", &num_types_feeds); 
    for(int x=1;x<=num_types_feeds;x++)
		for(int y=1;y<=num_types_vit;y++){
			fscanf(fin, "%d", &(list_types_feeds[x][y]));
		}
	
	cur_min_feeds = num_types_feeds;
//	for(int x=1;x<=num_types_feeds;x++){
//		for(int y=1;y<=num_types_vit;y++){
//			fprintf(fout, "%d ", list_types_feeds[x][y]);			
//		}
//		fprintf(fout, "\n");
//	}
	
	fprintf(fout, "%d ",check_feed(min_req_vit,num_types_vit,num_types_feeds,1));
	for(int x=1; x <= num_types_feeds;x++)
		if(is_feeds[x])
			last_true = x;
	
	for(int x=1; x <= num_types_feeds;x++){
		if(x==last_true)
			fprintf(fout, "%d\n",x);
		else if(is_feeds[x])
			fprintf(fout, "%d ",x);			
	}	

	fclose(fin);fclose(fout);
    return 0;
}



