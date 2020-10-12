#include <stdio.h>

int main()
{
	int arr[] = {1,4,4,2,3,7,6,4,2,1};
	int arr2[10];
	int n=2,i,k=0, max=1,count=1,temp,c,pos,x,j,l,f;
	for(i=0;i<10;i++)
	{
		c=1;
		f=0;	
		temp = arr[i];
		pos = i;
		for(l=0;l<k;l++)
		{
			if (arr2[l] == temp)
				f=1;
		}
		if (f==1)
			continue;
		arr2[k++] = temp;
		for(j=pos+1;j<10;j++)		
			if (arr[j] == temp)
				c++;	

		if (max < c)
		{
			max = c;
			x = i;
		}		
		if (n == arr[i])
			count++;

	}
	printf("Occurence of 2 = %d\n",count);
	printf("Element %d occurs maximum number of times = %d\n",arr[x],max);	
	return 0;
}
