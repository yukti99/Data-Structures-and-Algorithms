
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 100


// STACK DEFINITION
struct Stack{	
	int size;
	int top;
	int *a ;
};


struct Stack* CreateStack(int size){
	
	struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
	s->size = size ;
	s->top = -1;
	s->a = (int *)malloc(sizeof(int)*s->size);
	return s;
}

int isEmpty(struct Stack *s){
	return (s->top == -1);
}
int isFull(struct Stack *s){
	return (s->top == s->size);
}

void push(struct Stack* s, int item){
	
	if (isFull(s)){
		printf("\nOverflow Condition!\n");
		return ;
	}
	s->a[++s->top] = item;	
}
int pop(struct Stack *s){
	
	if (isEmpty(s)){
		printf("\nStack is Empty!\n");
		return INT_MIN;
	}
	int popped = s->a[s->top--];
	return popped;	
}

void  display(struct Stack *stack){
	
	printf("\nQUEUE :\n");
	if (isEmpty(stack)){
		printf("\nStack is Empty!\n");
		return ;
	}
	int c = 0;
	while(c <= stack->top && stack->a[c]){
		printf("%d\n",stack->a[c++]);
	}
	printf("\n");
}


// QUEUE USING STACK DEFINED ABOVE

void Enqueue(struct Stack *s1,int item){	
	push(s1,item);
	printf("\nEnqueued element - %d\n",item);
	
		
}

void Dequeue(struct Stack *s1,struct Stack *s2){	
	
	
	if (isEmpty(s1) && isEmpty(s2)){
		printf("\nERROR!!\n");
		return ;
	}
	if (isEmpty(s2)){
  		// pushing elements to second stack
		while(!isEmpty(s1)){
			push(s2,pop(s1));
		}
	}
	// now the top of the stack-2 will be the last element of stack-1
	printf("\nThe Element dequeued is- %d\n",pop(s2));
	while ( !isEmpty(s2) ){
		push(s1,pop(s2));		
	}
	printf("\nAfter Dequeue operation : \n");
	display(s1);
}

int main(){
	

	struct Stack *s1 = CreateStack(N);
	struct Stack *s2 = CreateStack(N);
	int item,choice;	
	while (1){
	   printf("\nEnter what you want to do");
	   printf("\n1.Enqueue \n");
	   printf("\n2.Dequeue \n");
	   printf("\n3.Display Queue \n");
	   printf("\n4.Quit \n\n");
	   scanf("%d",&choice);
	   printf("\n");
	   switch (choice){
	    
	        case 1:
			printf("Enter the element you want to enqueue : ");
			scanf("%d",&item);
			Enqueue(s1,item);
			break;
		case 2:
			Dequeue(s1,s2);
			break;
		case 3:
			display(s1);
			break;
		case 4:
			printf("\nThank You\n");
			exit(0);
		default:
			printf("\nWrong choice!!\n");
	    } 
	}	
	
	return 0;
}
