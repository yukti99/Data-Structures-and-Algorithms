#include <iostream>
#include <string>
#include <sstream>
#include<bits/stdc++.h>

using namespace std;

int IsVariable(string s){
	
	int i,l=s.length(),f;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	if (s[0] >=0 &&s[0] <= 9)
		return 0;
	for(i=0;i<l;i++){
		
		if ((s[i]>='a' && s[i] <= 'z') || (s[i]>=48 && s[i]<=57) || s[i] =='_' )
			f=1;
		else{
			
			cout<<s[i]<<endl;
			return 0;
		}		
	}
	if (f==1)
		return 1;
	else
		return 0;
}

int main(){
	
	int n,i,l,p=0,k=0;
	char code[100];
	string s;
	string words[50];
	string check[50] = {"int","float","double","string"};
	string I[50],F[50],D[50],S[50];
	int a,f,d,j,c;
	char variables[50][50];	
	cout<<"Enter code = ";
	for(i=0;i<3;i++){
		gets(code);
		printf("%c")
		puts(code);
	}
	

	/*
	for (i = 0; i<l; i++){
    	if (code[i] == ' ')
        	k++;
    	else
         	words[k] += code[i];
	}
	for(i=0;i<l;i++)
	{
		for(j=0;j<4;j++)
		{
			if (words[j].compare("int") == 0)
			{
				if (words[j] == ';')
					break;
				if (words[j] == ',')				
					j++;			
				
				I[a++] = words[j+1];				
			}
			
			
				
				
		}
	}
	for(int h=0;h<1;h++)
				cout<<I[h]<<endl;
		
	
	

	*/
	
	
	return 0;
}
