#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
	return (a>b)?a:b;
}

int main(){
	
	// Taking inputs
	int Profit[] = {0,1,2,5,6};
	int weight[] = {0,2,3,4,5};
	int capacity = 8, no = 4;
	int knap[no+1][capacity+1];
	int i=0,w=0;
	for(i=0;i<=no;i++){
		for(w=0;w<=capacity;w++){
			if (w == 0 || i == 0)
				knap[i][w] = 0;
			else if (weight[i] <= w){
				int prevProfit = knap[i-1][w-weight[i]] ;
				knap[i][w] = max( Profit[i]+ prevProfit , knap[i-1][w]);
			}	
			else
				knap[i][w] = knap[i-1][w];  
					
		}		
	}
	for(i=0;i<=no;i++){
		for(w=0;w<=capacity;w++){
			printf("%d ",knap[i][w]);
		}
		printf("\n");
	}
	printf("\nThe max profit is %d\n",knap[no][capacity]);
	// To display which objects to include
	i = no;w = capacity;
	while(i>00 && w>=0){
		
		if (knap[i][w] == knap[i-1][w]){
			printf("\n%d not included!\n",i);
			i--;
		}
		else{
			printf("\n%d included!\n",i);
			w = w-weight[i];
			i--; 
			
		}
		
	}
	
}
