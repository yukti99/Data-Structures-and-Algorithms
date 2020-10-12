/*INFIX TO PREFIX*/


#include <bits/stdc++.h>
using namespace std;


bool isOperand(char x){
	return ( x>='a' && x<='z' ||x>='A' && x<='Z' );
	
}
int prec(char op){	
	switch(op){
		case '=':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
			
	}
	return -1;
}

string getPrefix(string exp){
	stack<char> s;
	s.push('(');
	string prefix = "";
	for (int i=exp.length()-1; exp[i];i--){
		
		
		if (isOperand(exp[i])){
			prefix += exp[i];
		}
		else if (exp[i]== ')'){
			s.push(exp[i]);
		}
		else if (exp[i] == '('){
			while(exp[i] != '('){
				prefix+= s.top();
				s.pop();				
			}
			s.pop();			
		}
		else{
			
			while( prec(exp[i])<=s.top()){
				prefix+=s.top();
				s.pop();				
			}
			s.push(exp[i]);
		}
	}
	cout<<prefix<<endl;
	
}




int main(){
	
	string exp;
	cout<<"Enter INFIX Expression = ";
	cin>>exp;
	cout<<"PREFIX FORM = "<<getPrefix(exp);	
	return 0;
}
