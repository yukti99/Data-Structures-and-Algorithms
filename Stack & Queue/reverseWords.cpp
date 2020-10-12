// reverse the String word-wise
#include <bits/stdc++.h>
using namespace std;


int main(){
	string s = "";
	getline(cin,s);
	stack<string> stack;
	int l = s.length();
	string temp = "";
	int i;
	for(i=0;i<l;i++){
		temp+=s[i];		
		if (s[i] ==  ' ' || i==l-1){		
			stack.push(temp);
			temp.clear();
			continue;
		}
		
		
	}
	cout<<endl;
	while(!stack.empty()){
		cout<<stack.top()<<" ";
		stack.pop();
	}
	cout<<endl;
	

	return 0;
}
