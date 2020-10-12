#include <stdio.h>
#include <stdlib.h>


struct Stack{
	int top;
	unsigned size;
	int *array;
	
};

struct Stack *CreateStack(unsigned size){
	
	struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
	s->size = size;
	s->array = (int*)malloc(sizeof(int) * s->size);
	s->top = -1;
	return s;	
}
int isFull(struct Stack *s){	
	return (s->top == s->size - 1);
}

int isEmpty(struct Stack *s){
	return (s->top == -1);
}

void push(struct Stack* s){
	int item;
	printf("\nEnter element to push into the stack : ");
	scanf("%d",&item);
	if (isFull(s)){
		printf("\nStack is Full!\n");
		return ;
	}
	s->array[++s->top] = item;
	printf("\n%d pushed into the stack\n",item);
}

int pop(struct Stack* s){
	if (isEmpty(s)){
		printf("\nStack is Empty!\n");
		return s->top;
	}
	return s->array[s->top--];
}

void peek(struct Stack* s){
	if (isEmpty(s)){
		printf("\nStack is Empty!\n");
		return ;
	}
	printf("\nThe top of Stack = %d\n",s->array[s->top]);
}
// function to reverse a stack
void reverse(struct Stack*s){
	if (isEmpty(s)){
		printf("\nStack is Empty!\n");
		return ;
	}
	
	
}


void display(struct Stack* s){
	if (isEmpty(s)){
		printf("\nStack is Empty!\n");
		return ;
	}
	printf("\nSTACK : \n");
	int i = s->top;
	while(i>=0  && s->array[i]){
		printf("%d\n",s->array[i--]);
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
	    printf("\t\t\t5. Quit \n");
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
	        	printf("Thank you!\n");
	        	exit(0);
	        default:
	        	printf("\a\nWrong choice! \n\n");
	    } 
	}	
		
	return 0;
}
