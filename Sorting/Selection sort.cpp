/* Selection Sort : shifts the smallest element towards left in each, array gets sorted from the left side */

#include <stdio.h>

int main(){
	
	int n=10,i,j,min_index,t;
	int A[] = {5,2,0,9,1,3,8,4,7,6};
	for(i=0;i<n;i++){
		min_index = i;
		for(j=i+1;j<n;j++){
			if(A[j]<A[min_index])
				min_index = j;
		}
		//swapping
		t = A[i];
		A[i] = A[min_index];
		A[min_index] = t;
	}
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	
	
	
}
