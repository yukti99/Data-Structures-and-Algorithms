#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
#define N 100

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
	
	
void push(struct Stack *stack,int item){
	
	
	if (isFull(stack))
		return ;
	stack->array[++stack->top] = item;
	//printf("\nItem pushed to stack - %d\n",item);	
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

void middle(struct Stack*s){

	int m = s->top +1;
	if (m %2 == 0)
		printf("\nMiddle elements of the Stack are : %d  %d\n",s->array[m/2-1],s->array[m/2])	;
	else
		printf("\nMiddle element of the Stack is : %d\n",s->array[m/2]);		
	
}
struct Stack* reverse(struct Stack *s){
	
	struct Stack* t = s;
	if (isEmpty(s)){
		printf("\nStack is Empty!\n");
		return s;
	}
	struct Stack *R = CreateStack(N);
	
	while(!isEmpty(t)){
		push(R,pop(t));
	}
	return R;
	
}
void  display(struct Stack *stack){
	
	printf("\nStack :\n");
	if (isEmpty(stack)){
		printf("\nStack is Empty!\n");
		return ;
	}
	int c = stack->top ;
	for(int i=stack->top;i>=0;i--){
		printf("%d\n",stack->array[i]);
		
	}/* OR
	while(c >= 0 && stack->array[c]){
		printf("%d\n",stack->array[c--]);
	}*/
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
	    printf("\t\t\t6. Reverse the Stack \n");
	    printf("\t\t\t7. Quit \n");
	    printf("\t\t\tEnter your choice : ");
	    scanf("%d", &choice);
	    printf("\n");
	    switch (choice)
	    {
	        case 1:
	        	int item;
				printf("\nEnter item to push into the stack : ");
				scanf("%d",&item);
	        	push(s,item);
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
				s = reverse(s);
				printf("\nAfter Reversing : \n");
				display(s);
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
