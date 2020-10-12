/* String Matching  : Brute Force Method 

Text : She is amazing and pretty. She is kind too.
pattern : She
count  = 2

*/


#include <stdio.h>
#include <string.h>


void StringMatch(char text[],char pat[]){
	int t = strlen(text),p = strlen(pat);
	int i,j,flag = 0;
	for(i = 0 ;i<t-p ; i++){
		j = 0;
		while(j<p && text[i+j] == pat[j])
			j++;
		if (j == p){
			flag = 1;
			printf("\nPattern found at index = %d \n",i);			
		}			
	}
	if (!flag)
		printf("\nPattern Not Found!!\n");
}


int main(){
	
	char text[100],pat[50];
	printf("Enter the Text = ");
	gets(text);
	printf("Enter the Pattern = ");
	gets(pat);
	printf("\nText = %s\nPattern = %s\n",text,pat);
	StringMatch(text,pat);

	return 0;
}


