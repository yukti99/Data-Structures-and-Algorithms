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


void Selectionsort(int a[],int n){

	int i,j,min=0;
	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if (a[j]<a[min])
				min = j;
			
		}
		if (min!=i){
			// swap the minimum element with the current element
			int t = a[i];
			a[i] = a[min];
			a[min] = t;
			display(a,n);
		}
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
	
	printf("\nSELECTION SORT\n");
	
	printf("\nBefore Sorting : \n");
	print(a,n);
	Selectionsort(a,n);
	printf("\nAfter Sorting : \n");
	print(a,n);
	
	return 0;
}
