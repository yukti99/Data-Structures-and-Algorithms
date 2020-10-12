/* 
C Program : handling user defines index to find elements in an array when :
1. index range is given
2.  index range with increment value is given
3.  string is given
*/

// Part-1
#include <stdio.h>

int main()
{
	int i,l,u,range,index;	
	printf("Enter the lower limit of index = ");
	scanf("%d",&l);
	printf("Enter the upper limit of index = ");
	scanf("%d",&u);
	range = u-l+1;
	printf("range = %d\n",range);
	int array[range];
	printf("Enter elements of the array = ");
	for(i=0;i<range;i++)	
		scanf("%d",&array[i]);	
	printf("Entered array : ");
	for(i=0;i<range;i++)
		printf("%d ",array[i]);
	printf("\n");	
	printf("Enter the index whose element you want to access = ");
	scanf("%d",&index);
	printf("The required element of array = %d\n",array[index -l]);	
	return 0;
}
