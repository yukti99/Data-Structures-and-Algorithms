/* 
C Program : handling user defines index to find elements in an array when :
1. index range is given
2.  index range with increment value is given
3.  string is given
*/

// Part-3
#include <stdio.h>
#include <string.h>

int main()
{
	
	int n,i,myindex;
	char index[40];
	printf("\nEnter the number of elements you want in the array = ");
	scanf("%d",&n);
	int arr[n];
	char str[n][40];	
	printf("\nEnter the elements of the array : ");
	for(i=0;i<n;i++)	
		scanf("%d",&arr[i]);
	
	
	printf("\nEntered array : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	
	printf("\nEnter the strings as index of the array : ");	
	for(i=0;i<n;i++)	
		scanf("%s",&str[i]);
	
	printf("\nEnter the index whose element you want to access = ");
	scanf("%s",&index);
	
	for(i=0;i<n;i++)	
		if (strcmp(str[i],index)==0)
		{
			myindex = i;
			break;
		}
	
	printf("\nThe required element of array = %d",arr[myindex]);
		
	return 0;
}
