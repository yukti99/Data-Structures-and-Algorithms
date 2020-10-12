/* Array implementation of Queue */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Queue{
	
	int front,rear,size;
	unsigned capacity;
	int *array;
};

struct Queue *CreateQueue(unsigned capacity){
	
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->capacity = capacity;
	q->size = 0;
	q->front = q->rear = -1;       // initialize both rear and front as -1
	q->array = (int*)malloc(sizeof(q->capacity * sizeof(int)));
	return q;
}

int isFullq(struct Queue *q){
	return (q->size == q->capacity);   //  or q->rear = q->size-1
}

int isEmptyq(struct Queue *q){
	return (q->size == 0);    // q->rear = -1
}
void enqueue(struct Queue *q,int item){
	
	if (isFullq(q)){
		printf("\nQueue Overflow !\n");
		return ;
	}
	if (q->front == -1)
		q->front = 0;      // when first element is added
	q->rear++ ;
	q->array[q->rear] = item ;
	q->size++;
	printf("\nEnqueued to Queue : %d\n",item);	
	
}

int Dequeue(struct Queue *q){
	
	if (isEmptyq(q)){
		printf("Queue Underflow !\n");
		return INT_MIN;
	}
	int x = q->array[q->front];
	q->front++ ;	
	q->size-- ;
	if (q->front > q->rear)       // means the queue has become empty
		q->front = q->rear = -1;
	return x;
}



void displayq(struct Queue *q){
	
	
	if (isEmptyq(q)){
		printf("The queue is Empty!\n");
		return ;
	}
	printf("\nQUEUE : \n");	
	for(int i=q->front; i<= q->rear ;i++){
		
		printf("\t%d\n",q->array[i] ); 
	}
	printf("\n");
}

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

int isFulls(struct Stack *stack){
	return (stack->top == stack->size -1) ;
}
	

int isEmptys(struct Stack *stack){
	return (stack->top == -1);
}
	
	
void push(struct Stack *stack,int item){
	
	
	if (isFulls(stack))
		return ;
	stack->array[++stack->top] = item;
	printf("\nItem pushed to stack - %d\n",item);	
}


int pop(struct Stack *stack){
	if (isEmptys(stack)){
		printf("Stack is Empty\n");
		return stack->top;
	}	
	return stack->array[stack->top--];
}

struct Queue* reverseq(struct Queue*q){
	
	struct Stack* s = CreateStack(100);
	while(!isEmptyq(q)){
		push(s,Dequeue(q));
	}
	while(!isEmptys(s)){
		enqueue(q,pop(s));
	}
	return q;
}




int main(){
	struct Queue *q = CreateQueue(100);
	enqueue(q,1);enqueue(q,2);enqueue(q,3);enqueue(q,4);enqueue(q,5);
	displayq(q);
	struct Queue* R = reverseq(q);
	printf("\nAfter Reversing : \n");
	displayq(R);
	return 0;
}
