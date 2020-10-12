
#include <bits/stdc++.h>
using namespace std;


bool isOperand(char x){
	return ( x>='a' && x<='z' ||x>='A' && x<='Z' );
	
}

string getInfix(string exp){
	stack<string> s;
	for (int i=0;exp[i];i++){
		if (isOperand(exp[i])){
			string c="";
			c+=exp[i];
			s.push(c);
		}
		else{
			string x = s.top();
			s.pop();
			string y = s.top();
			s.pop();
			s.push("("+y+exp[i]+x+")");
		}
	}
	return s.top();
	
}




int main(){
	
	string exp;
	cout<<"Enter postfix Expression = ";
	cin>>exp;
	cout<<"INFIX FORM = "<<getInfix(exp);	
	return 0;
}
