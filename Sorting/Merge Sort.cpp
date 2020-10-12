/* MERGE SORT*/


#include <stdio.h>

/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void Merge(int a[],int l,int m,int r){

	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int n3 = n1+n2;
	
	/* create temp arrays */
	int L[n1],R[n2];	
	
	/* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
        
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
 
	
	while(i<n1 && j<n2){
		
		if(L[i] < R[j])		
			a[k++] = L[i++];		
		else
			a[k++] = R[j++];				
	}
	/* Copy the remaining elements of L[], if there
       are any */	
	while(i<n1)
		a[k++] = L[i++];
	
	/* Copy the remaining elements of R[], if there
       are any */
	while(j<n2)
		a[k++] = R[j++];	
	
	//for(i=0;i<n3;i++)
	//	printf("%d ",a[i]);	
}


/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void MergeSort(int a[],int l,int r){
	
	if (l < r){
		int m = l + (r-l)/2 ;
		// sort the first and second halves then merge
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		Merge(a,l,m,r);
	}
	
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {3,8,0,-9,2,1,5,12,-7,10};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    MergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
