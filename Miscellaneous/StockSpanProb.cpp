#include <bits/stdc++.h>
using namespace std;

// The Stock Span Problem
// using Stack in O(n) time complexity 

void StockSpan(int price[],int n,int S[]){

	stack<int> s;
	s.push(0);
	S[0] = 1;
	for(int i=1;i<n;i++){		
		while(!s.empty() && price[s.top()] <= price[i]){
			s.pop();
		}		
		S[i] = s.empty()?(i+1):(i-s.top());
		s.push(i);
	}	
}
// without using stack
void CalculateStockSpan(int price[],int n,int S[]){	
	S[0] = 1;
	for(int i=1;i<n;i++){
		int c = 1;
		while((i-c>=0)&& price[i] > price[i-c]){
			c += S[i-c];
		}
		S[i] = c;
	}
}

void print(int a[],int n){
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(){	
	int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]); 
    int S[n]; 
    //StockSpan(price,n,S);
    CalculateStockSpan(price,n,S);
   
    print(S,n);
	return 0;
}
