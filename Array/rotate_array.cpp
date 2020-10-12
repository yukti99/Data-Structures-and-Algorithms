#include <stdio.h>

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n=5,i,j,k,temp,l=9;
	for(i=0;i<n;i++)
	{
		temp = arr[0];
		for(j=l-1;j>=0;j--)
		{
			k = j+1;
			if (k>=l)
				k=0;
			arr[k] = arr[j];			
		}
		arr[k] = temp;
	}
	for(i=0;i<l;i++)
	{
		printf("%d ",arr[i]);
	}
	
	
	return 0;
}
