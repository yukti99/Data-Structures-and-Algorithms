#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
using namespace std;


struct Stack{
	
	int top;
	unsigned size;
	char *c ;
	
};

struct Stack *CreateStack(unsigned size){
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->size = size;
	stack->c = (char*)malloc(stack->size *sizeof(char));
	return stack;
}

int isFull(struct Stack *stack){
	return (stack->top == stack->size -1) ;
}
	

int isEmpty(struct Stack *stack){
	return (stack->top == -1);
}
	
	
void push(struct Stack *stack){
	char item;
	printf("\nEnter item to push into the stack : ");
	scanf("%c",&item);
	
	if (isFull(stack))
		return ;
	stack->array[++stack->top] = item;
	printf("\nItem pushed to stack - %c\n",item);	
}

void peek(struct Stack *stack){
	
	if (isEmpty(stack))
		printf("The Stack is Empty!\n");
	printf("\nThe top item of Stack is : %c\n",stack->array[stack->top]);
}
int pop(struct Stack *stack){
	if (isEmpty(stack)){
		printf("Stack is Empty\n");
		return stack->top;
	}	
	return stack->array[stack->top--];
}

void middle(struct Stack*s){
	
	int m = s->top +1;
	if (m %2 == 0)
		printf("\nMiddle elements of the Stack are : %d  %d\n",s->array[m/2-1],s->array[m/2])	;
	else
		printf("\nMiddle element of the Stack is : %d\n",s->array[m/2]);		
	
}

void reverse_words(string str){
	
	struct Stack* s = CreateStack(100);	
	for(int i=0;i<strlen(str);i++){
		if (str[i] != ' '){
			push(s,str[i]);
		}
		// if space is found characters of the stack are popped and printed
		else{
			while(!isEmpty(s)){
				char ch = pop(s);
				printf("%c",ch);				
			}
			printf(" ");			
		}
		
	}
	
}
void  display(struct Stack *stack){
	
	printf("\nStack :\n");
	if (isEmpty(stack)){
		printf("\nStack is Empty!\n");
		return ;
	}
	int c = stack->top ;
	while(c >= 0 && stack->array[c]){
		printf("%d\n",stack->array[c--]);
	}
	printf("\n");
}


int main(){
	
	struct Stack *s = CreateStack(100);
	int choice;
	while (1)
	{
	    printf("\n\n********************** STACK IMPLEMENTATION IN C **********************\n\n");
		printf("\t\t\t1. Push element to stack \n");
	    printf("\t\t\t2. Delete element from stack \n");
	    printf("\t\t\t3. Display the top  of stack \n");
	    printf("\t\t\t4. Display all elements of stack \n");
	    printf("\t\t\t5. Middle Element of the stack \n");
	    printf("\t\t\t6. Reverse Individual words of a string \n");	    
	    printf("\t\t\t7. Quit \n");
	    printf("\t\t\tEnter your choice : ");
	    scanf("%d", &choice);
	    printf("\n");
	    switch (choice)
	    {
	        case 1:
	        	push(s);
	        	break;
	        case 2:
	        	printf("\nPopped Element : %d\n\n",pop(s));
	        	break;
	        case 3:
	        	peek(s);
	        	break;	        
	        case 4:
	        	display(s);
	        	break;
	        case 5:
	        	middle(s);	 
				break;   
			case 6:
				string str;
				printf("\nEnter the string of words : ");
				gets(str);
				reverse_words(str);
				break;    	
	        case 7:
	        	printf("Thank you!\n");
	        	exit(0);	        	
	        default:
	        	printf("\a\nWrong choice! \n\n");
	    } 
	}	
		
	return 0;
}




/*
// C++ program to reverse individual words in a given 
// string using STL list
#include <bits/stdc++.h>
using namespace std;
 
// reverses individual words of a string
void reverseWords(string str)
{
    stack<char> st;
 
    // Traverse given string and push all characters
    // to stack until we see a space.
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != ' ')
            st.push(str[i]);
 
        // When we see a space, we print contents
        // of stack.
        else {
            while (st.empty() == false) {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
    }
 
    // Since there may not be space after
    // last word.
    while (st.empty() == false) {
        cout << st.top();
        st.pop();
    }
}
 
// Driver program to test function
int main()
{
    string str = "Geeks for Geeks";
    reverseWords(str);
    return 0;
}
Run on IDE

Output:
skeeG rof skeeG
Python | Reverse each word in a sentence

Using stringstream in C++ :

#include<bits/stdc++.h>
using namespace std;
  
void printWords(string str)
{
    // word variable to store word
    string word;
  
    // making a string stream
    stringstream iss(str);
  
    // Read and print each word.
    while (iss >> word){
        reverse(word.begin(),word.end());
        cout<<word<<" ";
    }
}
  
// Driver code
int main()
{
    string s = "GeeksforGeeks is good to learn";
    printWords(s);
    return 0;
}
// This code is contributed by Nikhil Rawat
*/
