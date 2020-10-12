/*  Check if a given string is a rotation of a palindrome:

Given a string, check if it is a rotation of a palindrome. For example “aab” is a rotation of “aba”.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string.


Output:
For each test case, output "1" if string is rotation of a palindrome otherwise "0" in a new line.
 

Constraints:
1<=T<=100
1<=Length of the string<=100


Example:
Input:
1
aab

Output:
1
*/



#include <iostream>
#include <string>
using namespace std;


int is_palindrome(string s)
{
	int i;
	string rev;
	int l = s.length() ;
	for(i=l-1;i>=0;i--)	
		rev += s[i];
	
	if (rev.compare(s) == 0)
		return 1;
		
	else
		return 0;	
	
}
int main()
{
	auto start = high_precission_clock::now();
	int T,i,j,l,k,m,f;
	string s,s2,s3;
	cout<<"Test cases = ";
	cin>>T;
	while(T--)
	{
		cout<<"Enter string = ";
		cin>>s;
		l = s.length();
		s2 = s+s;
		//cout<<s2<<endl;
		j=0;
		k=j+l;
		f=0;
		//cout<<"Possible rotations of the entered string :\n";
		for(m=0;m<l;m++)
		{
			for(i=j;i<k;i++)			
				s3 += s2[i];		
			
			cout<<s3<<endl;
			if (is_palindrome(s3))
				f=1;
			k++;
			j++;		
			s3.clear();
		}
		//cout<<"Palidrome or Not : ";
		if (f==1)
			cout<<1<<endl;
		else 
			cout<<0<<endl;
		
			
	}
	return 0;
}




