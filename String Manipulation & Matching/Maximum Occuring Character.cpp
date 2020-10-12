/*
Given a string, find the maximum occurring character in the string.
 If more than one character occurs maximum number of time then print the lexicographically smaller character.

Input:

The first line of input contains an integer T denoting the number of test cases. 
Each test case consist of a string in 'lowercase' only in a separate line.

Output:

Print the lexicographically smaller character which occurred the maximum time.

Constraints:

1 = T = 30
1 = |s| = 100

Example:

Input:
2
testsample
geeksforgeeks

Output:
e
e

*/


#include <iostream>
#include <string>
using namespace std;


string lexsort(string s,int l)
{
	int i,j;
	char t;
	for(i=0;i<l-1;i++)	
		for(j=0;j<l-1-i;j++)		
			if (s[j]>s[j+1])
			{
				t = s[j];
				s[j] = s[j+1];
				s[j+1] = t;				
			}	
	return s;
}
int main()
{
	int T,l,i,j=0,k=0,count,max,pos;
	char temp;
	string s;
	cin>>T;
	while(T--)
	{
		cin>>s;
		max = 0;
		l = s.length();
		s = lexsort(s,l);
		//cout<<s<<endl;
		int f[l];
		for(i=0;i<l;i++)
		{
			
			temp = s[i];				
			count = 1;
			for(j=i+1 ;j<l ;j++)
			{
				
				if (s[j] == temp)
					count++;
			}
			x : if (max<count)
		    {
		    	max = count;
		    	pos = i;
			}				
		}
		cout<<s[pos]<<endl;		
	}	
	return 0;
}

