/* BASIC OPERATIONS ON AN ARRAY */

#include <stdio.h>

void printarr(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main(){

	printf("BASIC OPERATIONS ON AN ARRAY\n");	
	int n,i,j,menu,item,index;
	printf("Enter the number of elements in the array = ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of the array = ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Original Array : ");
	printarr(arr,n);
	printf("What do you want to do ? \n");
	printf("1. Insertion \n");
	printf("2. Deletion  \n");
	printf("3. Search    \n");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			printf("Enter the element to be inserted = ");
			scanf("%d",&item);
			printf("Enter the positon of insertion  = ");
			scanf("%d",&index);
			index--;
			j = n;
			n = n+1;
			while(j>=index){
				j--;
				arr[j+1] = arr[j];
			}
			arr[index] = item;
			printf("Array after insertion operation : ");
			printarr(arr,n);
		case 2:
			printf("Enter the position of element to be deleted = ");
			scanf("%d",&index);
			printf("Deleting element - %d at position - %d of the array....",arr[index-1],index);
			index--;
			j = index;
			while(j<n){
				arr[j] = arr[j+1];
				j++;
			}
			n--;	
			printf("\nArray after deletion operation : ");
			printarr(arr,n);
		case 3:
			printf("Enter the element to be searched = ");
			scanf("%d",&item);
			int pos = -1;
			// Sequential Search
			for(i=0;i<n;i++){
				if (item == arr[i]){
					pos = i;
				}
			}
			if (-1 == pos)
				printf("Element NOT found!\n");
			else			
				printf("Element - %d is found at position - %d of the array\n",item,pos+1);
					

	}

	



}

