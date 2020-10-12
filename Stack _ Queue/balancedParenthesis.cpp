/* Check for balanced parentheses in an expression
Given an expression string exp , write a program to examine whether the pairs
 and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp. 
 
For example, the program should print true for exp = “[()]{}{[()()]()}” and false for exp = “[(])” 
USING STACK
*/


#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class Stack{
	
	int top;
	public:
		char a[SIZE];
		Stack(){
			top = -1;
		}
	char pop();
	void peek();
	void display();
	bool push(char x);		
	bool isEmpty();
		
};


bool Stack::push(char x){
	if (top >= SIZE-1){	
	
		cout<<"\nStack Overflow!\n";// if stack is full
		return false;		
	}            
	
	a[++top] = x;
	//cout<<x<<" Pushed to stack!\n";
	return true;	
}

char Stack::pop(){
	
	if (top < 0){		
		cout<<"\nStack underflow\n";
		return '?';
	}
	int popped = a[top--];
	return popped;
}
void Stack::peek(){
	
	if (top<0){
		cout<<"\nStack is Empty!\n";
		return ;
	}
	cout<<"\nTop of the Stack : "<<a[top]<<endl;
}
bool Stack::isEmpty(){	
	return (top<0);
}

void Stack::display(){
	
	cout<<"\nSTACK : \n";
	if(top<0){
		cout<<"\nStack is Empty!\n";
		return ;
	}
	for(int i=top;i>=0;i--){
		cout<<a[i]<<endl;
	}
}

bool isBalanced(string exp){
	
	Stack s ;
	char x;
	for(int i=0; i<exp.length(); i++){
		
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '['){
			s.push(exp[i]);
			continue;
		}
		if (s.isEmpty())
			return false;
			
		switch(exp[i]){
			
			case ')':
				x = s.pop();
				if (x=='{' || x=='[')
					return false;
				break;
				
			case '}':
				x = s.pop();
				if (x=='(' || x=='[')
					return false;
				break;
									
			case ']':
				x = s.pop();
				if (x=='{' || x=='(')
					return false;
				break;
				
		} 		
	}
	return (s.isEmpty() ); 	
}


int main(){
	
	
	string exp;
	cout<<"\nEnter the expression : ";
	cin>>(exp);
	if (isBalanced(exp))
		cout<<"The Parenthesis are balanced!\n";
	else
		cout<<"The Parenthesis are NOT balanced!\n";
	
	
	return 0;
	
	
}
