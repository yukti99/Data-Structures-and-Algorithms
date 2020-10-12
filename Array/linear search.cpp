/* Sequential Search in array - implementation in C */


#include <stdio.h>

int main()
{
	int i,J=0,ITEM = 9,N=7;
	int A[] = {1,4,2,9,0,10,6};
	
	printf("The original array elements are :\n");
	
    for(i = 0; i<N; i++)   
   		printf("A[%d] = %d \n", i, A[i]);
   		
   	while(J<N)
   	{
   		if (A[J] == ITEM)
   			break;
   		J = J+1;
	}
   	printf("Found element %d at position %d\n", ITEM, J+1);   
  	return 0;
}

