#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Queue{
	int size;
	int front,rear;
	int *a;
};

struct Queue* CreateQ(int size){
	
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->size = size;
	q->front = q->rear = -1;
	q->a = (int*)malloc(sizeof(int)*size);
	return q;
	
}
int isEmpty(struct Queue *q){
	return (q->rear == -1);
}

int isFull(struct  Queue *q){
	return (q->rear == q->size-1);	
}

void peek(struct Queue *q){
	if (isEmpty(q))
		return ;
	printf("%d ",q->a[q->front]);
}

void push(struct Queue *q,int item){
	if (isFull(q))
		return ;
	q->a[++q->rear] = item;
	if (q->front == -1)
		q->front = 0;
}

int pop(struct Queue *q){
	if(isEmpty(q))
		return INT_MIN;
	int popped = q->a[q->front++];
	if (q->front>q->rear)
		q->front = q->rear = -1;
	return popped;
}
void displayQ(struct Queue *q){
	
	if (isEmpty(q))
		return ;
	printf("\nQUEUE : \n");	
	int i;
	for(i = q->front; i <= q->rear ;i++)		
		printf("\t%d\n",q->a[i] ); 
	printf("\n");
} 

