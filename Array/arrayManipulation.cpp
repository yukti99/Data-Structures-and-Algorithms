#include <stdio.h>
#include <stdlib.h>

// Complete the arrayManipulation function below.
long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries){
	s
    int m = queries_rows;
    int i=0,a[n],j;
    for(i=0;i<n;i++)
        a[i] = 0;
    int x=0;
    while(m--){
    	for(j=queries[x][0]-1;j<=queries[x][1]-1;j++){
    		a[j] = a[j] +queries[x][2];
		}
		x++;
	}
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }


}

int main(){
	
	int m = 3;
	int** queries = (int**)malloc(m * sizeof(int*));
	int r = 3 , c = 3;
	int n = 5;
	arrayManipulation(n,r,c,queries);
	
	return 0;
}
