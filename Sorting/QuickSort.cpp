#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

// implementation-1
// both i and j form left
int partition(int arr[],int low,int high){
	
	int n = high-low+1;
	int pivot = arr[high];
	int i = low-1,j;
	for(j = low ;j<= high-1; j++){
		
		if (arr[j] <= pivot){
			i++;		
			swap(&arr[j],&arr[i]);	
			printArray(arr, n); 			
		}
	}
	swap(&arr[high],&arr[i+1]);
	printArray(arr, n); 	
	return i+1;
}
// implementation-2
// i from left , j form right
int partition1(int a[],int low,int high){
	int pivot  = a[high];
	int i = low,j = high-1;
	
	while(1){
		while(a[i]<pivot)
			i++;
		while(j>0 && a[j]>pivot)
			j--;
		if (i>=j)
			break;
		swap(&a[i],&a[j]);
	}
	// placing pivot at its right position
	swap(&a[high],&a[i]);
	return i;
}
int partition2(int a[],int low,int high){
	int pivot  = a[low];
	int n = high-low+1;
	int i = low+1,j = high;
	
	while(1){
		while(a[i]<pivot)
			i++;
		while(j>low && a[j]>pivot)
			j--;
		if (i>=j)
			break;
		swap(&a[i],&a[j]);
		printArray(a, n);
	}
	// placing pivot at its right position
	swap(&a[low],&a[i-1]);
	printArray(a, n);
	return i-1;
}

int partition3(int a[],int low,int high){
	int n = high-low+1;
	int pivot = a[low];
	int i = high+1,j;
	for(j = high ;j>0; j--){
		if (a[j] >= pivot){
			i--;
			swap(&a[j],&a[i]);
			printArray(a, n); 	
		}		
	}
	swap(&a[i],&a[low]);
	printArray(a, n); 	
	return i;
}

void QuickSort(int arr[],int low,int high){
	
	
	if (low < high){
		int pi = partition(arr,low,high);
		QuickSort(arr,low,pi-1);
		QuickSort(arr,pi+1,high);
		
	}
}


int main(){
	
	int arr[] = {35,33,42,10,14,19,27,44,26,31}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    QuickSort(arr, 0, n-1); 
    printf("\nSorted array: \n"); 
    printArray(arr, n); 	
	return 0;
}
