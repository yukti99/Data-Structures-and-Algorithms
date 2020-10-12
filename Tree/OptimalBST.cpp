// Optimal Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int MIN(int a,int b){
	return a<b?a:b;
}
int freqsum(int freq[],int i,int j){
	int k=0,sum=0;
	for(k=i;k<j;k++){
		sum+=freq[k];		
	}
	return sum;
}

int OptimalBST(int keys[],int freq[],int n){
	
	int cost[n+1][n+1];
	int i=0,j=0,d=0,r=0;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			cost[i][j] = 0;
	
	for(d=1;d<=n;d++){
		for(i=0;i<=n-d;i++){
			j = i+d;			
			cost[i][j] = INT_MAX;
			int s = freqsum(freq,i,j);			
			for(r=i;r<=j;r++){
				int c = cost[i][r] + cost[r+1][j] + s;
				if (c < cost[i][j])
					cost[i][j] = c;
			}			 			
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++)
			printf("%d\t",cost[i][j]);
		printf("\n");
	}
	return cost[0][n];
	
}

int main(){

    int keys[] = {10, 12,20}; 
    int freq[] = {34,8,50}; 
    int n = sizeof(keys)/sizeof(keys[0]); 
    printf("\nCost of Optimal BST is %d\n",OptimalBST(keys, freq, n)); 
    return 0;
}
