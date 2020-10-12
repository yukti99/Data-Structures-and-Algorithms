#include <stdio.h>
#include <stdlib.h>

void Sort(int a[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if (a[j]>a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}


int main(){
	
	int T,n,i,j,k;
	scanf("%d",&T);
	while(T--){
		
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&k);
		int item = a[k];
		// deletion of element at  k
		for(i=k;i<n;i++){
			a[i] = a[i+1];
		}
		Sort(a,n-1);		
		// insertion of element at  k
		for(i=n-1;i>=k;i--)
			a[i+1] = a[i];  
		
		a[k] = item;
		// printing 
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}	

	return 0;
}
