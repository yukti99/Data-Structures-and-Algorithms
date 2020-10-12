// The longest prefix which is also a suffix
#include <stdio.h>
#include <string.h>


int prefixSuffix(char text[]){
	int n = strlen(text);
	int i=0,j = n/2,k=0; ;
	char s[n];
	while(j < n){
		if (text[i] == text[j]){
			i++;
			j++;	
		}
		else{
			if (i==0)
				j++;
			else
				i--;
		}		
	}
	return i;
}

int main(){
	
	char text[100];
	int i=0;
	printf("Enter the Text = ");
	scanf("%s",text);
	int n = prefixSuffix(text);
	if (n!=0){
	printf("\nThe longest prefix which is also a suffix is of length = %d\n",n);
	printf("It is : ");
	for(i=0;i<n;i++)
		printf("%c",text[i]);
	printf("\n\n");
	}
	else
		printf("\nNo such prefix!!\n");
	return 0;
}



