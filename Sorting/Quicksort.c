#include <stdio.h>
#include <stdlib.h>


void display(int a[],int n){
	int i;
	printf("\nAfter Each Pass : ");
	printf("\n[");	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("]\n");
} 

void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int Partition(int a[],int n,int low,int high,int pivot){
	int i = low;
	int j = high-1;
	while(1){
		while(a[i]<pivot)
			i++;
		
		while(j>0 && a[j]>pivot)
			j--;
			
		if (i>=j)
			break;
		else{
			printf("\nSwapped Elements : %d and %d\n",a[i],a[j]);
			swap(&a[i],&a[j]);
			display(a,n);
		}
	}
	printf("\nSwapped Elements : %d and %d\n",a[i],a[high]);
	swap(&a[i],&a[high]);
	display(a,n);
	return i;

}


void QuickSort(int a[],int n,int left,int right){
	if (left>=right)
		return ;
	else{
		// making the rightmost value as pivot
		int pivot = a[right];
		printf("\nPivot = %d\n",pivot);
		int partition = Partition(a,n,left,right,pivot);
		QuickSort(a,n,left,partition-1);
		QuickSort(a,n,partition+1,right);
	}
	

}
void print(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

}

int main(){


	int i,n;
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the Elements of the array : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	printf("\nQUICK SORT\n");
	
	printf("\nBefore Sorting : \n");
	print(a,n);
	QuickSort(a,n,0,n-1);
	printf("\nAfter Sorting : \n");
	print(a,n);
	
	return 0;
}
