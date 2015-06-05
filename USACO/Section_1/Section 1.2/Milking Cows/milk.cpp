/*
ID: unequal1
LANG: C++
PROG: milk2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *fin  = fopen ("milk2.in", "r");
    FILE *fout = fopen ("milk2.out", "w");
    
   	long feed=0 , noFeed=0, feedEnd = 0, feedStart =1000000, count;
    long **feedTime;
    int num,x,y;
    bool time[1000000], flag;
    
    for(x=0;x<1000000;x++)
    	time[x] = false;
    
    fscanf(fin,"%d\n", &num);
    feedTime = (long **) malloc(sizeof(long *)*num);
    for(x=0;x<num;x++){
    	feedTime[x] = (long *) malloc(sizeof(long )*2);    	
    	fscanf(fin,"%d %d\n", &feedTime[x][0], &feedTime[x][1]);
	}
    
    for(x=0;x<num;x++){
    	for(y = feedTime[x][0]; y < feedTime[x][1]; y++)
    		time[y] = true;
    	if(feedEnd < feedTime[x][1])
    		feedEnd = feedTime[x][1];
    	if(feedStart > feedTime[x][0])
    		feedStart = feedTime[x][0];
    }
    
    flag = time[feedStart];
    count = 0;
    for(x=feedStart;x<=feedEnd;x++){
    	if(time[x] != flag){
    		if(flag){
    			if(feed < count)
    				feed = count;
			}
			else{
				if(noFeed < count)
    				noFeed = count;
			}
    		flag = time[x];
    		count = 1;
		}
		else
			count++;    		
	}
    
    fprintf (fout, "%d %d\n", feed, noFeed);
    
    fclose(fin);fclose(fout);
    return 0;
}
