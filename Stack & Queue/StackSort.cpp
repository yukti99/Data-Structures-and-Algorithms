#include <iostream>
#include <stack>
using namespace std;


// sorting a stack using a helper stack
stack<int> SortStack(stack<int> s){
	if (s.empty())
		return s;
	stack<int> s1;
	int cur = 0;
	while(!s.empty()){
		cur = s.top();
		s.pop();
		while(!s1.empty() && cur < s1.top()){
			s.push(s1.top());
			s1.pop();
		}
		s1.push(cur);
	
	}
	return s1;



}


int main(){
	stack<int> s ;
	s.push(3);s.push(2);s.push(4);s.push(6);s.push(5);s.push(1);
	s = SortStack(s);
	while(!s.empty()){
		cout<<s.top()<<" " ;
		s.pop();
	}

	

	return 0;
}
