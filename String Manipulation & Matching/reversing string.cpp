/* C++ Program
#include <bits/stdc++.h>
using namespace std;

string reversebyswap(string str)
{
	int len = str.length();
	for(int i=0;i<len/2;i++)	
		swap(str[i],str[len-1-i]);
	
	return str;
}


int main()
{
	string s = "!emoclew & olleH";
	s = reversebyswap(s);
	cout<<s<<endl;
	string s2 = "anaruhK itkuY";
	reverse(s2.begin(),s2.end());
	cout<<s2<<endl;
	
	return 0;
}*/
/* C Program : reverse function with strlen()

#include <stdio.h>
#include <string.h>

void *reverse(char *s)
{
	int i,l;
	l = strlen(s);
	// *(str+i) is the character at the ith index 
    // of the string
	for(i=l;i>=0;i--)
		printf("%c",*(s+i));  // or printf("%c",s[i]);
	
}

int main()
{
	char s[] = "anaruhK itkuY !emoclew & olleH";
	reverse(s);	
	return 0;
}
*/
/* C Program to reverse a constant string and return the pointer of that :If the string is a 
const string (not editable), then we need to create an array and return the pointer of that.*/
 
#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
// Function to reverse string and return reverse string pointer of that
char* ReverseConstString(char const* str)
{
    int start, end, len;
    char temp, *ptr = NULL;
     
    // find length of string
    len = strlen(str); 
     
    // create dynamic pointer char array
    ptr = (char*)malloc(sizeof(char)*(len+1)); 
     
    // copy of string to ptr array
    ptr = strcpy(ptr,str);             
     
    // swapping of the characters
    for (start=0,end=len-1; start<=end; start++,end--)
    {
        temp = ptr[start];
        ptr[start] = ptr[end];         
        ptr[end] = temp;
    }
     
    // return pointer of reversed string
    return ptr; 
}
 
// Driver Code
int main(void) 
{
    char const* str = "anaruhK itkuY !emoclew & olleH";
    printf("%s", ReverseConstString(str));
    return 0;
}

















