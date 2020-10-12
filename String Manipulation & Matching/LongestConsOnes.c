#include <stdio.h>
#include <string.h>


int max(int a,int b){
	return a>b?a:b ;
}

void print(int a[],int n){
	int i=0;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int longestOnes(char s[],int n){
	int ones = 0,i=0;
	int l[n],r[n];
	for(i=0;i<n;i++){
		if (s[i] == '1')
			ones++;		
	}
	if (s[0] == '1')
		l[0] = 1;
	else 
		l[0] = 0;
	
	if (s[n-1]== '1')
		r[n-1] = 1;
	else  
		r[n-1] = 0;
	
	for(i=1;i<n;i++){
		if (s[i] == '1'){
			l[i] = l[i-1] + 1;
		}
		else 
			l[i] = 0;
	}
	for(i = n-2;i>=0;i--){
		if (s[i] == '1')
			r[i] = r[i+1] + 1;
		else 
			r[i] = 0;
	}
	printf("left:\n");
	print(l,n);
	printf("right:\n");
	print(r,n);
	int c = 0,max_cnt = 0,sum=0,pos = 0;
	for(i=0;i<n;i++){
		if (s[i] == '0'){
			sum = l[i-1]+r[i+1] + 1;			
		}
		if (sum<ones)
			c = sum+1;
		else
			c = ones;		
		max_cnt = max(c,max_cnt);
		
		c = 0;
	}
	return max_cnt;	
}
int main(){
	char s[] = "111000111111";
	int n = strlen(s);	
	printf("\nThe longest Sequence of ones in string after swapping  = %d\n",longestOnes(s,n));
	return 0;
}
