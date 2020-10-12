#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// KMP

// m- length of pattern
void LPS(char *pat,int m,int *lps){
	
	int len = 0,i = 1;
	lps[0] = 0;
	while(i<m){
		if (pat[i] == pat[len]){
			len++;
			lps[i] = len;	
			i++;			
		}
		else{
			if (len!=0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}	
}

void KMP(char *text,char *pat){
	int t=0,p=0;
	// t = pointer for text
	// p = pointer for pattern
	int n = strlen(text);
	int m = strlen(pat);
	int lps[m];
	LPS(pat,m,lps);
	while(t<n){
		if (text[t] == pat[p]){
			p++;
			t++;		
		}
		if (p == m){
			printf("\nFound Pattern at Index - %d\n",t-p);
			p = lps[p-1];
		}
		else if (t < n && pat[p] != text[t]){
			if (p!=0)
				p = lps[p-1];
			else
				t++;
								
		}
		
	}
}

int main(){
	
	char text[] = "ABABDABACDABABCABAB"; 
    char pat[] = "ABABCABAB"; 
    KMP(text, pat); 
    return 0; 
}
