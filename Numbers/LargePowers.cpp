// To calculate large powers
// We need to calculate 2^n-1 for large values of n
// Diwali lights problem

#include <stdio.h>
#include <math.h>


void printAns(int a[],int n){
	//a[0] = a[0]-1;
	int i=0;
	for(i=n-1;i>=0;i--)
		printf("%d",a[i]);
	printf("\n");
		
}

int main(){
	
	int t=0,n=0,i,j,carry,x,m;
	int a[200];    // to store individual digits, array will have the capacity to store 200 digits.
	printf("\nEnter the number of Test Case = ");
	scanf("%d",&t);
	while(t--){
		printf("Enter n = ");
		scanf("%d",&n);	
		if (n==0 || n==1){
			printf("%d\n",n);
			continue;
		}
		a[0] = 1;
		m = 1; 		// initializes digit counter
		carry = 0;   // initializes carry variable to zero
		for(i=1;i<=n;i++){
			for(j=0;j<m;j++){
				x = 2*a[j] + carry;
				a[j] = x%10;     //Contains the digit to store in position j
				carry = x/10;  	 //Contains the carry value that will be stored on later indexes
			}
			while(carry>0){
				a[m] = carry%10;
				carry = carry/10;
				m++; 			// increments digit counter
			}
			
		}
		a[0] = a[0]-1;		
		printAns(a,m);		
		
		
	}
	
	return 0;
}



/*

//Complete the lights function below.

// To calculate large powers
// We need to calculate 2^n-1 for large values of n
// Diwali lights problem



int main(){
    
    int t=0,n=0,i,j,carry,x,m;
    int a[200];       
    scanf("%d",&t);
    while(t--){       
        scanf("%d",&n);    
        if (n==0 || n==1){
            printf("%d\n",n);
            continue;
        }
        unsigned long long int ans = 1;
        for(i=1;i<=n;i++){
            ans = (2*ans) % 100000 ;
        }
        ans--;
        printf("%lld\n",ans);    
        
    }
    
    return 0;
}*/

