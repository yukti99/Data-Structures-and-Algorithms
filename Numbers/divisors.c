/* Given an array of N numbers which has all divisors of two numbers in any order.
 The task is to find the two numbers whose divisors are given in the array*/


#include <stdio.h>


int main(){
	int a[] = {10, 2, 8, 1, 2, 4, 1, 20, 4, 5};
	int n = sizeof(a)/sizeof(a[0]);
	int i=0,freq[n],max = a[0];
	// to find max element
	for(i=0;i<n;i++){
		if(a[i]>max){
			max = a[i];
		}
	}
	printf("%d\n",max);
	
	return 0;
}
