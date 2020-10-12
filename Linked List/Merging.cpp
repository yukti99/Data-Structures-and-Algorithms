/* MERGING OF TWO SORTED LISTS TO CREATE A SORTED LIST*/


#include <stdio.h>

int main(){
	
	int i=0,j=0,k=0,n1=5,n2=4;
	int a[] = {1,3,5,6,9};
	int b[] = {2,4,7,8};
	int n3 = n1+n2;
	int c[n3];
	
	while(i<n1 && j<n2){
		
		if(a[i] < b[j])		
			c[k++] = a[i++];
		
			
		else
			c[k++] = b[j++];				
	}
	
	while(i<n1)
		c[k++] = a[i++];
	
	while(j<n2)
		c[k++] = b[j++];	
	
	for(i=0;i<n3;i++)
		printf("%d ",c[i]);
	
	
	
}
