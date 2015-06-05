/*
ID: unequal1
LANG: C++
PROG: castle
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Note{
	int room;
	bool visit;
	struct Note* root;
};

struct Note notes[50][50], *cur_root;
int map[50][50];
int raw,column;

int depth_first_search(int , int );
void walls(int ,bool*);

int main() {
    FILE *fin  = fopen ("castle.in", "r");
    FILE *fout = fopen ("castle.out", "w");   
        
    fscanf(fin, "%d %d\n", &column,&raw);
    
    int number_rooms=0,largest_space=0,largest_space_by_remove=0;    
	int largest_space_note_x,largest_space_note_y;
    char remove_wall;
    
    //create graph and note array
//	notes = (struct Note**) malloc(sizeof(struct Note*)*raw);
//	map = (int **) malloc(sizeof(int*)*raw);
//    for(int x=0;x<raw;x++){    	
//    	notes[x] = (struct Note *) malloc(sizeof(struct Note)*column);
//    	map[x] = (int *) malloc(sizeof(int)*raw);
//    }
    
    for(int x=0;x<raw;x++)
    	for(int y=0;y<column;y++){
    		notes[x][y].room = 0;
    		notes[x][y].visit = false;    		
    		fscanf(fin,"%d",&map[x][y]);
    	}
    
    for(int x=0;x<raw;x++)
    	for(int y=0;y<column;y++){
			if(!notes[x][y].visit){
				// set the pointer to the root for counting the room space lined with the root
				cur_root = &notes[x][y];				
				notes[x][y].room = depth_first_search(x,y);
				
				number_rooms++;
				if(notes[x][y].room > largest_space)
					largest_space = notes[x][y].room;
			}	
		}	
	for(int y=0;y<column;y++)
		for(int x=raw-1;x>=0;x--){
    		bool note_walls[4];  
		
			walls(map[x][y], note_walls);	
			
			if(note_walls[0]){
				if(y-1 >= 0 && notes[x][y].root != notes[x][y-1].root)
					if(notes[x][y].root->room + notes[x][y-1].root->room > largest_space_by_remove){
						remove_wall = 'W';
						largest_space_note_x = x; largest_space_note_y=y;
						largest_space_by_remove = notes[x][y].root->room + notes[x][y-1].root->room;
					}
			}
			if(note_walls[1]){
				if(x-1 >= 0 && notes[x][y].root != notes[x-1][y].root)
					if(notes[x][y].root->room + notes[x-1][y].root->room > largest_space_by_remove){
						remove_wall = 'N';
						largest_space_note_x = x; largest_space_note_y=y;
						largest_space_by_remove = notes[x][y].root->room + notes[x-1][y].root->room;
					}				
			}
			if(note_walls[2]){
				if(y + 1 < column && notes[x][y].root != notes[x][y+1].root)
					if(notes[x][y].root->room + notes[x][y+1].root->room > largest_space_by_remove){
						remove_wall = 'E';
						largest_space_note_x = x; largest_space_note_y=y;
						largest_space_by_remove = notes[x][y].root->room + notes[x][y+1].root->room;
					}
	
			}
			if(note_walls[3]){
				if(x+1 < raw && notes[x][y].root != notes[x+1][y].root)
					if(notes[x][y].root->room + notes[x+1][y].root->room > largest_space_by_remove){
						remove_wall = 'S';
						largest_space_note_x = x; largest_space_note_y=y;
						largest_space_by_remove = notes[x][y].root->room + notes[x+1][y].root->room;
					}			
    		}
		}
		    
	
	fprintf(fout,"%d\n", number_rooms);  
	fprintf(fout,"%d\n", largest_space);  
	fprintf(fout,"%d\n", largest_space_by_remove);  
	fprintf(fout,"%d %d %c\n", largest_space_note_x+1, largest_space_note_y+1, remove_wall);  
//    for(int x=0;x<raw;x++){
//    	for(int y=0;y<column;y++)
//    		fprintf(fout,"%d\t", map[x][y]);    
//    		fprintf(fout,"%d\t",notes[x][y].root->room);
//		fprintf(fout,"\n");
//	}
	
	
	fclose(fin);fclose(fout);
    return 0;
}

int depth_first_search(int x, int y){
	if(notes[x][y].visit)
		return 0;
	
	else{
		bool note_walls[4];		
		//self-space
		int room_space = 1;			
		
		notes[x][y].root = cur_root;
		notes[x][y].visit = true;
		
		walls(map[x][y], note_walls);	
		
		if(!note_walls[0])
			room_space += depth_first_search(x,y-1);
		if(!note_walls[1])
			room_space += depth_first_search(x-1,y);
		if(!note_walls[2])
			room_space += depth_first_search(x,y+1);
		if(!note_walls[3])
			room_space += depth_first_search(x+1,y);
		
		return room_space;
	}
}

void walls(int value, bool* array){
	int count = 0;
	
	while(count<4 && value < 16){
		if(value%2 == 1)
			*(array+count) = true;
		else
			*(array+count) = false;
		value /= 2;
		count++;
	}
}
