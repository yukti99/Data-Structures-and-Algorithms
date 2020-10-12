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
	q->a= (int*)malloc(sizeof(int)*size);
	return q;
	
}
int isEmpty(struct Queue *q){
	return (q->rear == -1);
}

int isFull(struct  Queue *q){
	return (q->rear == q->size-1);	
}

int front(struct Queue *q){
	if (isEmpty(q))
		return INT_MIN;
	return  q->a[q->front];

}

void Enqueue(struct Queue *q,int n){
	if (isFull(q))
		return ;
	q->a[++q->rear] = n;
	if (q->front == -1)
		q->front = 0;
}

int Dequeue(struct Queue *q){
	if(isEmpty(q))
		return INT_MIN;
	int popped = q->a[q->front++];
	if (q->front>q->rear)
		q->front = q->rear = -1;
	return popped;
}
void displayQ(struct Queue *q) {
	
    int i = q->front;
    if(isEmpty(q))
		printf("\nQueue is empty\n");    
	else{
        for(i = q->front; i < q->rear + 1; i++) {
                printf("%d ", q->a[i]);
        }
    }    
}

