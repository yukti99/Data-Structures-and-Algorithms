/* String Matching  : My method

Text : She is amazing and pretty. She is kind too.
pattern : She
count  = 2

*/


#include <stdio.h>
#include <string.h>


int main(){
	
	int i=0,j=0,count=0;
	char text[100],pat[50];
	printf("Enter the Text = ");
	gets(text);
	printf("Enter the Pattern = ");
	gets(pat);
	printf("\nText = %s\nPattern = %s\n",text,pat);
	
	while(i < strlen(text)){
		if (text[i] == pat[j])
			j++;
		i++;
		if (j == strlen(pat)){
			count++;
			j = 0;
		}
	}
	
	if (count == 0)
		printf("\nPattern Mismatch!\n");
	else
		printf("\nPattern found %d times in the text\n",count);
	

	return 0;
}


