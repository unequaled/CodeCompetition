/*
ID: unequal1
LANG: C++
PROG: ride
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
bool rideCheck(char* , char* );

int main() {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char group[7], comet[7];
    fscanf (fin, "%s\n%s", group, comet);	/* the two input integers */
    if(rideCheck(group,comet))
      fprintf (fout, "%s\n", "GO");
    else
      fprintf (fout, "%s\n", "STAY");
    return 0;
}

bool rideCheck(char* group, char* comet){
    int sum = 1, mod, x;
    for(x=0; x<strlen(group); x++)
        sum = sum*(group[x]-64)%47;
    mod = sum; 
    sum = 1;                   
    for(x=0; x<strlen(comet); x++)
        sum = sum*(comet[x]-64)%47;
    if (sum == mod)
        return true;
    else
        return false;
    
}
