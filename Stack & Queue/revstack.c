#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Stack{
	
	int top;
	int size;
	char *c ;	
};

struct Stack *CreateStack(int size){
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
	
	
void push(struct Stack *stack,char item){	
	if (isFull(stack))
		return ;
	stack->c[++stack->top] = item;
	
}

int pop(struct Stack *stack){
	if (isEmpty(stack)){
		printf("Stack is Empty\n");
		return stack->top;
	}	
	return stack->c[stack->top--];
}



void reverse_words(char *exp){	

	printf("\nThe Reversed words are: \n");
	struct Stack* s = CreateStack(100);
	int i;
	for( i=0;i<strlen(exp);i++){
		if (exp[i] != ' '){
			push(s,exp[i]);
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
	// for last word, if there is no space at the end of the string
	while(!isEmpty(s)){
		char ch = pop(s);
		printf("%c",ch);
	}
	printf("\n");
}


int main(){
	
	char item;
	int i;
	char c[100];
	printf("\nEnter the string of words : ");
	fgets (c, 100, stdin);
	printf("\nGiven String : %s\n",c);
	reverse_words(c);	
		
	return 0;
}



