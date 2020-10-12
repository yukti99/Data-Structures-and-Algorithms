#include <stdio.h>
#include <string.h>


int occurence(char str[]){
	int n = strlen(str);
	int i=0,f=0,count=0;
	while(i<n){
		if (str[i] == '1'&& str[i+1] == '0'){
			f=i;
			i++;
			while(str[i] == '0' && i<n)
				i++;
			if (str[i] == '1'){
				count++;
				printf("Pattern found at index = %d\n",f);		
			}				
				
		}	
		else
			i++;	
		
	}
	return count;
}


int main(){
	
	char str[100];
	int i=0;
	printf("Enter the String = ");
	scanf("%s",str);
	printf("The string = %s\n",str);
	int n = occurence(str);
	printf("\nThe No of occurences of 10+1 pattern in the given string = %d\n",n);
	return 0;
}

