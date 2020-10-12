#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


struct Stack{	
	unsigned capacity;
	int top;
	char *a ;
};


struct Stack* CreateStack(unsigned cap){
	
	struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
	s->capacity = cap;
	s->top = -1;
	s->a = (char*)malloc(sizeof(char)*s->capacity);
	return s;
}

int isEmpty(struct Stack *s){
	return (s->top == -1);
}
int isFull(struct Stack *s){
	return (s->top == s->capacity);
}

void push(struct Stack* s, int item){
	
	if (isFull(s)){
		printf("\nOverflow Condition!\n");
		return ;
	}
	s->a[++s->top] = item;	
}

char peek(struct Stack *s){
	
	if (isEmpty(s))
		return '$';
	
	return s->a[s->top] ;
}
char pop(struct Stack *s){
	
	if (isEmpty(s))		
		return '$';
	
	return s->a[s->top--];	
}
void display(struct Stack *s){
	
	if (isEmpty(s)){
		printf("\nUnderflow Condition!\n");
		return ;
	}
	printf("\nSTACK : \n");
	for(int i=s->top;i>=0;i--){
		printf("\t%c\n",s->a[i]);
	}
	printf("\n");
}
int IsOperand(char ch){
	return ( ( ch>='a'&& ch<='z') || (ch>='A' && ch<='Z' ) );
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
void InfixToPostfix(char *exp){
	
	int i,k=0;
	int l = strlen(exp);
	char postfix[l];
	struct Stack *stack = CreateStack(l);
	for(i=0 ; exp[i] ;i++){
		
		printf("TOKEN : %c\n",exp[i]);
		// operand found		
		if (IsOperand(exp[i])){
			postfix[k++] = exp[i];
			printf("\n%s\n",postfix);			
		}
		else if (exp[i] == '('){
			push(stack,exp[i]);
			display(stack);
		}
		
		else if (exp[i] == ')'){
			while(!isEmpty(stack) && peek(stack)!= '('){
				postfix[k++]  = pop(stack);
				printf("\n%s\n",postfix);
			}
			if (!isEmpty(stack)){
				printf("INVALID EXPRESSION");
				return ;
			}
                  
            else
            	pop(stack);
		}
		// operator found
		else{
			while(!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack))){		
				postfix[k++] = pop(stack);
				printf("\n%s\n",postfix);
			}
			push(stack,exp[i]);	
			display(stack);			
		}			
	}
	// pop all the operators from the stack
    while (!isEmpty(stack)){
    	int p =  pop(stack);
    	if (p == '('){
    		printf("INVALID EXPRESSION");
			return ;
		}    	
    	postfix[k++] = p ;
    		 
	}       
    
	postfix[k++]  = '\0';
	printf("\nPOSTFIX EXPRESSION : %s\n",postfix);
}

int main(){
	
	char exp[100];	
	printf("\nEnter the INFIX Expression : ");
	gets(exp);
	InfixToPostfix(exp);	
	return 0;
}
