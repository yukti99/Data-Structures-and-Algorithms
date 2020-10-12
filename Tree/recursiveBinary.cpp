#include <stdio.h>

long long int Binary(long long int n){
	if (n == 1)
		return 1;
	if (n%2 == 0)
		return 10*Binary(n/2);
	else
		return 10*Binary(n/2)+1;
	
}

int main(){
	long long int n,b;
	printf("Enter the decimal number = ");
	scanf("%lld",&n);
	b = Binary(n);
	printf("Binary Equivalent of %lld = %lld\n",n,b);
}

