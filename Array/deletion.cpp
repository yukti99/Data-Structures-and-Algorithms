/* Deletion operation in array - implementation in C */


#include <stdio.h>

int main()
{
	int i,K = 2,N = 5;
	int J=K;
	int A[] = {1,2,8,3,4};	
	printf("The original array elements are :\n");
    
	for(i = 0; i<N; i++) 	
      printf("A[%d] = %d \n", i, A[i]);   
    
    while(J<N)
    {
    	A[J] = A[J+1];
    	J = J+1;
	}    
	N = N-1;
	printf("The array elements after deletion :\n");

    for(i = 0; i<N; i++)   
      printf("A[%d] = %d \n", i, A[i]);
    
	
	return 0;
}

