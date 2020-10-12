/* Insertion operation in array - implementation in C */


#include <stdio.h>

int main()
{
	int i,ITEM = 4,K = 3,N = 5;
	int J=N;
	int A[] = {1,2,3,5,6};	
	printf("The original array elements are :\n");
    for(i = 0; i<N; i++) 	
      printf("A[%d] = %d \n", i, A[i]);   
    N = N+1;
	while(J >= K)
	{
		A[J+1] = A[J];
		J = J-1 ;
	}
	A[K] = ITEM ;
	printf("The array elements after insertion :\n");

    for(i = 0; i<N; i++)   
      printf("A[%d] = %d \n", i, A[i]);
    
	
	return 0;
}

