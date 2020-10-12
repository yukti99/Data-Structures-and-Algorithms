/* Bubble Sort - implementation in C */
#include <stdio.h>

int main()
{
	
	int N=10,temp;
	int A[] = {5,2,0,9,1,3,8,4,7,6};
	for(int i=0;i<N-1;i++)
		for(int j=0;j<N-i-1;j++)
			if (A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
	for(int i=0;i<N;i++)
		printf("%d ",A[i]);
	
	
   	return 0;
}

