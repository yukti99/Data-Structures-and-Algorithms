/* 
C Program : handling user defines index to find elements in an array when :
1. index range is given
2.  index range with increment value is given
3.  string is given
*/

// Part-2
#include <stdio.h>

int main()
{
	int i,l,u,range,myindex,f=0;
	float inc,index;
	printf("Enter the lower limit of index = ");
	scanf("%d",&l);
	printf("Enter the upper limit of index = ");
	scanf("%d",&u);
	printf("Enter the step value / increment of indices = ");
	scanf("%f",&inc);
	
	range = (int)((u-l)/inc + 1);	
	printf("range = %d\n",range);
	
	int arr[range];
	float user[range];
	
	for(i=0;i<range;i++)
		user[i] = l + i*(inc);
	
	printf("\nIndex array : ");
	for(i=0;i<range;i++)
		printf("%f  ",user[i]);

					
	printf("\nEnter elements of the array = ");
	for(i=0;i<range;i++)	
		scanf("%d",&arr[i]);
		
	printf("\nEntered array : ");
	for(i=0;i<range;i++)	
		printf("%d ",arr[i]);

	printf("\nEnter the index whose element you want to access = ");
	scanf("%f",&index);

	for(i=0;i<range;i++)	
		if (user[i] == index )
		{
			f=1;
			myindex = i;
			break;
		}
	if (f==0)
		printf("The Entered index is wrong!\n");
	else				
		printf("\nThe required element of array = %d\n",arr[myindex]);
		
	return 0;
}
