/* Rabin Karp Pattern Matching using Rolling Hash Function */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// number of characters in the character set
#define d 256



// q = any prime number
void search(char text[],char pat[],int q){
	
	int i,j;
	int M = strlen(text);
	int N = strlen(pat);
	int h = 1 ; // hash function
	int p = 0 ; // hash value for pattern
	int t = 0 ; // hash value for text
	int c = 0 ; //counter
	
	//for(i=0;i<N-1;i++)
	//	h = (h*d)%q ;
	h =(int) pow(d,N-1)%q;
		
	for(i=0;i<N;i++){
		p = (p*d + pat[i])%q;
		//printf("p = %d\n",p);
		//printf("pat[i] = %c,%d\n",pat[i],pat[i]);
		t = (t*d + text[i])%q;
		//printf("t = %d\n",t);
		//printf("text[i] = %c,%d\n",text[i],text[i]);
	}
	for(i=0;i<=M-N;i++){
		if (p == t){
			for(j=0;j<N;j++){
				if (text[i+j] != pat[j])
					break; 				
			}
			if (j == N){
				printf("\nPattern found at  index - %d\n",i);
				c++;
			}				
		}
		//printf("i = %d\n",i);
		if (i<M-N){
			t = (d*(t - text[i]*h) + text[i+N])%q; 
			//printf("\nInside next hash : \n");
			if (t<0)
				t = t+q;
			//printf("t = %d\n",t);
		
		}
	}
	if(c == 0)
		printf("The pattern is NOT found in the given text !\n");
}


int main(){
	
	char text[] = "GEEKS FOR GEEKS"; 
    char pat[] = "GEEK"; 
    int q = 101; // A prime number 
    search(text,pat,q); 	
	return 0;
}
