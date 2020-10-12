/* HEAP SORT */

#include <stdio.h>
#include <stdlib.h>



void swap(int *a,int *b){
	int t = *a;
	*a = *b ;
	*b = t;
}

void heapify(int a[],int n,int i){
	
	int largest = i;
	int l = 2*i+1;   // left child
	int r = 2*i+2;   // right child
	
	// if the left child is larger than the root
	if (l<n && a[l] > a[largest])
		largest = l;
	// if the right child is larger than the largest so far
	if (r<n && a[r] > a[largest])
		largest = r;
	//  if root is not the largest
	if (i!=largest){
		swap(&a[i],&a[largest]);
		// recursively heapify the tree
		heapify(a,n,largest);
	}
	
}
void HeapSort(int a[],int n){
	
	//  build heap
	int i;
	for(i=n/2 -1;i>=0 ;i--)
		heapify(a,n,i);
	// one by one extracting the top element of heap
	// replacing it with last element
	// heapify the tree
	for(i=n-1; i>=0 ;i--){
		swap(&a[i],&a[0]);
		// call max heapify on the reduced heap 
		heapify(a,i,0);		
	}
	
}


void print(int a[],int n){
	int i=0;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	
}

int main(){
	
	int n,i,x;	
	printf("Enter the number of elements in the array = ");
	scanf("%d",&n);
	printf("\nEnter the element : ");
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nBefore Sorting : \n");
	print(a,n);	
	HeapSort(a,n);
	printf("\nAfter Sorting : \n");
	print(a,n);	
	return 0;
}
