#include<stdlib.h>
#include<stdio.h>
 
int PossiblePaths(int m,int n){
 
  int Table[m][n];
  int i,j;
 
  for(i=0;i<=m; i++){
      Table[i][0] =1;
  }
 
  for(i=0;i<=n; i++){
      Table[0][i] =1;
  }
  for(i=1; i<=m; i++ ){
     for(j=1; j<=n; j++){
         Table[i][j] = Table[i-1][j] +  Table[i][j-1] +  Table[i-1][j-1];
     }
  }
  return Table[m][n];
}
 
int main(){
   printf("%d",PossiblePaths(8,8));
   return 0;
}

