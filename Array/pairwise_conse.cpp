#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
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
		//printf("Stack is Empty\n");
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
bool is_pair(struct Stack* s){
	bool result = true;
	struct Stack *s2 = CreateStack(N);
	while(!isEmpty(s)){
		push(s2,pop(s));
	}
	while(s2->top > 0){
		int x = pop(s2);
		int y = pop(s2);
		if (abs(x-y) != 1){ 
			result = false;		
		}
		push(s,x);
		push(s,y);
	}
	if (s2->top == 0)
		push(s,pop(s2));
	return result;
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
		
	}
	printf("\n");
}


int main(){
	
	struct Stack *s = CreateStack(100);
    push(s,6);push(s,5);push(s,-3);push(s,-2);push(s,0);push(s,1);
	display(s);
	if (is_pair(s))
		printf("\nYES\n");
	else
		printf("\nNO\n");
		
	return 0;
}
