// count Sort

#include <bits/stdc++.h>
using namespace std;


int findMax(int a[],int n){
	int m = INT_MIN;
	for(int i=0;i<n;i++){
		if (a[i] > m)
			m = a[i];
	}
	return m;
}

void CountSort(int a[],int n){
	int i,j;
	int max = findMax(a,n);
	int count[max+1];
	memset(count,0,sizeof(count));
	for(i=0;i<n;i++){
		count[a[i]]++;
	}
	i=0;j=0;
	while(i<max+1){
		if (count[i]>0){
			a[j++] = i;
			count[i]--;
		}
		else
			i++;
	}
	
}

int main(){

	int a[] = {11,13,7,12,16,9,24,5,10,3,2,3,4,22,46,21,12};
	int n = sizeof(a)/sizeof(a[0]);
	CountSort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
