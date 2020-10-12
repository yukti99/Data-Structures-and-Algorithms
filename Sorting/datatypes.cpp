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
	int i,j,l,u,range,index,myindex;
	float inc;

	printf("Enter the lower limit of index = ");
	scanf("%d",&l);
	printf("Enter the upper limit of index = ");
	scanf("%d",&u);
	printf("Enter the step value / increment of indices = ");
	scanf("%f",&inc);	
	
	range = (u-l)/inc + 1;	
	printf("range = %d\n",range);
	
	int arr[range],user[range];
	
	for(i=0;i<range;i++)
		user[i] = l + i*(inc);
			
	printf("Enter elements of the array = ");
	for(i=0;i<range;i++)	
		scanf("%d",&arr[i]);
		
	printf("Entered array : ");
	for(i=0;i<range;i++)	
		scanf("%d",&arr[i]);			
	printf("\n");	
	
	printf("Enter the index whose element you want to access = ");
	scanf("%d",&index);
	
	for(i=0;i<range;i++)
	{
		//printf("%d",&user[i]);
		if (user[j] == index )
		{
			myindex = j;
			break;
		}
				
	}		
	printf("The required element of array = %d\n",arr[myindex]);
		
	return 0;
}
