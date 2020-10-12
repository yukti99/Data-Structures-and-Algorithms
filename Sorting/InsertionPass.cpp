/* INSERTION SORTING OF ARRAYS IN C */



#include <stdio.h>

void printarr(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	printf("INSERTION SORTING OF ARRAY IN C\n");	
	int i,j,n,pass,comp=0,swaps=0,temp,pos;
        printf("Enter the number of elements in the array = ");
	scanf("%d",&n);
	int arr[100];
	printf("Enter the elements of the array = ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Array before sorting : ");
	printarr(arr,n);
	printf("\n");
	for(i=1;i<n;i++){
		printf("Pass %d.\n",i);
		temp = arr[i];
		pos = i-1;
		comp++;
		while(pos>=0 && temp < arr[pos]){
			if (temp<arr[pos])
				comp++;
			swaps++;
			arr[pos+1] = arr[pos];
			pos--;
   		}
		arr[pos+1] = temp;
		printarr(arr,n);
		
	}
	printf("\nArray after sorting : ");
	printarr(arr,n);
	printf("No of comparisons = %d\n",comp);
	printf("No of swaps = %d\n",swaps);
	return 0;
}
