// To check if the elements in the given array are consecutive or not

#include <stdio.h>
#include <stdlib.h>


int min(int a[],int n){
	int i=0,m = a[0];
	for(i=1;i<n;i++){
		if (a[i]<m){
			m = a[i];
		}
	}
	return m;
}
int max(int a[],int n){
	int i=0,m = a[0];
	for(i=1;i<n;i++){
		if (a[i]>m){
			m = a[i];
		}
	}
	return m;
}

int isConsecutive(int a[],int n){
	int i=0;
	int small = min(a,n),large = max(a,n);
	if  (large-small+1 == n){
		int *visited = (int*)calloc(n,sizeof(int));
		for(i=0;i<n;i++){
			if (visited[a[i]-small] == 1)
				return 0;
			visited[a[i]-small]=1;
		}		
	}
	else
		return 0;
	return 1;		
	
}

int main(){
	int a[] = {0,-1,3,2,5,7,6,1,4};
	int n = sizeof(a)/sizeof(a[0]) ;
	if (isConsecutive(a,n))
		printf("YES, The elements are Consecutive !!\n");
	else
		printf("NO, The elements are NOT Consecutive !!\n");
	return 0;
}
