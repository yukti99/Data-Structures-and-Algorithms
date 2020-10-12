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

/* Merge Sort */
void Merge(int a[],int n,int low,int mid,int high){
	int i,j,k=low;
	int n1 = mid-low+1;
	int n2 = high-mid;
	int n3 = n1+n2;
	
	int l[n1],r[n2];
	// left part
	for(i=0;i<n1;i++)
		l[i] = a[low+i];
	// right part
	for(j=0;j<n2;j++)
		r[j] = a[mid+1+j];
	
	i = 0;
	j = 0;
	// sorted merge
	while(i<n1 && j<n2){
		
		if (l[i]<r[j])
			a[k++] = l[i++];
		else 
			a[k++] = r[j++];
			
	}
	while(i<n1)
		a[k++] = l[i++];
	
	while(j<n2)
		a[k++] = r[j++];
	printf("\nMerging : \n");
	display(a,n);
	
}
void MergeSort(int a[],int n,int l,int r){
	if (l<r){
	
		int m = l + (r-l)/2 ;
		MergeSort(a,n,l,m);
		MergeSort(a,n,m+1,r);
		Merge(a,n,l,m,r);
		printf("\nAfter Merging : \n");
		display(a,n);
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
	
	printf("\nMERGE SORT\n");
	
	printf("\nBefore Sorting : \n");
	print(a,n);
	MergeSort(a,n,0,n-1);
	printf("\nAfter Sorting : \n");
	print(a,n);
	
	return 0;
}
