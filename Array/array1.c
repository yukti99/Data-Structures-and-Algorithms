#include <stdio.h>

int main()
{
	int arr[] = {1,2,7,3,9,0,2,1,5,6,4,10};
	int a=2,b=6,i,sum=0;
	for(i=0;i<12;i++)
	{
		if (arr[i] < a && arr[i] > b)
			sum +=arr[i];
			
	}
	printf("Sum = %d\n",sum);
	
	return 0;
}
