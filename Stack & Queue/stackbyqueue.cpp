#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define N 100

struct Queue{
	
	int front,rear,size;
	int cap;
	int *a;
};

struct Queue* Create(int cap){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->cap = cap;
	q->size = q->front=0;
	q->front = 0;
	q->rear = q->cap -1;
	q->a = (int*)malloc(sizeof(int)*cap) ;
	return q;
}

int isEmpty(struct Queue*q){
	return (q->size == 0);
}
int isFull(struct Queue* q){
	return (q->size == q->cap);
}
void enqueue(struct Queue* q,int item){
	
	if(isFull(q)){
		printf("\nFULL!!\n");
		return ;
	}
	q->rear = (q->rear+1)% q->cap;
	q->a[q->rear] = item;
	q->size++;
//	printf("%d enqueued to queue\n", item);
	
}
int dequeue(struct Queue* q){
	if (isEmpty(q)){
		printf("\nEMPTY!!\n");
		return INT_MIN;		
	}
	int x = q->a[q->front];
	q->front = (q->front+1) % q->cap ;
	q->size--; 
	return x;
}
void displayq(struct Queue *q){
	
	
	if (isEmpty(q)){
		printf("\nEmpty\n");
		return ;
	}
	for(int i=q->rear; i>= q->front;i--){
		
		printf("\t%d\n",q->a[i]); 
	}
	printf("\n");
}
void reverseq(struct Queue* q){

	if (isEmpty(q))
		return ;
	int data = dequeue(q);
	reverseq(q);
	enqueue(q,data);
}

// STACK IMPLEMENTATION USING QUEUE

struct Stack{
	struct Queue *q;
	int top;
	int size;
};

struct  Stack* CreateStack(int size){
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
	s->q = Create(N);
	s->top = -1;
	s->size = 0;	
}

void push(struct Stack *s,int item){

	enqueue(s->q,item);
	s->size++;

	printf("\n%d pushed to stack\n",item);
}
int pop(struct Stack*s){
	if (isEmpty(s->q))
		return INT_MIN;
	return s->q->a[s->q->rear--];
		/*
	reverseq(s->q);	
	int x = dequeue(s->q);
	reverseq(s->q);
	return x;*/
}

void display(struct Stack*s){
	printf("\nSTACK: \n");
	displayq(s->q);

}
int main(){
	struct Stack* s = CreateStack(N);
	push(s,1);push(s,2);push(s,3);push(s,4);push(s,8);
	display(s);
	printf("\n%d popped from Stack\n",pop(s));
	display(s);
	printf("\n%d popped from Stack\n",pop(s));
	display(s);
	push(s,9);
	display(s);
	
	
	return 0;
}
