/* BUBBLE SORTING OF ARRAYS IN C */



#include <stdio.h>

void printarr(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	printf("BUBBLE SORTING OF ARRAY IN C\n");	
	int i,j,n,pass=0,comp=0,swaps=0,temp;
        printf("Enter the number of elements in the array = ");
	scanf("%d",&n);
	int arr[100];
	printf("Enter the elements of the array = ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Array before sorting : ");
	printarr(arr,n);
	printf("\n");
	for(i=0;i<n-1;i++){
		printf("Pass %d.\n",i+1);
		for(j=0;j<n-i-1;j++){
			
			if (arr[j] > arr[j+1]){
				swaps++;
				temp = arr[j];   // swapping adjacent elements
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
   			}
			comp++;
			printarr(arr,n);
		}
		printf("\n");
	}
	printf("\nArray after sorting : ");
	printarr(arr,n);
	printf("No of comparisons = %d\n",comp);
	printf("No of swaps = %d\n",swaps);

	return 0;
}

