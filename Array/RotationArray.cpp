#include <iostream>
using namespace std;

void print(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}


int main(){
	
	int N,i,k,x,t,T;
	cin>>T;
	while(T--){
	cin>>N;
	int a[N];
	for(i=0;i<N;i++){
		cin>>a[i];
	}
	//rotation
	int n = N;
	int ans = 0;
	for(x=1;x<=n;x++){
    	t = a[N-1];
    	for(i=N-1;i>=0;i--){
    		a[i+1] = a[i];
    	}
    	a[0] = t;
    	//deletion
    	if (x>N){
    	    k = 0;
    	}
    	else
    	    k = N-x;
        for(i=k;i<N-1;i++){
            a[i] = a[i+1];
        }
    	
        N--;
        ans = a[0];
        //print(a,N);
    	//print(a,N);
    	
	}
	printf("%d\n",ans);
	}
	return 0;
}
