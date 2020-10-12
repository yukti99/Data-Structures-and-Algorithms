#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

void swap(int *a,int *b){
	
	int t = *a;
	*a = *b ;
	*b = t ;
}
void display(int a[]){
   int i;
   printf("[");
	
   // navigate through all items 
   for(i = 0; i < SIZE; i++) {
      printf("%d ",a[i]);
   }
	
   printf("]\n");
}


int partition(int a[],int low,int high,int pivot){
	
	int left  = low;
	int right = high-1;
	
	while(1){
		while( a[left] < pivot ){
			left++;
		}
		while(a[right] > pivot && right > 0){
			right--;
		}
		if (left >= right)
			break;
		else{
			printf("\nItems swapped : %d and %d\n",a[left],a[right]);
			swap(&a[left],&a[right]);
			display(a);
		}
	}
	printf("\nPivot Swapped : %d and %d\n",a[left],a[high]);
	swap(&a[left],&a[high]);
	display(a);
	return left;
	
	
}

void QuickSort(int a[],int low,int high){
	if (low <= high){
		int pivot = a[high];
		int partitionPoint = partition(a,low,high,pivot);
		QuickSort(a,low,partitionPoint-1);
		QuickSort(a,partitionPoint+1,high);
		
	}
	else
		return ;
}

void printArray(int arr[], int size){ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main(){
	
	int a[] = {10, 7, 8, 9, 1, 5};     
    QuickSort(a, 0, SIZE-1); 
    printf("\nSorted array: \n"); 
    printArray(a, SIZE); 	
	return 0;
}
