/* Implementation of Queue using two Stacks
NOTE : Stacks implemented by array */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// STACK DEFINITION
struct Stack{	
	unsigned capacity;
	int top;
	int *a ;
};


struct Stack* CreateStack(unsigned cap){
	
	struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
	s->capacity = cap;
	s->top = -1;
	s->a = (int *)malloc(sizeof(int)*s->capacity);
	return s;
}
struct Stack *s1 = CreateStack(100);
struct Stack *s2 = CreateStack(100);

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
int pop(struct Stack *s){
	
	if (isEmpty(s)){
		printf("\nStack is Empty!\n");
		return INT_MIN;
	}
	int popped = s->a[s->top--];
	return popped;	
}

// QUEUE USING STACK DEFINED ABOVE

void Enqueue(int item){	
	push(s1,item);
	printf("\nEnqueued element - %d\n",item);
}

int Dequeue(){
	
	if (isEmpty(s1) && isEmpty(s2)){
		printf("\nERROR!!\n");
		return INT_MIN;
	}
	if (isEmpty(s2)){
		while(!isEmpty(s1)){
			push(s2,pop(s1));
		}
	}
	return pop(s2);	
}

int main(){
	

	Enqueue(1);Enqueue(2);Enqueue(3);Enqueue(4);Enqueue(5);	
	printf("\nThe Element dequeued is- %d\n",Dequeue());
	printf("\nThe Element dequeued is- %d\n",Dequeue());
	
	
	return 0;
}
