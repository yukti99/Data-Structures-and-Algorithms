#include <stdio.h>
#include <stdlib.h>

// suitable for large data
void BubbleSort(int a[],int n){
	int i,j,swapped,pass=0;
	for(i=0;i<n;i++){
		swapped = 0;
		pass++;		
		for(j=0;j<n-i-1;j++){
			
			if (a[j]>a[j+1]){
				// swapping			
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				swapped = 1;  
			}
		}
		if (!swapped)
			break;
	}
	printf("pass = %d\n",pass);
}
// modified- both from back and front
void BS(int a[],int n){
	int i,j,k=n-1,l=0,pass=0;
	while(l<n){	
		pass++;
		for(j=l;j<k;j++){			
			if (a[j]>a[j+1]){
				// swapping   						
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t; 
			}
		}
		k--;
		l++;
		for(j=k;j>=l;j--){
			
			if (a[j]<a[j-1]){
				// swapping
				int t = a[j];
				a[j] = a[j-1];
				a[j-1] = t;  
			}
		}
	}
	printf("pass = %d\n",pass);
}
//  inserting the element at its proper position 
void InsertionSort(int a[],int n){
	int i,pos,temp;
	for(i=1;i<n;i++){
		
		temp = a[i];
		pos = i-1;
		while(pos>=0 && temp<a[pos]){
					
			a[pos+1] = a[pos];
			pos = pos-1;				
		}
		a[pos+1] = temp;		
	}
}
/*
The smallest element is selected from the unsorted array and swapped with the leftmost element, 
and that element becomes a part of the sorted array. 
This process continues moving unsorted array boundary by one element to the right.
*/
void SelectionSort(int a[],int n){
	
	int min=0,i,j;
	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if (a[j] < a[min]){
				min = j;
			}
		}
		//swap the minimum element with the current element
		if (i != min){
			int t = a[i];
			a[i] = a[min];
			a[min] = t;			
		}		
	}	
}
// stable seletion sort
void StableSelectionSort(int a[],int n){	
	int min=0,i,j;
	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if (a[j] < a[min]){
				min = j;
			}
		}
		// instead of swapping we insert
		if (i!=min){
			int temp = a[min];
			while(min>i){
				a[min] = a[min-1];
				min--;
			}
			a[i] = temp;
		}
	}	
}


/* Merge Sort */
void Merge(int a[],int low,int mid,int high){
	int i,j,k;
	int n1 = mid-low+1;
	int n2 = high-mid;
	int n3 = n1+n2;
	
	int l[n1],r[n2];
	
	for(i=0;i<n1;i++)
		l[i] = a[low+i];
	
	for(j=0;j<n2;j++)
		r[j] = a[mid+1+j];
	
	i = 0;
	j = 0;
	k = low;
	
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
	
}
void MergeSort(int a[],int l,int r){
	if (l<r){
		//int m = (l+r)/2 ;
		int m = l + (r-l)/2 ;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		Merge(a,l,m,r);
	}
}
// Non-recursive Merge Sort
void MS(int a[],int n){
	int cur_size,l;
	for(cur_size = 1;cur_size< n ; cur_size = cur_size*2){
		for(l=0;l<n-1;l+=cur_size*2){
			int m = l+cur_size-1;
			int r = m+cur_size;
			if (r>n-1)
				r = n-1;
			Merge(a,l,m,r);
		}
	}
}

/* Quick Sort */

void swap(int *a,int *b){
	
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int a[],int low,int high){
	
	int pivot = a[high];
	int i = low-1,j;
	for(j = low ; j<=high-1; j++){
		if (a[j]<=pivot){
			i++;
			printf("%d,%d\n",i,j);
			swap(&a[j],&a[i]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
}

void QuickSort(int a[],int low,int high){
	
	if (low < high){
		int pi = partition(a,low,high);   // partition index
		QuickSort(a,low,pi-1);
		QuickSort(a,pi+1,high);
	}
	
}
void ShellSort(int a[],int n){
	int temp,i,j,pos;
	int gap = n/2 ;
	while(gap > 0){
		for(i = gap;i<n;i++){
			temp = a[i];
			pos = i-gap;
			while(pos >= 0 && a[pos] > temp){
				a[pos + gap] = a[pos];
				pos = pos - gap; 
			}
			a[pos+gap] = temp;
		}		
		gap /= 2;		
	}
	
}

int main(){
	
	int a[] = {3,8,0,-9,2,1,5,12,-7,10,4,5};
	int n = sizeof(a)/sizeof(a[0]);
	printf("\nList before Sorting: \n");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	//BubbleSort(a,n);
	//StableSelectionSort(a,n);
	//BS(a,n);
	MS(a,n);
	//InsertionSort(a,n);
	//SelectionSort(a,n);
	//MergeSort(a,0,n-1);
	//ShellSort(a,n);
	//QuickSort(a,0,n-1);
	printf("\nSorted List : \n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);	
	return 0;
}
