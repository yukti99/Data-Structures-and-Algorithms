/* Shell Sort */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
	int t = *a;
	*a = *b ;
	*b = t;
}

void ShellSort(int a[],int n){
	
	int i,j,gap,temp;
	
	for(gap = n/2 ; gap > 0 ; gap/=2 ){
	 
		for(i = gap ; i<n ; i++){
			
			temp = a[i];
			
			for(j = i; j>=gap && a[j-gap] > temp ; j -= gap){
				a[j] = a[j-gap];
			}
			a[j] = temp;
		}
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
	printf("\n\t\tSHELL SORTING\n");
	printf("Enter the number of elements in the array = ");
	scanf("%d",&n);
	printf("\nEnter the element : ");
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nBefore Sorting : \n");
	print(a,n);	
	ShellSort(a,n);
	printf("\nAfter Sorting : \n");
	print(a,n);	
	return 0;
}
