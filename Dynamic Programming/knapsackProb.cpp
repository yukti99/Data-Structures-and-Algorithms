// The Fractional knapsack Problem in c++

#include <bits/stdc++.h>
using namespace std;


struct Item{
	int value;
	int weight;
};

bool cmp(struct Item a,struct Item b){
	double r1 = (double)a.value/a.weight ;
	double r2 = (double)b.value/b.weight ;
	return (r1>r2);
}
	

int main(){	

	int W = 50;   //    Weight of knapsack 
    Item arr[] = {{60, 10}, {120, 30}, {100, 20}};   
    int n = sizeof(arr) / sizeof(arr[0]);  
	sort(arr,arr+n,cmp);
	for (int i = 0; i < n; i++){ 
        cout << arr[i].value << "  " << arr[i].weight << " : " 
             << ((double)arr[i].value / arr[i].weight) << endl; 
    } 
    //cout << "Maximum value we can obtain = "
      //   << fractionalKnapsack(W , arr, n); 
    return 0; 
}



