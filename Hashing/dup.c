#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int elem(int *A,int n,int e){
	int i=0;
	for(i=0;i<n;i++){
		if (A[i] == e)
			return 1;
	}
	return 0;
}
void print(int *a,int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int Compare(const void *a,const void *b){
	return *(char*)a - *(char*)b ;
}

void rD(char s[]){
	int last=0,current=0,i=0,j=0;
	qsort(s,strlen(s),sizeof(char),Compare);
	while(s[i]!='\0'){
		if (s[i] == s[last])
			last++;
		else
			s[++i] = s[last];
				
	}
	s[i] = '\0';
}



int removeDuplicates(int *A,int n){
	int m=0,i=0;
	for(i=0;i<n;i++){
		if (!elem(A,m,A[i])){
			printf("\nm = %d\n",m);
			A[m++] = A[i];
			print(A,n);
		}
	}
	return m;

}

int main(){
	int n = 7,i=0;
	int a[] = {2,3,2,1,3,4,5,1};
	/*removeDuplicates(a,n);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	*/
	char s[] = {'a','b','a','b','d','c','a','c','b','d'};
	rD(s);
	for(i=0;s[i]!='\0';i++)
		printf("%c ",s[i]);
	printf("\n");


	return 0;
}
