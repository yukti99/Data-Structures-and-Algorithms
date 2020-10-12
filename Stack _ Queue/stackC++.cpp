#include<iostream>
using namespace std;

#define SIZE 100

class Stack{
	
	int top;
	public:
		int a[SIZE];
		Stack(){
			top = -1;
		}
		int pop();
		void peek();
		void display();
		bool push(int x);		
		bool isEmpty();
		
};


bool Stack::push(int x){
	if (top >= SIZE-1){	
	
		cout<<"\nStack Overflow!\n";// if stack is full
		return false;		
	}            
	
	a[++top] = x;
	cout<<x<<" Pushed to stack!\n";
	return true;	
}

int Stack::pop(){
	
	if (top < 0){
		
		cout<<"Stack underflow\n";
		return 0;
	}
	int popped = a[top--];
	return popped;
}
void Stack::peek(){
	
	if (top<0){
		cout<<"\nStack is Empty!\n";
		return ;
	}
	cout<<a[top];
}
bool Stack::isEmpty(){	
	return (top<0);
}

void Stack::display(){
	
	if(top<0){
		cout<<"\nStack is Empty!\n";
		return ;
	}
	for(int i=top;i>=0;i--){
		cout<<a[i]<<endl;
	}
}




int main(){
	
	Stack s ;
	int choice,item;
	while (1)
	{
	   	cout<<("\n\n********************** STACK IMPLEMENTATION IN C **********************\n\n");
		cout<<("\t\t\t1. Push element to stack \n");
	    cout<<("\t\t\t2. Delete element from stack \n");
	    cout<<("\t\t\t3. Display the top  of stack \n");
	    cout<<("\t\t\t4. Display all elements of stack \n");
	    cout<<("\t\t\t5. Quit \n");
	    cout<<("\t\t\tEnter your choice : ");
	    scanf("%d", &choice);
	    cout<<("\n");
	    switch (choice)
	    {
	        case 1:
	        	cout<<("\nEnter Element to push in stack = ");
	        	scanf("%d",&item);
	        	s.push(item);
	        	break;
	        case 2:
	        	cout<<("\nPopped Element : %d\n\n",s.pop());
	        	break;
	        case 3:
	        	s.peek();
	        	break;	        
	        case 4:
	        	s.display();
	        	break;
	        case 5:
	        	cout<<("Thank you!\n");
	        	exit(0);
	        default:
	        	cout<<("\a\nWrong choice! \n\n");
	    } 
	}	
		
	return 0;
	
	
}

