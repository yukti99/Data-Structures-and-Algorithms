#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;


struct Stack{
	
	int top;
	unsigned size;
	int *array;
	
};


struct Stack *CreateStack(unsigned size){
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->size = size;
	stack->array = (int *)malloc(stack->size *  sizeof(int));
	return stack;
}

int isFull(struct Stack *stack){
	return (stack->top == stack->size -1) ;
}
	

int isEmpty(struct Stack *stack){
	return (stack->top == -1);
}
	
	
void push(struct Stack *stack){
	int item;
	printf("\nEnter item to push into the stack : ");
	scanf("%d",&item);
	
	if (isFull(stack))
		return ;
	stack->array[++stack->top] = item;
	printf("\nItem pushed to stack - %d\n",item);	
}

void peek(struct Stack *stack){
	
	if (isEmpty(stack))
		printf("The Stack is Empty!\n");
	printf("\nThe top item of Stack is : %d\n",stack->array[stack->top]);
}
int pop(struct Stack *stack){
	if (isEmpty(stack)){
		printf("Stack is Empty\n");
		return stack->top;
	}	
	return stack->array[stack->top--];
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
