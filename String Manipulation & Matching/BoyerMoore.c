#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LastOccIndex(char *pat,int m,int *badchar){
	int i=0;
	for(i=0;i<256;i++)
		badchar[i] = -1;
	for(i=0;i<m;i++)
		badchar[(int)pat[i]] = i; 
	
}
int min(int a,int b){
	return ((a<b)?a:b);
}

void BoyerMooreSearch(char *text,char *pat){	
	int badchar[256];
	int n = strlen(text);
	int m = strlen(pat);
	int i = m-1;
	int j = m-1;
	LastOccIndex(pat,m,badchar);
	while(i<=n-1){
		printf("\nComparing %c and %c\n",text[i],pat[j]);
		if (pat[j] == text[i]){
			if (j==0){
				printf("\n*Pattern Found at Index - %d\n",i);
				i = i+m;
				j = m-1;				
			}			
			else{				
				i--;
				j--;
				printf("\nChar Match Now i = %d, j = %d\n",i,j);
			}
		}
		else{ 			
			i = i+m-min(j,1+badchar[text[i]]);  // shifting 
			j = m-1;			      //reset
			printf("\nShifting by i = %d\n",i);
		} 
		
	}
	
}



int main(){
    char text[] = "ABCAAABCDABC";
    char pat[] = "ABC";
    BoyerMooreSearch(text, pat); 
    return 0; 
}
